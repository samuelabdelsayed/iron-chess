#pragma once

#include "ChessTypes.h"
#include <array>
#include <vector>
#include <functional>

namespace IronChess {

class ChessBoard {
public:
    ChessBoard();
    
    // Board state
    void reset();
    const Piece& getPiece(const Position& pos) const;
    void setPiece(const Position& pos, const Piece& piece);
    bool isEmpty(const Position& pos) const;
    
    // Move validation and execution
    bool isValidMove(const Move& move) const;
    bool makeMove(const Move& move);
    void undoMove();
    
    // Game state queries
    std::vector<Move> getLegalMoves(PieceColor color) const;
    std::vector<Move> getLegalMovesForPiece(const Position& pos) const;
    bool isInCheck(PieceColor color) const;
    bool isCheckmate(PieceColor color) const;
    bool isStalemate(PieceColor color) const;
    GameState getGameState() const;
    
    // Special move detection
    bool canCastle(PieceColor color, bool kingside) const;
    Position getEnPassantTarget() const { return enPassantTarget; }
    
    // Utility
    PieceColor getCurrentPlayer() const { return currentPlayer; }
    int getMoveCount() const { return moveCount; }
    std::string toFEN() const;
    bool loadFromFEN(const std::string& fen);
    
    // Events
    std::function<void(const Move&)> onMoveMade;
    std::function<void(GameState)> onGameStateChanged;

private:
    std::array<std::array<Piece, 8>, 8> board;
    PieceColor currentPlayer;
    int moveCount;
    int halfMoveClock; // For 50-move rule
    
    // Special state
    Position enPassantTarget;
    bool whiteCanCastleKingside;
    bool whiteCanCastleQueenside;
    bool blackCanCastleKingside;
    bool blackCanCastleQueenside;
    
    // Move history for undo
    struct MoveHistory {
        Move move;
        Piece capturedPiece;
        Position enPassantTarget;
        bool castlingRights[4]; // [WK, WQ, BK, BQ]
        int halfMoveClock;
    };
    std::vector<MoveHistory> moveHistory;
    
    // Move validation helpers
    bool isValidPawnMove(const Move& move) const;
    bool isValidRookMove(const Move& move) const;
    bool isValidKnightMove(const Move& move) const;
    bool isValidBishopMove(const Move& move) const;
    bool isValidQueenMove(const Move& move) const;
    bool isValidKingMove(const Move& move) const;
    
    bool isPathClear(const Position& from, const Position& to) const;
    bool wouldKingBeInCheck(const Move& move, PieceColor color) const;
    std::vector<Position> getAttackedSquares(PieceColor color) const;
    Position findKing(PieceColor color) const;
    
    // Move generation
    void generatePawnMoves(const Position& pos, std::vector<Move>& moves) const;
    void generateRookMoves(const Position& pos, std::vector<Move>& moves) const;
    void generateKnightMoves(const Position& pos, std::vector<Move>& moves) const;
    void generateBishopMoves(const Position& pos, std::vector<Move>& moves) const;
    void generateQueenMoves(const Position& pos, std::vector<Move>& moves) const;
    void generateKingMoves(const Position& pos, std::vector<Move>& moves) const;
    
    // Utility
    void updateGameState();
    void updateCastlingRights(const Move& move);
    void switchPlayer() { currentPlayer = (currentPlayer == PieceColor::White) ? PieceColor::Black : PieceColor::White; }
};

} // namespace IronChess