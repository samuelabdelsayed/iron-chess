#pragma once

#include <array>
#include <vector>
#include <string>
#include <memory>

namespace IronChess {

enum class PieceType {
    None = 0,
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King
};

enum class PieceColor {
    None = 0,
    White,
    Black
};

struct Position {
    int file; // 0-7 (a-h)
    int rank; // 0-7 (1-8)
    
    Position() : file(0), rank(0) {}
    Position(int f, int r) : file(f), rank(r) {}
    
    bool operator==(const Position& other) const {
        return file == other.file && rank == other.rank;
    }
    
    bool operator!=(const Position& other) const {
        return !(*this == other);
    }
    
    bool isValid() const {
        return file >= 0 && file < 8 && rank >= 0 && rank < 8;
    }
    
    std::string toString() const {
        return std::string(1, 'a' + file) + std::to_string(rank + 1);
    }
};

struct Piece {
    PieceType type = PieceType::None;
    PieceColor color = PieceColor::None;
    bool hasMoved = false;
    
    Piece() = default;
    Piece(PieceType t, PieceColor c) : type(t), color(c) {}
    
    bool isEmpty() const { return type == PieceType::None; }
    char getSymbol() const;
    float getValue() const;
};

struct Move {
    Position from;
    Position to;
    PieceType promotionPiece = PieceType::None;
    bool isCapture = false;
    bool isCheck = false;
    bool isCheckmate = false;
    bool isCastling = false;
    bool isEnPassant = false;
    Piece capturedPiece;
    
    Move() = default;
    Move(Position f, Position t) : from(f), to(t) {}
    
    std::string toAlgebraicNotation() const;
};

enum class GameState {
    Playing,
    Check,
    Checkmate,
    Stalemate,
    Draw
};

} // namespace IronChess