//! Move validation and legal move generation

use crate::board::ChessBoard;
use crate::moves::{ChessMove, MoveFlags};
use crate::pieces::{Color, PieceType, Position};

pub struct MoveValidator<'a> {
    board: &'a ChessBoard,
    current_color: Color,
}

impl<'a> MoveValidator<'a> {
    pub fn new(board: &'a ChessBoard, current_color: Color) -> Self {
        Self {
            board,
            current_color,
        }
    }

    /// Checks if a move is legal
    pub fn is_legal_move(&self, chess_move: &ChessMove) -> Result<bool, String> {
        let piece = self.board.get_piece(&chess_move.from)
            .ok_or("No piece at source position")?;

        // Must move own piece
        if piece.color != self.current_color {
            return Ok(false);
        }

        // Cannot capture own piece
        if let Some(target) = self.board.get_piece(&chess_move.to) {
            if target.color == self.current_color {
                return Ok(false);
            }
        }

        // Validate piece-specific movement
        let is_pseudo_legal = match piece.piece_type {
            PieceType::Pawn => self.is_legal_pawn_move(chess_move, piece.color),
            PieceType::Knight => self.is_legal_knight_move(chess_move),
            PieceType::Bishop => self.is_legal_bishop_move(chess_move),
            PieceType::Rook => self.is_legal_rook_move(chess_move),
            PieceType::Queen => self.is_legal_queen_move(chess_move),
            PieceType::King => self.is_legal_king_move(chess_move, piece.color),
        };

        if !is_pseudo_legal {
            return Ok(false);
        }

        // TODO: Check if move leaves king in check (requires board cloning)
        Ok(true)
    }

    /// Generates all legal moves for the current player
    pub fn generate_all_legal_moves(&self) -> Vec<ChessMove> {
        let mut moves = Vec::new();

        for from_file in 0..8 {
            for from_rank in 0..8 {
                let from = Position::new(from_file, from_rank);
                if let Some(piece) = self.board.get_piece(&from) {
                    if piece.color == self.current_color {
                        moves.extend(self.generate_piece_moves(&from, &piece));
                    }
                }
            }
        }

        moves
    }

    fn generate_piece_moves(&self, from: &Position, _piece: &crate::pieces::Piece) -> Vec<ChessMove> {
        let mut moves = Vec::new();

        // Generate all possible destination squares based on piece type
        for to_file in 0..8 {
            for to_rank in 0..8 {
                let to = Position::new(to_file, to_rank);
                if from == &to {
                    continue;
                }

                // Try to construct a move
                let mut flags = MoveFlags::NONE;
                if self.board.get_piece(&to).is_some() {
                    flags |= MoveFlags::CAPTURE;
                }

                let chess_move = ChessMove::new(*from, to, flags);
                if self.is_legal_move(&chess_move).unwrap_or(false) {
                    moves.push(chess_move);
                }
            }
        }

        moves
    }

    pub fn is_king_in_check(&self) -> bool {
        // Find king position
        let king_pos = self.board.find_king(self.current_color);
        if king_pos.is_none() {
            return false;
        }
        let king_pos = king_pos.unwrap();

        // Check if any opponent piece attacks king
        for file in 0..8 {
            for rank in 0..8 {
                let pos = Position::new(file, rank);
                if let Some(piece) = self.board.get_piece(&pos) {
                    if piece.color != self.current_color {
                        let test_move = ChessMove::new(pos, king_pos, MoveFlags::CAPTURE);
                        // Create validator for opponent
                        let opponent_validator = MoveValidator::new(self.board, piece.color);
                        if opponent_validator.is_legal_move(&test_move).unwrap_or(false) {
                            return true;
                        }
                    }
                }
            }
        }

        false
    }

    fn is_legal_pawn_move(&self, chess_move: &ChessMove, color: Color) -> bool {
        let direction = color.pawn_direction() as i8;
        let file_diff = chess_move.to.file as i8 - chess_move.from.file as i8;
        let rank_diff = chess_move.to.rank as i8 - chess_move.from.rank as i8;

        // Forward move
        if file_diff == 0 {
            if rank_diff == direction && self.board.get_piece(&chess_move.to).is_none() {
                return true;
            }
            // Double push from starting position
            if rank_diff == 2 * direction
                && chess_move.from.rank == color.pawn_start_rank()
                && self.board.get_piece(&chess_move.to).is_none()
            {
                let intermediate = Position::new(
                    chess_move.from.file,
                    (chess_move.from.rank as i8 + direction) as u8,
                );
                if self.board.get_piece(&intermediate).is_none() {
                    return true;
                }
            }
        }

        // Capture
        if file_diff.abs() == 1 && rank_diff == direction {
            if self.board.get_piece(&chess_move.to).is_some() {
                return true;
            }
            // En passant
            if Some(chess_move.to) == self.board.en_passant_target() {
                return true;
            }
        }

        false
    }

    fn is_legal_knight_move(&self, chess_move: &ChessMove) -> bool {
        let file_diff = (chess_move.to.file as i8 - chess_move.from.file as i8).abs();
        let rank_diff = (chess_move.to.rank as i8 - chess_move.from.rank as i8).abs();
        (file_diff == 2 && rank_diff == 1) || (file_diff == 1 && rank_diff == 2)
    }

    fn is_legal_bishop_move(&self, chess_move: &ChessMove) -> bool {
        let file_diff = (chess_move.to.file as i8 - chess_move.from.file as i8).abs();
        let rank_diff = (chess_move.to.rank as i8 - chess_move.from.rank as i8).abs();
        
        if file_diff != rank_diff {
            return false;
        }

        self.is_path_clear(chess_move)
    }

    fn is_legal_rook_move(&self, chess_move: &ChessMove) -> bool {
        if chess_move.from.file != chess_move.to.file && chess_move.from.rank != chess_move.to.rank {
            return false;
        }

        self.is_path_clear(chess_move)
    }

    fn is_legal_queen_move(&self, chess_move: &ChessMove) -> bool {
        self.is_legal_bishop_move(chess_move) || self.is_legal_rook_move(chess_move)
    }

    fn is_legal_king_move(&self, chess_move: &ChessMove, color: Color) -> bool {
        let file_diff = (chess_move.to.file as i8 - chess_move.from.file as i8).abs();
        let rank_diff = (chess_move.to.rank as i8 - chess_move.from.rank as i8).abs();

        // Normal king move (one square)
        if file_diff <= 1 && rank_diff <= 1 {
            return true;
        }

        // Castling
        if file_diff == 2 && rank_diff == 0 {
            // Kingside castling
            if chess_move.to.file == 6 && self.board.can_castle_kingside(color) {
                return self.is_castling_legal(chess_move, true);
            }
            // Queenside castling
            if chess_move.to.file == 2 && self.board.can_castle_queenside(color) {
                return self.is_castling_legal(chess_move, false);
            }
        }

        false
    }

    fn is_path_clear(&self, chess_move: &ChessMove) -> bool {
        let file_step = (chess_move.to.file as i8 - chess_move.from.file as i8).signum();
        let rank_step = (chess_move.to.rank as i8 - chess_move.from.rank as i8).signum();

        let mut current_file = chess_move.from.file as i8 + file_step;
        let mut current_rank = chess_move.from.rank as i8 + rank_step;

        while current_file != chess_move.to.file as i8 || current_rank != chess_move.to.rank as i8 {
            let pos = Position::new(current_file as u8, current_rank as u8);
            if self.board.get_piece(&pos).is_some() {
                return false;
            }
            current_file += file_step;
            current_rank += rank_step;
        }

        true
    }

    fn is_castling_legal(&self, _chess_move: &ChessMove, _kingside: bool) -> bool {
        // TODO: Check that king and rook haven't moved, path is clear, and king doesn't pass through check
        true
    }
}
