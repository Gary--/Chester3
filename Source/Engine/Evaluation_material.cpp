#include "Evaluation.h"
#include "Game.h"


namespace {
	int matScores[2] = { 0 };

	int pieceValue(Piece piece) {
		switch (piece.asEnum()) {
		case PieceEnum::EMPTY:
			return 0;
		case PieceEnum::PAWN:
			return 100;
		case PieceEnum::KNIGHT:
			return 320;
		case PieceEnum::BISHOP:
			return 330;
		case PieceEnum::ROOK:
			return 500;
		case PieceEnum::QUEEN:
			return 900;
		default:
			return 0;
		}
	}

	int totalInitialMaterial() {
		return 8 * pieceValue(Piece::PAWN()) +
			2 * pieceValue(Piece::KNIGHT()) +
			2 * pieceValue(Piece::BISHOP()) +
			2 * pieceValue(Piece::ROOK()) +
			1 * pieceValue(Piece::QUEEN());
	}

	// fraction of material that remaining
	double materialLeft(Turn turn) {
		return Evaluation::material(turn) / (double)totalInitialMaterial();
	}



	// factor is +1/-1 for make/unmake
	void adjustScores(Move move, Turn turn, int factor) {
		const Turn other = !turn;
		const Position from = move.getFrom().perspective(turn);
		const Position to = move.getTo().perspective(turn);

		// Capturing a piece
		matScores[other.asIndex()] -= factor*pieceValue(move.getTarg());

		// Additional adjustments for special moves
		if (move.isPromotion()) {
			Piece promo = move.promotionPiece();
			matScores[turn.asIndex()] += factor*(pieceValue(promo) - pieceValue(Piece::PAWN()));
		} else if (move.getType() == MoveType::ENPEASENT) {
			matScores[other.asIndex()] -= factor*pieceValue(Piece::PAWN());

		}
	}
}



int Evaluation::material(Turn turn) {
	return matScores[turn.asIndex()];
}


void Evaluation::synchronizeMaterial() {
	FOR_TURN(turn) {
		matScores[turn.asIndex()] = 0;

		FOR_PIECE_ALL(piece) {
			matScores[turn.asIndex()] += Game::getPieces(turn, piece).count() * pieceValue(piece);
		}
	}
}

void Evaluation::notifyMoveMaterial(Move move, Turn turn) {
	adjustScores(move, turn, +1);
}

void Evaluation::notifyUndoMoveMaterial(Move move, Turn turn) {
	adjustScores(move, turn, -1);
}



int Evaluation::materialBalance() {
	double w = material(Turn::WHITE());
	double b = material(Turn::BLACK());

	double matGone = 1.0 - (w + b) / totalInitialMaterial() / 2.0;
	
	const double tradeBonusFact = 0.2;

	return (w - b)*(1.0 + matGone*tradeBonusFact);
}