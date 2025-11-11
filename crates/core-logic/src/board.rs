//! Chess board representation and manipulation

use crate::moves::{ChessMove, MoveFlags};
use crate::pieces::{Color, Piece, PieceType, Position};
use serde::{Deserialize, Serialize};

/// Represents the phase of the game
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
pub enum GamePhase {
    Opening,
    Middlegame,
    Endgame,
}

/// Represents the result of a game
#[derive(Debug, Clone, PartialEq, Eq, Serialize, Deserialize)]
pub enum GameResult {
    Checkmate(Color), // Winner
    Stalemate,
    Draw(String),
}

/// Represents an 8x8 chess board
#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct ChessBoard {
    squares: [[Option<Piece>; 8]; 8], // [file][rank]
    en_passant_target: Option<Position>,
    white_can_castle_kingside: bool,
    white_can_castle_queenside: bool,
    black_can_castle_kingside: bool,
    black_can_castle_queenside: bool,
}

impl ChessBoard {
    /// Creates a new empty board
    pub fn empty() -> Self {
        Self {
            squares: [[None; 8]; 8],
            en_passant_target: None,
            white_can_castle_kingside: true,
            white_can_castle_queenside: true,
            black_can_castle_kingside: true,
            black_can_castle_queenside: true,
        }
    }

    /// Creates a board with the standard starting position
    pub fn standard_starting_position() -> Self {
        let mut board = Self::empty();

        // Place pawns
        for file in 0..8 {
            board.set_piece(Position::new(file, 1), Piece::new(PieceType::Pawn, Color::White));
            board.set_piece(Position::new(file, 6), Piece::new(PieceType::Pawn, Color::Black));
        }

        // Place back rank pieces
        let back_rank = [
            PieceType::Rook,
            PieceType::Knight,
            PieceType::Bishop,
            PieceType::King,     // King on d-file (index 3) - d1 (USER'S ORIGINAL CUSTOM LAYOUT)
            PieceType::Queen,    // Queen on e-file (index 4) - e1 (USER'S ORIGINAL CUSTOM LAYOUT)
            PieceType::Bishop,
            PieceType::Knight,
            PieceType::Rook,
        ];

        for (file, &piece_type) in back_rank.iter().enumerate() {
            board.set_piece(Position::new(file as u8, 0), Piece::new(piece_type, Color::White));
            board.set_piece(Position::new(file as u8, 7), Piece::new(piece_type, Color::Black));
        }

        board
    }

    /// Gets the piece at the given position
    pub fn get_piece(&self, pos: &Position) -> Option<Piece> {
        self.squares[pos.file as usize][pos.rank as usize]
    }

    /// Sets a piece at the given position
    pub fn set_piece(&mut self, pos: Position, piece: Piece) {
        self.squares[pos.file as usize][pos.rank as usize] = Some(piece);
    }

    /// Removes a piece from the given position
    pub fn remove_piece(&mut self, pos: &Position) -> Option<Piece> {
        self.squares[pos.file as usize][pos.rank as usize].take()
    }

    /// Applies a move to the board (assumes move is legal)
    pub fn apply_move(&mut self, chess_move: &ChessMove) {
        let piece = self.remove_piece(&chess_move.from).expect("No piece to move");

        // Handle castling
        if chess_move.is_castling() {
            let rank = chess_move.from.rank;
            if chess_move.flags.contains(MoveFlags::CASTLING_KINGSIDE) {
                // Kingside: King d->f, Rook h->e (King on d-file)
                let rook = self.remove_piece(&Position::new(7, rank)).expect("No rook for castling");
                self.set_piece(Position::new(4, rank), rook);
            } else {
                // Queenside castling: King d->b, Rook a->c (King on d-file)
                let rook = self.remove_piece(&Position::new(0, rank)).expect("No rook for castling");
                self.set_piece(Position::new(2, rank), rook);
            }
        }

        // Handle en passant capture
        if chess_move.flags.contains(MoveFlags::EN_PASSANT) {
            let captured_pawn_rank = if piece.color == Color::White {
                chess_move.to.rank - 1
            } else {
                chess_move.to.rank + 1
            };
            self.remove_piece(&Position::new(chess_move.to.file, captured_pawn_rank));
        }

        // Handle promotion
        let final_piece = if let Some(promo_type) = chess_move.promotion_piece() {
            Piece::new(promo_type, piece.color)
        } else {
            piece
        };

        // Place piece at destination
        self.set_piece(chess_move.to, Piece {
            has_moved: true,
            ..final_piece
        });

        // Update en passant target
        self.en_passant_target = if chess_move.flags.contains(MoveFlags::PAWN_DOUBLE_PUSH) {
            Some(Position::new(
                chess_move.to.file,
                (chess_move.from.rank + chess_move.to.rank) / 2,
            ))
        } else {
            None
        };

        // Update castling rights
        if piece.piece_type == PieceType::King {
            match piece.color {
                Color::White => {
                    self.white_can_castle_kingside = false;
                    self.white_can_castle_queenside = false;
                }
                Color::Black => {
                    self.black_can_castle_kingside = false;
                    self.black_can_castle_queenside = false;
                }
            }
        }

        if piece.piece_type == PieceType::Rook {
            match (piece.color, chess_move.from.file) {
                (Color::White, 0) => self.white_can_castle_queenside = false,
                (Color::White, 7) => self.white_can_castle_kingside = false,
                (Color::Black, 0) => self.black_can_castle_queenside = false,
                (Color::Black, 7) => self.black_can_castle_kingside = false,
                _ => {}
            }
        }
    }

    /// Finds the king position for the given color
    pub fn find_king(&self, color: Color) -> Option<Position> {
        for file in 0..8 {
            for rank in 0..8 {
                if let Some(piece) = self.squares[file][rank] {
                    if piece.piece_type == PieceType::King && piece.color == color {
                        return Some(Position::new(file as u8, rank as u8));
                    }
                }
            }
        }
        None
    }

    /// Counts total material on the board
    pub fn count_material(&self) -> i32 {
        let mut total = 0;
        for file in 0..8 {
            for rank in 0..8 {
                if let Some(piece) = self.squares[file][rank] {
                    total += piece.material_value();
                }
            }
        }
        total
    }

    /// Checks if there's insufficient material for checkmate
    pub fn has_insufficient_material(&self) -> bool {
        let mut pieces = Vec::new();
        for file in 0..8 {
            for rank in 0..8 {
                if let Some(piece) = self.squares[file][rank] {
                    pieces.push(piece);
                }
            }
        }

        // King vs King
        if pieces.len() == 2 {
            return true;
        }

        // King + minor piece vs King
        if pieces.len() == 3 {
            return pieces
                .iter()
                .any(|p| p.piece_type == PieceType::Knight || p.piece_type == PieceType::Bishop);
        }

        false
    }

    pub fn en_passant_target(&self) -> Option<Position> {
        self.en_passant_target
    }

    pub fn can_castle_kingside(&self, color: Color) -> bool {
        match color {
            Color::White => self.white_can_castle_kingside,
            Color::Black => self.black_can_castle_kingside,
        }
    }

    pub fn can_castle_queenside(&self, color: Color) -> bool {
        match color {
            Color::White => self.white_can_castle_queenside,
            Color::Black => self.black_can_castle_queenside,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_standard_position() {
        let board = ChessBoard::standard_starting_position();
        
        // Check white pawns
        for file in 0..8 {
            let piece = board.get_piece(&Position::new(file, 1)).unwrap();
            assert_eq!(piece.piece_type, PieceType::Pawn);
            assert_eq!(piece.color, Color::White);
        }

        // Check white king
        let king = board.get_piece(&Position::new(4, 0)).unwrap();
        assert_eq!(king.piece_type, PieceType::King);
    }

    #[test]
    fn test_find_king() {
        let board = ChessBoard::standard_starting_position();
        assert_eq!(board.find_king(Color::White), Some(Position::new(4, 0)));
        assert_eq!(board.find_king(Color::Black), Some(Position::new(4, 7)));
    }
}
