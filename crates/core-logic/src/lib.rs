//! # Core Chess Logic
//! 
//! Pure chess rules implementation with zero external dependencies.
//! This module provides the foundational chess engine that validates moves,
//! detects check/checkmate, and maintains game state.
//!
//! ## Design Philosophy
//! - No rendering dependencies - pure logic
//! - Immutable where possible for replay safety
//! - Comprehensive move validation
//! - Support for all chess rules including special moves

pub mod board;
pub mod moves;
pub mod pieces;
pub mod validation;

pub use board::{ChessBoard, GamePhase, GameResult};
pub use moves::{ChessMove, MoveFlags, MoveHistory};
pub use pieces::{Color, Piece, PieceType, Position};
pub use validation::MoveValidator;

/// Represents the complete state of a chess game
#[derive(Debug, Clone, serde::Serialize, serde::Deserialize)]
pub struct GameState {
    pub board: ChessBoard,
    pub current_turn: Color,
    pub move_history: MoveHistory,
    pub halfmove_clock: u32,
    pub fullmove_number: u32,
    pub phase: GamePhase,
}

impl GameState {
    /// Creates a new game with standard starting position
    pub fn new() -> Self {
        Self {
            board: ChessBoard::standard_starting_position(),
            current_turn: Color::White,
            move_history: MoveHistory::new(),
            halfmove_clock: 0,
            fullmove_number: 1,
            phase: GamePhase::Opening,
        }
    }

    /// Attempts to make a move, returning true if successful
    pub fn make_move(&mut self, chess_move: ChessMove) -> Result<(), String> {
        // Validate move legality
        let validator = MoveValidator::new(&self.board, self.current_turn);
        if !validator.is_legal_move(&chess_move)? {
            return Err("Illegal move".to_string());
        }

        // Execute the move
        self.board.apply_move(&chess_move);
        self.move_history.push(chess_move);

        // Update clocks
        if chess_move.is_capture() || matches!(self.board.get_piece(&chess_move.from), Some(p) if p.piece_type == PieceType::Pawn) {
            self.halfmove_clock = 0;
        } else {
            self.halfmove_clock += 1;
        }

        // Switch turns
        self.current_turn = self.current_turn.opposite();
        if self.current_turn == Color::White {
            self.fullmove_number += 1;
        }

        // Update game phase based on material
        self.update_phase();

        Ok(())
    }

    /// Generates all legal moves for the current player
    pub fn legal_moves(&self) -> Vec<ChessMove> {
        let validator = MoveValidator::new(&self.board, self.current_turn);
        validator.generate_all_legal_moves()
    }

    /// Checks if the current player is in check
    pub fn is_in_check(&self) -> bool {
        let validator = MoveValidator::new(&self.board, self.current_turn);
        validator.is_king_in_check()
    }

    /// Checks if the game is over (checkmate or stalemate)
    pub fn is_game_over(&self) -> Option<GameResult> {
        let legal_moves = self.legal_moves();
        
        if legal_moves.is_empty() {
            if self.is_in_check() {
                return Some(GameResult::Checkmate(self.current_turn.opposite()));
            } else {
                return Some(GameResult::Stalemate);
            }
        }

        // Check for fifty-move rule
        if self.halfmove_clock >= 100 {
            return Some(GameResult::Draw("Fifty-move rule".to_string()));
        }

        // Check for insufficient material
        if self.board.has_insufficient_material() {
            return Some(GameResult::Draw("Insufficient material".to_string()));
        }

        None
    }

    fn update_phase(&mut self) {
        let material_count = self.board.count_material();
        self.phase = match material_count {
            0..=16 => GamePhase::Endgame,
            17..=24 => GamePhase::Middlegame,
            _ => GamePhase::Opening,
        };
    }
}

impl Default for GameState {
    fn default() -> Self {
        Self::new()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_initial_position() {
        let game = GameState::new();
        assert_eq!(game.current_turn, Color::White);
        assert_eq!(game.fullmove_number, 1);
        assert_eq!(game.phase, GamePhase::Opening);
    }

    #[test]
    fn test_pawn_move() {
        let mut game = GameState::new();
        let pawn_move = ChessMove::new(
            Position::new(4, 1), // e2
            Position::new(4, 3), // e4
            MoveFlags::DOUBLE_PAWN_PUSH,
        );
        
        assert!(game.make_move(pawn_move).is_ok());
        assert_eq!(game.current_turn, Color::Black);
    }

    #[test]
    fn test_illegal_move_rejected() {
        let mut game = GameState::new();
        // Try to move a knight illegally
        let illegal_move = ChessMove::new(
            Position::new(1, 0), // b1 knight
            Position::new(1, 3), // b4 (illegal for knight from start)
            MoveFlags::NONE,
        );
        
        assert!(game.make_move(illegal_move).is_err());
    }
}
