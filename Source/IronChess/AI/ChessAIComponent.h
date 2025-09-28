#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Core/ChessTypes.h"
#include "ChessAIComponent.generated.h"

class UChessGameLogic;

UENUM(BlueprintType)
enum class EAIDifficulty : uint8
{
    None = 0,          // Default/uninitialized value
    Beginner = 1,      // Random moves with basic patterns
    Novice = 2,        // Simple evaluation
    Casual = 3,        // Minimax depth 2-3
    Intermediate = 4,  // Minimax depth 3-4
    Advanced = 5,      // Opening book + basic tactics
    Expert = 6,        // Endgame knowledge + tactics
    Master = 7,        // Advanced evaluation + patterns
    Grandmaster = 8,   // Deep analysis + strategic play
    WorldClass = 9,    // Limited Stockfish strength
    Superhuman = 10    // Full Stockfish integration
};

USTRUCT(BlueprintType)
struct IRONCHESS_API FAIPersonality
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Personality")
    float Aggression = 0.5f; // 0.0 = Defensive, 1.0 = Aggressive

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Personality")
    float RiskTaking = 0.5f; // 0.0 = Safe, 1.0 = Risky

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Personality")
    float MaterialValue = 0.8f; // How much AI values material vs position

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Personality")
    float KingSafety = 0.7f; // Priority for king safety

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Personality")
    float CenterControl = 0.6f; // Priority for center control

    FAIPersonality()
    {
        Aggression = 0.5f;
        RiskTaking = 0.5f;
        MaterialValue = 0.8f;
        KingSafety = 0.7f;
        CenterControl = 0.6f;
    }
};

USTRUCT(BlueprintType)
struct IRONCHESS_API FMoveEvaluation
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FChessMove Move;

    UPROPERTY(BlueprintReadOnly)
    float Score = 0.0f;

    UPROPERTY(BlueprintReadOnly)
    int32 Depth = 0;

    UPROPERTY(BlueprintReadOnly)
    FString PrincipalVariation;

    FMoveEvaluation() : Score(0.0f), Depth(0) {}
    FMoveEvaluation(const FChessMove& InMove, float InScore, int32 InDepth = 0)
        : Move(InMove), Score(InScore), Depth(InDepth) {}
};

/**
 * AI Component for chess gameplay
 * Handles difficulty scaling, move calculation, and personality-based play styles
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType)
class IRONCHESS_API UChessAIComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UChessAIComponent();

    // AI Move Selection
    UFUNCTION(BlueprintCallable, Category = "Chess AI")
    FChessMove GetBestMove(UChessGameLogic* GameLogic, float MaxThinkTime = 5.0f);

    UFUNCTION(BlueprintCallable, Category = "Chess AI")
    TArray<FMoveEvaluation> AnalyzePosition(UChessGameLogic* GameLogic, int32 MaxDepth = 5);

    // Difficulty Management
    UFUNCTION(BlueprintCallable, Category = "Chess AI")
    void SetDifficulty(EAIDifficulty NewDifficulty);

    UFUNCTION(BlueprintPure, Category = "Chess AI")
    EAIDifficulty GetDifficulty() const { return CurrentDifficulty; }

    // AI Personality
    UFUNCTION(BlueprintCallable, Category = "Chess AI")
    void SetPersonality(const FAIPersonality& NewPersonality) { Personality = NewPersonality; }

    UFUNCTION(BlueprintPure, Category = "Chess AI")
    const FAIPersonality& GetPersonality() const { return Personality; }

    // Stockfish Integration
    UFUNCTION(BlueprintCallable, Category = "Chess AI")
    bool InitializeStockfish(const FString& ExecutablePath);

    UFUNCTION(BlueprintCallable, Category = "Chess AI")
    FChessMove GetStockfishMove(const FString& FENPosition, int32 SkillLevel = 20);

    // Analysis Functions
    UFUNCTION(BlueprintCallable, Category = "Chess AI")
    float EvaluatePosition(UChessGameLogic* GameLogic, EPieceColor Perspective);

    UFUNCTION(BlueprintCallable, Category = "Chess AI")
    bool IsEndgame(UChessGameLogic* GameLogic) const;

    // Events
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAIMoveCalculated, const FChessMove&, Move);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAIThinking, float, Progress, const FString&, CurrentLine);

    UPROPERTY(BlueprintAssignable)
    FOnAIMoveCalculated OnAIMoveCalculated;

    UPROPERTY(BlueprintAssignable)
    FOnAIThinking OnAIThinking;

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess AI")
    EAIDifficulty CurrentDifficulty = EAIDifficulty::Intermediate;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess AI")
    FAIPersonality Personality;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess AI")
    bool bUseOpeningBook = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess AI")
    bool bUseEndgameTablebase = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess AI")
    float DefaultThinkTime = 3.0f;

private:
    // Minimax algorithm implementation
    float Minimax(UChessGameLogic* GameLogic, int32 Depth, float Alpha, float Beta, 
                  bool bMaximizingPlayer, EPieceColor AIColor);

    FMoveEvaluation MinimaxRoot(UChessGameLogic* GameLogic, int32 Depth, EPieceColor AIColor);

    // Position evaluation components
    float EvaluateMaterial(UChessGameLogic* GameLogic, EPieceColor Perspective);
    float EvaluatePosition(UChessGameLogic* GameLogic, EPieceColor Perspective, bool bEndgame);
    float EvaluateKingSafety(UChessGameLogic* GameLogic, EPieceColor Perspective);
    float EvaluateCenterControl(UChessGameLogic* GameLogic, EPieceColor Perspective);
    float EvaluateMobility(UChessGameLogic* GameLogic, EPieceColor Perspective);
    float EvaluatePawnStructure(UChessGameLogic* GameLogic, EPieceColor Perspective);

    // Opening book
    FChessMove GetOpeningBookMove(UChessGameLogic* GameLogic);
    void LoadOpeningBook();

    // Difficulty scaling
    int32 GetSearchDepth() const;
    float GetRandomness() const;
    bool ShouldUseStockfish() const;

    // Stockfish integration
    bool bStockfishInitialized = false;
    FString StockfishPath;
    
    // Move ordering for alpha-beta pruning
    void OrderMoves(TArray<FChessMove>& Moves, UChessGameLogic* GameLogic, EPieceColor Color);
    int32 GetMoveOrderScore(const FChessMove& Move, UChessGameLogic* GameLogic);

    // Transposition table for caching evaluations
    UPROPERTY()
    TMap<FString, FMoveEvaluation> TranspositionTable;

    // Opening book moves - using multimap approach
    TMap<FString, TArray<FChessMove>> OpeningBook;

    // Piece values for material calculation
    static const TMap<EPieceType, float> PieceValues;
    
    // Position value tables (piece-square tables)
    static const TArray<TArray<float>> PawnTable;
    static const TArray<TArray<float>> KnightTable;
    static const TArray<TArray<float>> BishopTable;
    static const TArray<TArray<float>> RookTable;
    static const TArray<TArray<float>> QueenTable;
    static const TArray<TArray<float>> KingMiddlegameTable;
    static const TArray<TArray<float>> KingEndgameTable;
};