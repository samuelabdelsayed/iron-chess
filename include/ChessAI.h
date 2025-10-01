#pragma once

#include "ChessBoard.h"
#include <random>
#include <chrono>

namespace IronChess {

enum class Difficulty {
    Beginner = 1,
    Novice,
    Casual,
    Intermediate,
    Advanced,
    Expert,
    Master,
    Grandmaster,
    WorldClass,
    Legendary
};

class ChessAI {
public:
    explicit ChessAI(Difficulty diff = Difficulty::Intermediate);
    
    // Main AI interface
    Move getBestMove(const ChessBoard& board, PieceColor color);
    void setDifficulty(Difficulty diff) { difficulty = diff; }
    Difficulty getDifficulty() const { return difficulty; }
    
    // AI personality settings
    void setAggression(float level) { aggression = std::clamp(level, 0.0f, 1.0f); }
    void setRiskTaking(float level) { riskTaking = std::clamp(level, 0.0f, 1.0f); }
    void setPositionalFocus(float level) { positionalFocus = std::clamp(level, 0.0f, 1.0f); }
    
    // Analysis
    float evaluatePosition(const ChessBoard& board, PieceColor color) const;
    int getSearchDepth() const;
    
private:
    Difficulty difficulty;
    float aggression = 0.5f;
    float riskTaking = 0.5f;
    float positionalFocus = 0.5f;
    
    mutable std::mt19937 rng;
    
    // Search algorithms
    float minimax(ChessBoard& board, int depth, float alpha, float beta, bool maximizing, PieceColor color) const;
    Move getRandomMove(const ChessBoard& board, PieceColor color) const;
    Move getBookMove(const ChessBoard& board, PieceColor color) const;
    
    // Evaluation functions
    float evaluateMaterial(const ChessBoard& board, PieceColor color) const;
    float evaluatePosition(const ChessBoard& board, PieceColor color, const Position& pos) const;
    float evaluatePieceSquareTables(const ChessBoard& board, PieceColor color) const;
    float evaluateKingSafety(const ChessBoard& board, PieceColor color) const;
    float evaluatePawnStructure(const ChessBoard& board, PieceColor color) const;
    float evaluateMobility(const ChessBoard& board, PieceColor color) const;
    
    // Opening book
    std::vector<Move> getOpeningMoves(const ChessBoard& board, PieceColor color) const;
    bool isInOpeningPhase(const ChessBoard& board) const;
    
    // Endgame
    bool isEndgame(const ChessBoard& board) const;
    float evaluateEndgame(const ChessBoard& board, PieceColor color) const;
    
    // Move ordering for alpha-beta pruning
    void orderMoves(std::vector<Move>& moves, const ChessBoard& board, PieceColor color) const;
    int getMoveScore(const Move& move, const ChessBoard& board) const;
};

} // namespace IronChess