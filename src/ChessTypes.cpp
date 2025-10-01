#include "ChessTypes.h"

namespace IronChess {

char Piece::getSymbol() const {
    if (type == PieceType::None) return ' ';
    
    char symbols[] = {' ', 'P', 'R', 'N', 'B', 'Q', 'K'};
    char symbol = symbols[static_cast<int>(type)];
    
    return (color == PieceColor::White) ? symbol : (symbol + 32); // lowercase for black
}

float Piece::getValue() const {
    switch (type) {
        case PieceType::Pawn:   return 1.0f;
        case PieceType::Knight: return 3.0f;
        case PieceType::Bishop: return 3.0f;
        case PieceType::Rook:   return 5.0f;
        case PieceType::Queen:  return 9.0f;
        case PieceType::King:   return 1000.0f;
        default:                return 0.0f;
    }
}

std::string Move::toAlgebraicNotation() const {
    std::string notation;
    
    // Add piece letter (except for pawns)
    if (capturedPiece.type != PieceType::Pawn && capturedPiece.type != PieceType::None) {
        char pieceSymbols[] = {' ', 'P', 'R', 'N', 'B', 'Q', 'K'};
        if (capturedPiece.type != PieceType::Pawn) {
            notation += pieceSymbols[static_cast<int>(capturedPiece.type)];
        }
    }
    
    // Add capture symbol
    if (isCapture) {
        notation += 'x';
    }
    
    // Add destination square
    notation += to.toString();
    
    // Add promotion
    if (promotionPiece != PieceType::None) {
        char pieceSymbols[] = {' ', 'P', 'R', 'N', 'B', 'Q', 'K'};
        notation += '=';
        notation += pieceSymbols[static_cast<int>(promotionPiece)];
    }
    
    // Add check/checkmate
    if (isCheckmate) {
        notation += '#';
    } else if (isCheck) {
        notation += '+';
    }
    
    return notation;
}

} // namespace IronChess