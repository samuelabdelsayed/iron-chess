#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChessTypes.h"
#include "ChessGameLogic.generated.h"

/**
 * Core chess game logic implementation
 * Handles move validation, game state management, and rule enforcement
 */
UCLASS(BlueprintType, Blueprintable)
class IRONCHESS_API UChessGameLogic : public UObject
{
    GENERATED_BODY()

public:
    UChessGameLogic();

    // Core game functions
    UFUNCTION(BlueprintCallable, Category = "Chess")
    bool IsValidMove(const FChessMove& Move) const;

    UFUNCTION(BlueprintCallable, Category = "Chess")
    bool MakeMove(const FChessMove& Move);

    UFUNCTION(BlueprintCallable, Category = "Chess")
    TArray<FChessMove> GetLegalMoves(EPieceColor Color) const;

    UFUNCTION(BlueprintCallable, Category = "Chess")
    TArray<FChessMove> GetLegalMovesForPiece(const FChessPosition& Position) const;

    UFUNCTION(BlueprintCallable, Category = "Chess")
    bool IsInCheck(EPieceColor Color) const;

    UFUNCTION(BlueprintCallable, Category = "Chess")
    bool IsCheckmate(EPieceColor Color) const;

    UFUNCTION(BlueprintCallable, Category = "Chess")
    bool IsStalemate(EPieceColor Color) const;

    UFUNCTION(BlueprintCallable, Category = "Chess")
    void ResetGame();

    // Game state accessors
    UFUNCTION(BlueprintPure, Category = "Chess")
    const FChessBoardState& GetBoardState() const { return BoardState; }

    UFUNCTION(BlueprintPure, Category = "Chess")
    FChessPiece GetPieceAt(const FChessPosition& Position) const;

    UFUNCTION(BlueprintPure, Category = "Chess")
    EPieceColor GetActivePlayer() const { return BoardState.ActivePlayer; }

    UFUNCTION(BlueprintPure, Category = "Chess")
    EGameState GetGameState() const { return BoardState.GameState; }

    UFUNCTION(BlueprintPure, Category = "Chess")
    int32 GetMoveNumber() const { return BoardState.MoveNumber; }

    UFUNCTION(BlueprintPure, Category = "Chess")
    TArray<FChessMove> GetMoveHistory() const { return MoveHistory; }

    // Special moves
    UFUNCTION(BlueprintCallable, Category = "Chess")
    bool CanCastle(EPieceColor Color, bool Kingside) const;

    UFUNCTION(BlueprintCallable, Category = "Chess")
    FChessPosition FindKing(EPieceColor Color) const;

    // Move generation helpers
    UFUNCTION(BlueprintCallable, Category = "Chess")
    TArray<FChessPosition> GetAttackedSquares(EPieceColor Color) const;

    // FEN notation support
    UFUNCTION(BlueprintCallable, Category = "Chess")
    FString GetFENString() const;

    UFUNCTION(BlueprintCallable, Category = "Chess")
    bool LoadFromFEN(const FString& FENString);

    // Event delegates
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveMade, const FChessMove&, Move);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameStateChanged, EGameState, NewState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCheck, EPieceColor, PlayerInCheck);

    UPROPERTY(BlueprintAssignable)
    FOnMoveMade OnMoveMade;

    UPROPERTY(BlueprintAssignable)
    FOnGameStateChanged OnGameStateChanged;

    UPROPERTY(BlueprintAssignable)
    FOnCheck OnCheck;

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Chess")
    FChessBoardState BoardState;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Chess")
    TArray<FChessMove> MoveHistory;

private:
    // Move validation helpers
    bool IsValidPawnMove(const FChessMove& Move) const;
    bool IsValidRookMove(const FChessMove& Move) const;
    bool IsValidKnightMove(const FChessMove& Move) const;
    bool IsValidBishopMove(const FChessMove& Move) const;
    bool IsValidQueenMove(const FChessMove& Move) const;
    bool IsValidKingMove(const FChessMove& Move) const;

    bool IsPathClear(const FChessPosition& From, const FChessPosition& To) const;
    bool WouldMoveCauseCheck(const FChessMove& Move, EPieceColor Color) const;
    
    // Move generation
    void GeneratePawnMoves(const FChessPosition& Position, TArray<FChessMove>& OutMoves) const;
    void GenerateRookMoves(const FChessPosition& Position, TArray<FChessMove>& OutMoves) const;
    void GenerateKnightMoves(const FChessPosition& Position, TArray<FChessMove>& OutMoves) const;
    void GenerateBishopMoves(const FChessPosition& Position, TArray<FChessMove>& OutMoves) const;
    void GenerateQueenMoves(const FChessPosition& Position, TArray<FChessMove>& OutMoves) const;
    void GenerateKingMoves(const FChessPosition& Position, TArray<FChessMove>& OutMoves) const;
    
    // Special move handling
    void HandleSpecialMoves(const FChessMove& Move);
    void GenerateCastlingMoves(const FChessPosition& Position, TArray<FChessMove>& OutMoves) const;

    // Game state management
    void UpdateGameState();
    void SwitchActivePlayer();
    void UpdateCastlingRights(const FChessMove& Move);
    void UpdateEnPassantTarget(const FChessMove& Move);

    // Utility functions
    static int32 GetDirection(int32 From, int32 To);
    static bool IsOnBoard(const FChessPosition& Position);
};