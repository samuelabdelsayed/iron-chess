#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "ChessTypes.generated.h"

/**
 * Core types and enumerations for the Iron Chess game system
 */

// Forward declarations
UENUM(BlueprintType)
enum class EPieceType : uint8
{
    None = 0,
    Pawn = 1,
    Rook = 2,
    Knight = 3,
    Bishop = 4,
    Queen = 5,
    King = 6
};

UENUM(BlueprintType)
enum class EPieceColor : uint8
{
    None = 0,
    White,
    Black
};

UENUM(BlueprintType)
enum class EGameState : uint8
{
    WaitingForPlayers,
    InProgress,
    Check,
    Checkmate,
    Stalemate,
    Draw
};

UENUM(BlueprintType)
enum class EMoveType : uint8
{
    Normal,
    Capture,
    Castling,
    Castle = Castling,
    EnPassant,
    PawnPromotion,
    Promotion = PawnPromotion
};

/**
 * Represents a position on the chess board
 */
USTRUCT(BlueprintType)
struct IRONCHESS_API FChessPosition
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Rank;

    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    int32 File;

    FChessPosition()
        : Rank(0), File(0) {}

    FChessPosition(int32 InRank, int32 InFile)
        : Rank(InRank), File(InFile) {}

    bool operator==(const FChessPosition& Other) const
    {
        return Rank == Other.Rank && File == Other.File;
    }

    bool operator!=(const FChessPosition& Other) const
    {
        return !(*this == Other);
    }

    FString ToString() const
    {
        return FString::Printf(TEXT("%c%d"), 'a' + File, Rank + 1);
    }

    bool IsValid() const
    {
        return Rank >= 0 && Rank < 8 && File >= 0 && File < 8;
    }
};

/**
 * Represents a chess piece
 */
USTRUCT(BlueprintType)
struct IRONCHESS_API FChessPiece
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPieceType Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPieceColor Color;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool HasMoved;

    FChessPiece()
        : Type(EPieceType::None), Color(EPieceColor::White), HasMoved(false) {}

    FChessPiece(EPieceType InType, EPieceColor InColor, bool bInHasMoved = false)
        : Type(InType), Color(InColor), HasMoved(bInHasMoved) {}

    bool IsEmpty() const
    {
        return Type == EPieceType::None;
    }

    bool IsOpposite(const FChessPiece& Other) const
    {
        return !IsEmpty() && !Other.IsEmpty() && Color != Other.Color;
    }

    bool IsSameColor(const FChessPiece& Other) const
    {
        return !IsEmpty() && !Other.IsEmpty() && Color == Other.Color;
    }
};

/**
 * Represents a chess move
 */
USTRUCT(BlueprintType)
struct IRONCHESS_API FChessMove
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FChessPosition From;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FChessPosition To;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EMoveType MoveType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPieceType PromotionPiece;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FChessPiece CapturedPiece;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsCheck;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool IsCheckmate;

    FChessMove()
        : MoveType(EMoveType::Normal), PromotionPiece(EPieceType::None), 
          IsCheck(false), IsCheckmate(false) {}

    FChessMove(const FChessPosition& InFrom, const FChessPosition& InTo, EMoveType InMoveType = EMoveType::Normal)
        : From(InFrom), To(InTo), MoveType(InMoveType), PromotionPiece(EPieceType::None),
          IsCheck(false), IsCheckmate(false) {}

    FString ToString() const
    {
        return FString::Printf(TEXT("%s-%s"), *From.ToString(), *To.ToString());
    }

    FString ToAlgebraicNotation() const
    {
        return ToString(); // Simplified for now
    }
};

/**
 * Represents the complete state of the chess board
 */
USTRUCT(BlueprintType)
struct IRONCHESS_API FChessBoardState
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FChessPiece> Board;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EPieceColor ActivePlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EGameState GameState;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 MoveNumber;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 HalfMoveCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FChessPosition EnPassantTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool WhiteCanCastleKingside;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool WhiteCanCastleQueenside;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool BlackCanCastleKingside;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool BlackCanCastleQueenside;

    FChessBoardState()
    {
        Board.SetNum(64);
        ActivePlayer = EPieceColor::White;
        GameState = EGameState::InProgress;
        MoveNumber = 1;
        HalfMoveCount = 0;
        EnPassantTarget = FChessPosition(-1, -1);
        WhiteCanCastleKingside = true;
        WhiteCanCastleQueenside = true;
        BlackCanCastleKingside = true;
        BlackCanCastleQueenside = true;
        InitializeStandardBoard();
    }

    int32 GetBoardIndex(int32 Rank, int32 File) const
    {
        return Rank * 8 + File;
    }

    FChessPiece& GetPieceAt(int32 Rank, int32 File)
    {
        return Board[GetBoardIndex(Rank, File)];
    }

    const FChessPiece& GetPieceAt(int32 Rank, int32 File) const
    {
        return Board[GetBoardIndex(Rank, File)];
    }

private:
    void InitializeStandardBoard()
    {
        // Clear board
        for (int32 i = 0; i < 64; i++)
        {
            Board[i] = FChessPiece();
        }

        // White pieces (rank 0)
        GetPieceAt(0, 0) = FChessPiece(EPieceType::Rook, EPieceColor::White);
        GetPieceAt(0, 1) = FChessPiece(EPieceType::Knight, EPieceColor::White);
        GetPieceAt(0, 2) = FChessPiece(EPieceType::Bishop, EPieceColor::White);
        GetPieceAt(0, 3) = FChessPiece(EPieceType::Queen, EPieceColor::White);
        GetPieceAt(0, 4) = FChessPiece(EPieceType::King, EPieceColor::White);
        GetPieceAt(0, 5) = FChessPiece(EPieceType::Bishop, EPieceColor::White);
        GetPieceAt(0, 6) = FChessPiece(EPieceType::Knight, EPieceColor::White);
        GetPieceAt(0, 7) = FChessPiece(EPieceType::Rook, EPieceColor::White);

        // White pawns (rank 1)
        for (int32 File = 0; File < 8; File++)
        {
            GetPieceAt(1, File) = FChessPiece(EPieceType::Pawn, EPieceColor::White);
        }

        // Black pawns (rank 6)
        for (int32 File = 0; File < 8; File++)
        {
            GetPieceAt(6, File) = FChessPiece(EPieceType::Pawn, EPieceColor::Black);
        }

        // Black pieces (rank 7)
        GetPieceAt(7, 0) = FChessPiece(EPieceType::Rook, EPieceColor::Black);
        GetPieceAt(7, 1) = FChessPiece(EPieceType::Knight, EPieceColor::Black);
        GetPieceAt(7, 2) = FChessPiece(EPieceType::Bishop, EPieceColor::Black);
        GetPieceAt(7, 3) = FChessPiece(EPieceType::Queen, EPieceColor::Black);
        GetPieceAt(7, 4) = FChessPiece(EPieceType::King, EPieceColor::Black);
        GetPieceAt(7, 5) = FChessPiece(EPieceType::Bishop, EPieceColor::Black);
        GetPieceAt(7, 6) = FChessPiece(EPieceType::Knight, EPieceColor::Black);
        GetPieceAt(7, 7) = FChessPiece(EPieceType::Rook, EPieceColor::Black);
    }
};