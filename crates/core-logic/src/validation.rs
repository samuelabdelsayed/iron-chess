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

        // Check if move leaves king in check
        // Clone the board and test the move
        let mut test_board = self.board.clone();
        test_board.apply_move(chess_move);
        
        // Find king position after the move
        let king_pos = test_board.find_king(self.current_color);
        if king_pos.is_none() {
            // King was captured - this move is illegal
            return Ok(false);
        }
        
        // Check if king is under attack after the move
        let king_pos = king_pos.unwrap();
        if self.is_square_attacked_on_board(&test_board, king_pos, self.current_color) {
            return Ok(false);
        }

        Ok(true)
    }

    /// Generates all legal moves for the current player
    pub fn generate_all_legal_moves(&self) -> Vec<ChessMove> {
        let mut moves = Vec::new();
        let mut piece_count = 0;

        for from_file in 0..8 {
            for from_rank in 0..8 {
                let from = Position::new(from_file, from_rank);
                if let Some(piece) = self.board.get_piece(&from) {
                    if piece.color == self.current_color {
                        piece_count += 1;
                        let piece_moves = self.generate_piece_moves(&from, &piece);
                        if !piece_moves.is_empty() {
                            eprintln!("  {:?} at {:?}: {} moves", piece.piece_type, from, piece_moves.len());
                        }
                        moves.extend(piece_moves);
                    }
                }
            }
        }

        eprintln!("📊 Generated {} legal moves from {} pieces for {:?}", moves.len(), piece_count, self.current_color);
        moves
    }

    fn generate_piece_moves(&self, from: &Position, piece: &crate::pieces::Piece) -> Vec<ChessMove> {
        let mut moves = Vec::new();

        // Special handling for king castling moves
        if piece.piece_type == PieceType::King {
            // Add kingside castling (King d->f, King on d-file)
            if self.board.can_castle_kingside(piece.color) {
                let to = Position::new(5, from.rank);
                let castle_move = ChessMove::new(*from, to, MoveFlags::CASTLING_KINGSIDE);
                if self.is_legal_move(&castle_move).unwrap_or(false) {
                    moves.push(castle_move);
                }
            }
            // Add queenside castling (King d->b, King on d-file)
            if self.board.can_castle_queenside(piece.color) {
                let to = Position::new(1, from.rank);
                let castle_move = ChessMove::new(*from, to, MoveFlags::CASTLING_QUEENSIDE);
                if self.is_legal_move(&castle_move).unwrap_or(false) {
                    moves.push(castle_move);
                }
            }
        }

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

        // Castling: King on d-file (3) can castle kingside to f (5) = 2 squares, or queenside to b (1) = 2 squares
        if rank_diff == 0 {
            // Kingside castling (d->f, 2 squares)
            if file_diff == 2 && chess_move.to.file == 5 && self.board.can_castle_kingside(color) {
                return self.is_castling_legal(chess_move, true);
            }
            // Queenside castling (d->b, 2 squares)
            if file_diff == 2 && chess_move.to.file == 1 && self.board.can_castle_queenside(color) {
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

    fn is_castling_legal(&self, chess_move: &ChessMove, kingside: bool) -> bool {
        let color = self.board.get_piece(&chess_move.from).unwrap().color;
        let rank = chess_move.from.rank;
        
        // Check that the king is not currently in check
        if self.is_in_check(color) {
            return false;
        }
        
        if kingside {
            // Check that the rook is still at its starting position (h file = 7)
            let rook_pos = Position::new(7, rank);
            match self.board.get_piece(&rook_pos) {
                Some(piece) if piece.piece_type == PieceType::Rook && piece.color == color => {},
                _ => return false, // No rook found or wrong piece
            }
            
            // King on d-file (3), castles to f-file (5)
            // Check squares between king and rook are empty (e, f files = 4,5)
            for file in 4..6 {
                if self.board.get_piece(&Position::new(file, rank)).is_some() {
                    return false;
                }
            }
            
            // Check king doesn't move through or into check
            // King moves from d(3) -> e(4) -> f(5), so check files 3,4,5
            for file in 3..=5 {
                let test_pos = Position::new(file, rank);
                if self.is_square_attacked(test_pos, color) {
                    return false;
                }
            }
        } else {
            // Check that the rook is still at its starting position (a file = 0)
            let rook_pos = Position::new(0, rank);
            match self.board.get_piece(&rook_pos) {
                Some(piece) if piece.piece_type == PieceType::Rook && piece.color == color => {},
                _ => return false, // No rook found or wrong piece
            }
            
            // King on d-file (3), castles to b-file (1)
            // Queenside: Check squares between king and rook are empty (b, c files = 1,2)
            for file in 1..3 {
                if self.board.get_piece(&Position::new(file, rank)).is_some() {
                    return false;
                }
            }
            
            // Check king doesn't move through or into check
            // King moves from d(3) -> c(2) -> b(1), so check files 3,2,1
            for file in 1..=3 {
                let test_pos = Position::new(file, rank);
                if self.is_square_attacked(test_pos, color) {
                    return false;
                }
            }
        }
        
        true
    }

    /// Helper method to check if the given color's king is in check
    fn is_in_check(&self, color: Color) -> bool {
        let king_pos = match self.board.find_king(color) {
            Some(pos) => pos,
            None => return false,
        };
        self.is_square_attacked(king_pos, color)
    }

    /// Helper method to check if a square is attacked by the opponent
    fn is_square_attacked(&self, position: Position, defender_color: Color) -> bool {
        let attacker_color = defender_color.opposite();
        
        // Check all opponent pieces to see if any attack this square
        for file in 0..8 {
            for rank in 0..8 {
                let from = Position::new(file, rank);
                if let Some(piece) = self.board.get_piece(&from) {
                    if piece.color == attacker_color {
                        // Check if this piece can attack the target square
                        let test_move = ChessMove::new(from, position, MoveFlags::NONE);
                        
                        // Use basic movement validation (ignoring check since we're testing for check)
                        let can_attack = match piece.piece_type {
                            PieceType::Pawn => {
                                // Pawns attack diagonally
                                let file_diff = (position.file as i8 - from.file as i8).abs();
                                let rank_diff = position.rank as i8 - from.rank as i8;
                                let direction = attacker_color.pawn_direction() as i8;
                                file_diff == 1 && rank_diff == direction
                            }
                            PieceType::Knight => self.is_legal_knight_move(&test_move),
                            PieceType::Bishop => self.is_legal_bishop_move(&test_move),
                            PieceType::Rook => self.is_legal_rook_move(&test_move),
                            PieceType::Queen => self.is_legal_queen_move(&test_move),
                            PieceType::King => {
                                let file_diff = (position.file as i8 - from.file as i8).abs();
                                let rank_diff = (position.rank as i8 - from.rank as i8).abs();
                                file_diff <= 1 && rank_diff <= 1
                            }
                        };
                        
                        if can_attack {
                            return true;
                        }
                    }
                }
            }
        }
        
        false
    }

    /// Helper method to check if a square is attacked on a specific board state
    fn is_square_attacked_on_board(&self, board: &ChessBoard, position: Position, defender_color: Color) -> bool {
        let attacker_color = defender_color.opposite();
        
        // Check all opponent pieces to see if any attack this square
        for file in 0..8 {
            for rank in 0..8 {
                let from = Position::new(file, rank);
                if let Some(piece) = board.get_piece(&from) {
                    if piece.color == attacker_color {
                        // Check if this piece can attack the target square
                        let test_move = ChessMove::new(from, position, MoveFlags::NONE);
                        
                        // Create a temporary validator for this board state
                        let temp_validator = MoveValidator::new(board, attacker_color);
                        
                        // Use basic movement validation
                        let can_attack = match piece.piece_type {
                            PieceType::Pawn => {
                                // Pawns attack diagonally
                                let file_diff = (position.file as i8 - from.file as i8).abs();
                                let rank_diff = position.rank as i8 - from.rank as i8;
                                let direction = attacker_color.pawn_direction() as i8;
                                file_diff == 1 && rank_diff == direction
                            }
                            PieceType::Knight => temp_validator.is_legal_knight_move(&test_move),
                            PieceType::Bishop => temp_validator.is_legal_bishop_move(&test_move),
                            PieceType::Rook => temp_validator.is_legal_rook_move(&test_move),
                            PieceType::Queen => temp_validator.is_legal_queen_move(&test_move),
                            PieceType::King => {
                                let file_diff = (position.file as i8 - from.file as i8).abs();
                                let rank_diff = (position.rank as i8 - from.rank as i8).abs();
                                file_diff <= 1 && rank_diff <= 1
                            }
                        };
                        
                        if can_attack {
                            return true;
                        }
                    }
                }
            }
        }
        
        false
    }
}
