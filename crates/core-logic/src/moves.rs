//! Chess move representation and history tracking

use crate::pieces::{Piece, PieceType, Position};
use serde::{Deserialize, Serialize};

bitflags::bitflags! {
    /// Flags representing special properties of a chess move
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
    pub struct MoveFlags: u16 {
        const NONE = 0;
        const CAPTURE = 1 << 0;
        const EN_PASSANT = 1 << 1;
        const CASTLING_KINGSIDE = 1 << 2;
        const CASTLING_QUEENSIDE = 1 << 3;
        const PAWN_DOUBLE_PUSH = 1 << 4;
        const PROMOTION_QUEEN = 1 << 5;
        const PROMOTION_ROOK = 1 << 6;
        const PROMOTION_BISHOP = 1 << 7;
        const PROMOTION_KNIGHT = 1 << 8;
    }
}

/// Represents a single chess move
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
pub struct ChessMove {
    pub from: Position,
    pub to: Position,
    pub flags: MoveFlags,
    pub moved_piece: Option<Piece>,
    pub captured_piece: Option<Piece>,
}

impl ChessMove {
    pub fn new(from: Position, to: Position, flags: MoveFlags) -> Self {
        Self {
            from,
            to,
            flags,
            moved_piece: None,
            captured_piece: None,
        }
    }

    pub fn with_pieces(mut self, moved: Piece, captured: Option<Piece>) -> Self {
        self.moved_piece = Some(moved);
        self.captured_piece = captured;
        self
    }

    pub fn is_capture(&self) -> bool {
        self.flags.contains(MoveFlags::CAPTURE) || self.flags.contains(MoveFlags::EN_PASSANT)
    }

    pub fn is_castling(&self) -> bool {
        self.flags.contains(MoveFlags::CASTLING_KINGSIDE) || self.flags.contains(MoveFlags::CASTLING_QUEENSIDE)
    }

    pub fn is_promotion(&self) -> bool {
        self.flags.intersects(
            MoveFlags::PROMOTION_QUEEN
                | MoveFlags::PROMOTION_ROOK
                | MoveFlags::PROMOTION_BISHOP
                | MoveFlags::PROMOTION_KNIGHT,
        )
    }

    pub fn promotion_piece(&self) -> Option<PieceType> {
        if self.flags.contains(MoveFlags::PROMOTION_QUEEN) {
            Some(PieceType::Queen)
        } else if self.flags.contains(MoveFlags::PROMOTION_ROOK) {
            Some(PieceType::Rook)
        } else if self.flags.contains(MoveFlags::PROMOTION_BISHOP) {
            Some(PieceType::Bishop)
        } else if self.flags.contains(MoveFlags::PROMOTION_KNIGHT) {
            Some(PieceType::Knight)
        } else {
            None
        }
    }

    /// Converts move to long algebraic notation (e.g., "e2e4", "e7e8q")
    pub fn to_lan(&self) -> String {
        let mut lan = format!("{}{}", self.from.to_algebraic(), self.to.to_algebraic());
        
        if let Some(promo) = self.promotion_piece() {
            lan.push(match promo {
                PieceType::Queen => 'q',
                PieceType::Rook => 'r',
                PieceType::Bishop => 'b',
                PieceType::Knight => 'n',
                _ => unreachable!(),
            });
        }
        
        lan
    }
}

/// Tracks the history of moves in a game
#[derive(Debug, Clone, Default, Serialize, Deserialize)]
pub struct MoveHistory {
    moves: Vec<ChessMove>,
}

impl MoveHistory {
    pub fn new() -> Self {
        Self { moves: Vec::new() }
    }

    pub fn push(&mut self, chess_move: ChessMove) {
        self.moves.push(chess_move);
    }

    pub fn pop(&mut self) -> Option<ChessMove> {
        self.moves.pop()
    }

    pub fn last(&self) -> Option<&ChessMove> {
        self.moves.last()
    }

    pub fn len(&self) -> usize {
        self.moves.len()
    }

    pub fn is_empty(&self) -> bool {
        self.moves.is_empty()
    }

    pub fn iter(&self) -> impl Iterator<Item = &ChessMove> {
        self.moves.iter()
    }

    /// Returns moves in PGN notation
    pub fn to_pgn(&self) -> String {
        self.moves
            .iter()
            .enumerate()
            .map(|(i, m)| {
                if i % 2 == 0 {
                    format!("{}. {}", i / 2 + 1, m.to_lan())
                } else {
                    m.to_lan()
                }
            })
            .collect::<Vec<_>>()
            .join(" ")
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_move_flags() {
        let capture_move = ChessMove::new(
            Position::new(4, 3),
            Position::new(5, 4),
            MoveFlags::CAPTURE,
        );
        assert!(capture_move.is_capture());
        assert!(!capture_move.is_castling());
    }

    #[test]
    fn test_move_history() {
        let mut history = MoveHistory::new();
        let move1 = ChessMove::new(
            Position::new(4, 1),
            Position::new(4, 3),
            MoveFlags::DOUBLE_PAWN_PUSH,
        );
        
        history.push(move1);
        assert_eq!(history.len(), 1);
        assert_eq!(history.last(), Some(&move1));
    }
}
