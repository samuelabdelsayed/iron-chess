//! Chess piece definitions and utilities

use serde::{Deserialize, Serialize};
use std::fmt;

/// Represents a chess piece color
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, Serialize, Deserialize)]
pub enum Color {
    White,
    Black,
}

impl Color {
    /// Returns the opposite color
    pub fn opposite(self) -> Self {
        match self {
            Color::White => Color::Black,
            Color::Black => Color::White,
        }
    }

    /// Returns the direction pawns move for this color (1 for White, -1 for Black)
    pub fn pawn_direction(self) -> i8 {
        match self {
            Color::White => 1,
            Color::Black => -1,
        }
    }

    /// Returns the starting rank for pawns of this color
    pub fn pawn_start_rank(self) -> u8 {
        match self {
            Color::White => 1,
            Color::Black => 6,
        }
    }

    /// Returns the promotion rank for pawns of this color
    pub fn promotion_rank(self) -> u8 {
        match self {
            Color::White => 7,
            Color::Black => 0,
        }
    }
}

/// Represents the type of chess piece
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, Serialize, Deserialize)]
pub enum PieceType {
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King,
}

impl PieceType {
    /// Returns the relative material value of this piece type
    pub fn material_value(self) -> i32 {
        match self {
            PieceType::Pawn => 100,
            PieceType::Knight => 320,
            PieceType::Bishop => 330,
            PieceType::Rook => 500,
            PieceType::Queen => 900,
            PieceType::King => 20000,
        }
    }

    /// Returns the symbol for this piece (FEN notation)
    pub fn symbol(self, color: Color) -> char {
        let base = match self {
            PieceType::Pawn => 'p',
            PieceType::Knight => 'n',
            PieceType::Bishop => 'b',
            PieceType::Rook => 'r',
            PieceType::Queen => 'q',
            PieceType::King => 'k',
        };
        
        match color {
            Color::White => base.to_ascii_uppercase(),
            Color::Black => base,
        }
    }
}

/// Represents a complete chess piece
#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
pub struct Piece {
    pub piece_type: PieceType,
    pub color: Color,
    pub has_moved: bool,
}

impl Piece {
    pub fn new(piece_type: PieceType, color: Color) -> Self {
        Self {
            piece_type,
            color,
            has_moved: false,
        }
    }

    pub fn material_value(&self) -> i32 {
        self.piece_type.material_value()
    }

    pub fn symbol(&self) -> char {
        self.piece_type.symbol(self.color)
    }
}

/// Represents a position on the chess board (0-7 for both file and rank)
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, Serialize, Deserialize)]
pub struct Position {
    pub file: u8, // 0 = a, 7 = h
    pub rank: u8, // 0 = 1, 7 = 8
}

impl Position {
    pub fn new(file: u8, rank: u8) -> Self {
        assert!(file < 8 && rank < 8, "Position out of bounds");
        Self { file, rank }
    }

    /// Creates a position from algebraic notation (e.g., "e4")
    pub fn from_algebraic(s: &str) -> Option<Self> {
        if s.len() != 2 {
            return None;
        }
        
        let bytes = s.as_bytes();
        let file = bytes[0].wrapping_sub(b'a');
        let rank = bytes[1].wrapping_sub(b'1');
        
        if file < 8 && rank < 8 {
            Some(Position::new(file, rank))
        } else {
            None
        }
    }

    /// Converts position to algebraic notation (e.g., "e4")
    pub fn to_algebraic(&self) -> String {
        format!("{}{}", (b'a' + self.file) as char, self.rank + 1)
    }

    /// Checks if a position is valid on the board
    pub fn is_valid(file: i8, rank: i8) -> bool {
        file >= 0 && file < 8 && rank >= 0 && rank < 8
    }

    /// Returns the offset position if valid
    pub fn offset(&self, file_offset: i8, rank_offset: i8) -> Option<Self> {
        let new_file = self.file as i8 + file_offset;
        let new_rank = self.rank as i8 + rank_offset;
        
        if Self::is_valid(new_file, new_rank) {
            Some(Position::new(new_file as u8, new_rank as u8))
        } else {
            None
        }
    }

    /// Calculates Manhattan distance to another position
    pub fn manhattan_distance(&self, other: &Position) -> u8 {
        ((self.file as i8 - other.file as i8).abs() + (self.rank as i8 - other.rank as i8).abs()) as u8
    }

    /// Calculates Chebyshev distance (king moves) to another position
    pub fn chebyshev_distance(&self, other: &Position) -> u8 {
        ((self.file as i8 - other.file as i8).abs().max((self.rank as i8 - other.rank as i8).abs())) as u8
    }
}

impl fmt::Display for Position {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{}", self.to_algebraic())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_color_opposite() {
        assert_eq!(Color::White.opposite(), Color::Black);
        assert_eq!(Color::Black.opposite(), Color::White);
    }

    #[test]
    fn test_position_algebraic() {
        let pos = Position::new(4, 3); // e4
        assert_eq!(pos.to_algebraic(), "e4");
        assert_eq!(Position::from_algebraic("e4"), Some(pos));
    }

    #[test]
    fn test_position_offset() {
        let e4 = Position::new(4, 3);
        assert_eq!(e4.offset(1, 1), Some(Position::new(5, 4))); // f5
        assert_eq!(e4.offset(-5, 0), None); // Off board
    }

    #[test]
    fn test_piece_material() {
        let queen = Piece::new(PieceType::Queen, Color::White);
        assert_eq!(queen.material_value(), 900);
    }
}
