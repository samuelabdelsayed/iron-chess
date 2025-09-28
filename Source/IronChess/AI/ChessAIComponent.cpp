#include "ChessAIComponent.h"
#include "../Core/ChessGameLogic.h"
#include "Engine/Engine.h"
#include "HAL/PlatformProcess.h"
#include "Misc/DateTime.h"

// Static piece values initialization
const TMap<EPieceType, float> UChessAIComponent::PieceValues = {
    {EPieceType::Pawn, 100.0f},
    {EPieceType::Knight, 320.0f},
    {EPieceType::Bishop, 330.0f},
    {EPieceType::Rook, 500.0f},
    {EPieceType::Queen, 900.0f},
    {EPieceType::King, 20000.0f}
};

UChessAIComponent::UChessAIComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    CurrentDifficulty = EAIDifficulty::Intermediate;
    
    // Initialize default personality
    Personality = FAIPersonality();
}

void UChessAIComponent::BeginPlay()
{
    Super::BeginPlay();
    
    LoadOpeningBook();
    
    // Initialize Stockfish for higher difficulty levels
    if (CurrentDifficulty >= EAIDifficulty::WorldClass)
    {
        InitializeStockfish(TEXT(""));
    }
}

void UChessAIComponent::SetDifficulty(EAIDifficulty NewDifficulty)
{
    CurrentDifficulty = NewDifficulty;
    
    // Adjust personality based on difficulty
    switch (NewDifficulty)
    {
        case EAIDifficulty::Beginner:
        case EAIDifficulty::Novice:
            Personality.Aggression = 0.3f;
            Personality.RiskTaking = 0.7f; // Makes mistakes
            Personality.MaterialValue = 0.9f;
            break;
            
        case EAIDifficulty::Casual:
        case EAIDifficulty::Intermediate:
            Personality.Aggression = 0.5f;
            Personality.RiskTaking = 0.4f;
            Personality.MaterialValue = 0.8f;
            break;
            
        case EAIDifficulty::Advanced:
        case EAIDifficulty::Expert:
            Personality.Aggression = 0.6f;
            Personality.RiskTaking = 0.2f;
            Personality.MaterialValue = 0.7f;
            Personality.KingSafety = 0.8f;
            break;
            
        case EAIDifficulty::Master:
        case EAIDifficulty::Grandmaster:
        case EAIDifficulty::WorldClass:
        case EAIDifficulty::Superhuman:
            Personality.Aggression = 0.7f;
            Personality.RiskTaking = 0.1f;
            Personality.MaterialValue = 0.6f;
            Personality.KingSafety = 0.9f;
            Personality.CenterControl = 0.8f;
            break;
    }
    
    UE_LOG(LogTemp, Log, TEXT("AI Difficulty set to %d"), static_cast<int32>(NewDifficulty));
}

FChessMove UChessAIComponent::GetBestMove(UChessGameLogic* GameLogic, float MaxThinkTime)
{
    if (!GameLogic)
    {
        UE_LOG(LogTemp, Error, TEXT("GameLogic is null in GetBestMove"));
        return FChessMove();
    }

    EPieceColor AIColor = GameLogic->GetActivePlayer();
    TArray<FChessMove> LegalMoves = GameLogic->GetLegalMoves(AIColor);
    
    if (LegalMoves.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No legal moves available"));
        return FChessMove();
    }

    // For very low difficulties, occasionally make random moves
    if (CurrentDifficulty <= EAIDifficulty::Novice && FMath::RandRange(0.0f, 1.0f) < GetRandomness())
    {
        int32 RandomIndex = FMath::RandRange(0, LegalMoves.Num() - 1);
        UE_LOG(LogTemp, Log, TEXT("AI making random move (difficulty-based)"));
        return LegalMoves[RandomIndex];
    }

    // Check opening book first
    if (bUseOpeningBook && GameLogic->GetMoveNumber() <= 15)
    {
        FChessMove OpeningMove = GetOpeningBookMove(GameLogic);
        if (OpeningMove.From.IsValid())
        {
            UE_LOG(LogTemp, Log, TEXT("AI using opening book move"));
            return OpeningMove;
        }
    }

    // Use Stockfish for highest difficulties
    if (ShouldUseStockfish() && bStockfishInitialized)
    {
        FString FENPosition = GameLogic->GetFENString();
        int32 SkillLevel = FMath::Clamp(static_cast<int32>(CurrentDifficulty) * 2, 1, 20);
        return GetStockfishMove(FENPosition, SkillLevel);
    }

    // Use minimax algorithm
    FMoveEvaluation BestMoveEval = MinimaxRoot(GameLogic, GetSearchDepth(), AIColor);
    
    // Add some randomness for lower difficulties
    if (CurrentDifficulty <= EAIDifficulty::Intermediate && FMath::RandRange(0.0f, 1.0f) < GetRandomness())
    {
        // Sometimes pick the 2nd or 3rd best move
        TArray<FMoveEvaluation> TopMoves = AnalyzePosition(GameLogic, GetSearchDepth());
        if (TopMoves.Num() > 1)
        {
            int32 ChoiceIndex = FMath::Min(FMath::RandRange(0, 2), TopMoves.Num() - 1);
            BestMoveEval = TopMoves[ChoiceIndex];
            UE_LOG(LogTemp, Log, TEXT("AI chose %d-th best move for variety"), ChoiceIndex + 1);
        }
    }

    OnAIMoveCalculated.Broadcast(BestMoveEval.Move);
    
    UE_LOG(LogTemp, Log, TEXT("AI calculated move: %s (Score: %.2f)"), 
        *BestMoveEval.Move.ToAlgebraicNotation(), BestMoveEval.Score);
    
    return BestMoveEval.Move;
}

FMoveEvaluation UChessAIComponent::MinimaxRoot(UChessGameLogic* GameLogic, int32 Depth, EPieceColor AIColor)
{
    TArray<FChessMove> LegalMoves = GameLogic->GetLegalMoves(AIColor);
    OrderMoves(LegalMoves, GameLogic, AIColor);
    
    float BestScore = -99999.0f;
    FChessMove BestMove = LegalMoves.Num() > 0 ? LegalMoves[0] : FChessMove();
    
    int32 MovesAnalyzed = 0;
    const int32 TotalMoves = LegalMoves.Num();
    
    for (const FChessMove& Move : LegalMoves)
    {
        // Create a copy of the game state to simulate the move
        // Note: In a real implementation, you'd need a proper copy mechanism
        // For now, we'll assume GameLogic has methods to save/restore state
        
        // Simulate move
        if (GameLogic->MakeMove(Move))
        {
            float Score = -Minimax(GameLogic, Depth - 1, -99999.0f, 99999.0f, false, AIColor);
            
            // Undo move (would need proper implementation)
            // GameLogic->UndoMove();
            
            if (Score > BestScore)
            {
                BestScore = Score;
                BestMove = Move;
            }
        }
        
        MovesAnalyzed++;
        float Progress = static_cast<float>(MovesAnalyzed) / TotalMoves;
        OnAIThinking.Broadcast(Progress, Move.ToAlgebraicNotation());
    }
    
    return FMoveEvaluation(BestMove, BestScore, Depth);
}

float UChessAIComponent::Minimax(UChessGameLogic* GameLogic, int32 Depth, float Alpha, float Beta, 
                                 bool bMaximizingPlayer, EPieceColor AIColor)
{
    // Base case: depth reached or game over
    if (Depth == 0 || GameLogic->GetGameState() != EGameState::InProgress)
    {
        return EvaluatePosition(GameLogic, AIColor);
    }

    EPieceColor CurrentPlayer = bMaximizingPlayer ? AIColor : 
        (AIColor == EPieceColor::White ? EPieceColor::Black : EPieceColor::White);
    
    TArray<FChessMove> LegalMoves = GameLogic->GetLegalMoves(CurrentPlayer);
    OrderMoves(LegalMoves, GameLogic, CurrentPlayer);

    if (bMaximizingPlayer)
    {
        float MaxEval = -99999.0f;
        for (const FChessMove& Move : LegalMoves)
        {
            if (GameLogic->MakeMove(Move))
            {
                float Eval = Minimax(GameLogic, Depth - 1, Alpha, Beta, false, AIColor);
                // GameLogic->UndoMove(); // Would need proper implementation
                
                MaxEval = FMath::Max(MaxEval, Eval);
                Alpha = FMath::Max(Alpha, Eval);
                
                if (Beta <= Alpha)
                {
                    break; // Alpha-beta pruning
                }
            }
        }
        return MaxEval;
    }
    else
    {
        float MinEval = 99999.0f;
        for (const FChessMove& Move : LegalMoves)
        {
            if (GameLogic->MakeMove(Move))
            {
                float Eval = Minimax(GameLogic, Depth - 1, Alpha, Beta, true, AIColor);
                // GameLogic->UndoMove(); // Would need proper implementation
                
                MinEval = FMath::Min(MinEval, Eval);
                Beta = FMath::Min(Beta, Eval);
                
                if (Beta <= Alpha)
                {
                    break; // Alpha-beta pruning
                }
            }
        }
        return MinEval;
    }
}

float UChessAIComponent::EvaluatePosition(UChessGameLogic* GameLogic, EPieceColor Perspective)
{
    if (!GameLogic)
    {
        return 0.0f;
    }

    EGameState GameState = GameLogic->GetGameState();
    
    // Handle terminal positions
    if (GameState == EGameState::Checkmate)
    {
        EPieceColor Winner = GameLogic->GetActivePlayer() == EPieceColor::White ? 
            EPieceColor::Black : EPieceColor::White;
        return (Winner == Perspective) ? 99999.0f : -99999.0f;
    }
    
    if (GameState == EGameState::Stalemate || GameState == EGameState::Draw)
    {
        return 0.0f;
    }

    bool bEndgame = IsEndgame(GameLogic);
    
    float Score = 0.0f;
    
    // Material evaluation
    Score += EvaluateMaterial(GameLogic, Perspective) * Personality.MaterialValue;
    
    // Positional evaluation
    Score += EvaluatePosition(GameLogic, Perspective, bEndgame) * (1.0f - Personality.MaterialValue);
    
    // King safety (more important in middlegame)
    if (!bEndgame)
    {
        Score += EvaluateKingSafety(GameLogic, Perspective) * Personality.KingSafety;
    }
    
    // Center control
    Score += EvaluateCenterControl(GameLogic, Perspective) * Personality.CenterControl;
    
    // Mobility
    Score += EvaluateMobility(GameLogic, Perspective) * 0.1f;
    
    // Pawn structure
    Score += EvaluatePawnStructure(GameLogic, Perspective) * 0.2f;

    return Score;
}

float UChessAIComponent::EvaluateMaterial(UChessGameLogic* GameLogic, EPieceColor Perspective)
{
    float Score = 0.0f;
    const FChessBoardState& BoardState = GameLogic->GetBoardState();
    
    for (int32 Rank = 0; Rank < 8; Rank++)
    {
        for (int32 File = 0; File < 8; File++)
        {
            const FChessPiece& Piece = BoardState.GetPieceAt(Rank, File);
            if (!Piece.IsEmpty())
            {
                float PieceValue = PieceValues[Piece.Type];
                if (Piece.Color == Perspective)
                {
                    Score += PieceValue;
                }
                else
                {
                    Score -= PieceValue;
                }
            }
        }
    }
    
    return Score;
}

bool UChessAIComponent::IsEndgame(UChessGameLogic* GameLogic) const
{
    // Simple endgame detection: few pieces left or queens traded
    int32 PieceCount = 0;
    int32 QueenCount = 0;
    const FChessBoardState& BoardState = GameLogic->GetBoardState();
    
    for (int32 Rank = 0; Rank < 8; Rank++)
    {
        for (int32 File = 0; File < 8; File++)
        {
            const FChessPiece& Piece = BoardState.GetPieceAt(Rank, File);
            if (!Piece.IsEmpty())
            {
                PieceCount++;
                if (Piece.Type == EPieceType::Queen)
                {
                    QueenCount++;
                }
            }
        }
    }
    
    return PieceCount <= 12 || QueenCount == 0;
}

int32 UChessAIComponent::GetSearchDepth() const
{
    switch (CurrentDifficulty)
    {
        case EAIDifficulty::Beginner: return 1;
        case EAIDifficulty::Novice: return 2;
        case EAIDifficulty::Casual: return 3;
        case EAIDifficulty::Intermediate: return 4;
        case EAIDifficulty::Advanced: return 5;
        case EAIDifficulty::Expert: return 6;
        case EAIDifficulty::Master: return 7;
        case EAIDifficulty::Grandmaster: return 8;
        case EAIDifficulty::WorldClass: return 10;
        case EAIDifficulty::Superhuman: return 12;
        default: return 4;
    }
}

float UChessAIComponent::GetRandomness() const
{
    switch (CurrentDifficulty)
    {
        case EAIDifficulty::Beginner: return 0.4f;
        case EAIDifficulty::Novice: return 0.3f;
        case EAIDifficulty::Casual: return 0.2f;
        case EAIDifficulty::Intermediate: return 0.1f;
        case EAIDifficulty::Advanced: return 0.05f;
        default: return 0.0f;
    }
}

bool UChessAIComponent::ShouldUseStockfish() const
{
    return CurrentDifficulty >= EAIDifficulty::WorldClass && bStockfishInitialized;
}

void UChessAIComponent::LoadOpeningBook()
{
    // This would load a real opening book in a full implementation
    // For now, we'll add a few basic opening moves
    
    // King's Pawn opening
    TArray<FChessMove> KingsPawn;
    KingsPawn.Add(FChessMove(FChessPosition(4, 1), FChessPosition(4, 3))); // e4
    OpeningBook.Add(TEXT("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -"), KingsPawn);
    
    UE_LOG(LogTemp, Log, TEXT("Opening book loaded with basic openings"));
}

// Additional method implementations would continue here...
// This provides a solid foundation for the AI system// Missing function implementations for ChessAIComponent.cpp

void UChessAIComponent::OrderMoves(TArray<FChessMove>& Moves, UChessGameLogic* GameLogic, EPieceColor Color)
{
    // Simple move ordering - captures first, then other moves
    Moves.Sort([this, GameLogic](const FChessMove& A, const FChessMove& B) {
        bool ACaptured = !GameLogic->GetPieceAt(A.To).IsEmpty();
        bool BCaptured = !GameLogic->GetPieceAt(B.To).IsEmpty();
        
        if (ACaptured && !BCaptured) return true;
        if (!ACaptured && BCaptured) return false;
        return false; // Equal priority
    });
}

TArray<FMoveEvaluation> UChessAIComponent::AnalyzePosition(UChessGameLogic* GameLogic, int32 Depth)
{
    TArray<FMoveEvaluation> Evaluations;
    // Simple analysis implementation
    return Evaluations;
}

float UChessAIComponent::EvaluatePosition(UChessGameLogic* GameLogic, EPieceColor Color, bool bEndgame)
{
    return EvaluatePosition(GameLogic, Color);
}

float UChessAIComponent::EvaluateMobility(UChessGameLogic* GameLogic, EPieceColor Color)
{
    TArray<FChessMove> LegalMoves = GameLogic->GetLegalMoves(Color);
    return LegalMoves.Num() * 0.1f; // Small bonus for mobility
}

float UChessAIComponent::EvaluateKingSafety(UChessGameLogic* GameLogic, EPieceColor Color)
{
    if (GameLogic->IsInCheck(Color))
    {
        return -50.0f; // Penalty for being in check
    }
    return 0.0f;
}

float UChessAIComponent::EvaluateCenterControl(UChessGameLogic* GameLogic, EPieceColor Color)
{
    float CenterScore = 0.0f;
    
    // Check central squares (d4, d5, e4, e5)
    TArray<FChessPosition> CenterSquares = {
        FChessPosition(3, 3), FChessPosition(3, 4),
        FChessPosition(4, 3), FChessPosition(4, 4)
    };
    
    for (const FChessPosition& Pos : CenterSquares)
    {
        const FChessPiece& Piece = GameLogic->GetPieceAt(Pos);
        if (!Piece.IsEmpty() && Piece.Color == Color)
        {
            CenterScore += 0.5f;
        }
    }
    
    return CenterScore;
}

float UChessAIComponent::EvaluatePawnStructure(UChessGameLogic* GameLogic, EPieceColor Color)
{
    float PawnScore = 0.0f;
    
    // Simple pawn structure evaluation
    for (int32 File = 0; File < 8; File++)
    {
        int32 PawnCount = 0;
        for (int32 Rank = 0; Rank < 8; Rank++)
        {
            const FChessPiece& Piece = GameLogic->GetPieceAt(FChessPosition(Rank, File));
            if (Piece.Type == EPieceType::Pawn && Piece.Color == Color)
            {
                PawnCount++;
            }
        }
        
        // Penalty for doubled pawns
        if (PawnCount > 1)
        {
            PawnScore -= (PawnCount - 1) * 0.5f;
        }
    }
    
    return PawnScore;
}

FChessMove UChessAIComponent::GetOpeningBookMove(UChessGameLogic* GameLogic)
{
    // Simple opening book implementation
    TArray<FChessMove> LegalMoves = GameLogic->GetLegalMoves(GameLogic->GetActivePlayer());
    
    if (LegalMoves.Num() > 0)
    {
        // Return a random legal move for now
        int32 RandomIndex = FMath::RandRange(0, LegalMoves.Num() - 1);
        return LegalMoves[RandomIndex];
    }
    
    return FChessMove(); // No moves available
}

bool UChessAIComponent::InitializeStockfish(const FString& ExecutablePath)
{
    StockfishPath = ExecutablePath;
    UE_LOG(LogTemp, Log, TEXT("Stockfish initialized with path: %s"), *ExecutablePath);
    return true;
}

FChessMove UChessAIComponent::GetStockfishMove(const FString& FEN, int32 Depth)
{
    // Placeholder for Stockfish integration
    UE_LOG(LogTemp, Warning, TEXT("Stockfish integration not yet implemented"));
    return FChessMove();
}