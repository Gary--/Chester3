#include "Evaluate_simple.h"
#include "Game.h"
#include "attack_fields.h"

#include <cstdint>
namespace {
	int matScores[2] = { 0 };
	int posScores[2] = { 0 };

#pragma region PieceSqr tables
int8_t pieceSquare[7][64] = {
		{},
    {//PAWN
         0,  0,  0,  0,  0,  0,  0,  0,
        50, 50, 50, 50, 50, 50, 50, 50,
        10, 10, 20, 30, 30, 20, 10, 10,
         5,  5, 10, 25, 25, 10,  5,  5,
         0,  0,  0, 20, 20,  0,  0,  0,
         5, -5,-10,  0,  0,-10, -5,  5,
         5, 10, 10,-20,-20, 10, 10,  5,
         0,  0,  0,  0,  0,  0,  0,  0
    },

    {//KNIGHT
        -50,-40,-30,-30,-30,-30,-40,-50,
        -40,-20,  0,  0,  0,  0,-20,-40,
        -30,  0, 10, 15, 15, 10,  0,-30,
        -30,  5, 15, 20, 20, 15,  5,-30,
        -30,  0, 15, 20, 20, 15,  0,-30,
        -30,  5, 10, 15, 15, 10,  5,-30,
        -40,-20,  0,  5,  5,  0,-20,-40,
        -50,-40,-30,-30,-30,-30,-40,-50,
    },

    {//BISHOP
        -20,-10,-10,-10,-10,-10,-10,-20,
        -10,  0,  0,  0,  0,  0,  0,-10,
        -10,  0,  5, 10, 10,  5,  0,-10,
        -10,  5,  5, 10, 10,  5,  5,-10,
        -10,  0, 10, 10, 10, 10,  0,-10,
        -10, 10, 10, 10, 10, 10, 10,-10,
        -10,  5,  0,  0,  0,  0,  5,-10,
        -20,-10,-10,-10,-10,-10,-10,-20,
    },

    {//ROOK
         0,  0,  0,  0,  0,  0,  0,  0,
          5, 10, 10, 10, 10, 10, 10,  5,
         -5,  0,  0,  0,  0,  0,  0, -5,
         -5,  0,  0,  0,  0,  0,  0, -5,
         -5,  0,  0,  0,  0,  0,  0, -5,
         -5,  0,  0,  0,  0,  0,  0, -5,
         -5,  0,  0,  0,  0,  0,  0, -5,
          0,  0,  0, 15, 15,  0,  0,  0
    },

    {//QUEEN
        -20,-10,-10, -5, -5,-10,-10,-20,
        -10,  0,  0,  0,  0,  0,  0,-10,
        -10,  0,  5,  5,  5,  5,  0,-10,
         -5,  0,  5,  5,  5,  5,  0, -5,
          0,  0,  5,  5,  5,  5,  0, -5,
        -10,  5,  5,  5,  5,  5,  0,-10,
        -10,  0,  5,  0,  0,  0,  0,-10,
        -20,-10,-10, -5, -5,-10,-10,-20
	} };

	int8_t kingEarlygame[64] = {
		-30,-40,-40,-50,-50,-40,-40,-30,
		-30,-40,-40,-50,-50,-40,-40,-30,
		-30,-40,-40,-50,-50,-40,-40,-30,
		-30,-40,-40,-50,-50,-40,-40,-30,
		-20,-30,-30,-40,-40,-30,-30,-20,
		-10,-20,-20,-20,-20,-20,-20,-10,
		 20, 20,  0,-10,-10,-10, 20, 20,
		 20, 30, 20,-10,  0,-10, 30, 20
	};

    int8_t kingLateGame[64] = {//KING
        -50,-40,-30,-20,-20,-30,-40,-50,
        -30,-20,-10,  0,  0,-10,-20,-30,
        -30,-10, 20, 30, 30, 20,-10,-30,
        -30,-10, 30, 40, 40, 30,-10,-30,
        -30,-10, 30, 40, 40, 30,-10,-30,
        -30,-10, 20, 30, 30, 20,-10,-30,
        -30,-30,  0,  0,  0,  0,-30,-30,
        -50,-30,-30,-30,-30,-30,-30,-50
    };




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

	// fraction of material that is gone.
	double materialLeft(Turn turn) {
		return SimpleEvaluation::evaluateMaterial(turn) / 4800.0;
	}


	
	int getPieceSquare(Piece piece, Position pos) {
		return pieceSquare[piece.asIndex()][pos.index()];
	}

	// factor is +1/-1 for make/unmake
	void adjustScores(Move move, Turn turn,int factor) {
		const Turn other = !turn;
		const Position from = move.getFrom().perspective(turn);
		const Position to = move.getTo().perspective(turn);

		// Our piece moving
		posScores[turn.asIndex()] += factor*(
			getPieceSquare(move.getPiece(), to) - getPieceSquare(move.getPiece(), from));

		// Capturing a piece
		matScores[other.asIndex()] -= factor*pieceValue(move.getTarg());
		posScores[other.asIndex()] -= factor*getPieceSquare(move.getTarg(), to.mirror());;

		// Additional adjustments for special moves
		if (move.isPromotion()) {
			Piece promo = move.promotionPiece();
			matScores[turn.asIndex()] += factor*(pieceValue(promo) - pieceValue(Piece::PAWN()));
			posScores[turn.asIndex()] += factor*getPieceSquare(promo, to);//Pawn end row is 0

		} else if (move.getType() == MoveType::ENPEASENT) {
			matScores[other.asIndex()] -= factor*pieceValue(Piece::PAWN());

			// Assume WLOG that we are white
			int column = to.col();
			Position capturedPos = AttackFields::enpeasentCaptured(Turn::BLACK(),column);
			posScores[other.asIndex()] -= factor*getPieceSquare(Piece::PAWN(), capturedPos);

		} else if (move.getType() == MoveType::CASTLE_LEFT || move.getType() == MoveType::CASTLE_RIGHT) {
			// Assume WLOG that we are white
			Position rookFrom(7, (move.getType() == MoveType::CASTLE_LEFT) ? 0 : 7);
			Position rookTo(7, (move.getType() == MoveType::CASTLE_LEFT) ? 3 : 5);
			posScores[turn.asIndex()] += factor*
				(getPieceSquare(Piece::ROOK(), rookTo) - getPieceSquare(Piece::ROOK(), rookFrom));
		}
	}
}

int SimpleEvaluation::evaluate() {
	return evaluateFull(Game::getTurn()) - evaluateFull(!Game::getTurn());
}

int SimpleEvaluation::evaluateFull(Turn turn) {
	return evaluateMaterial(turn) + evaluatePosition(turn);
}
int SimpleEvaluation::evaluateMaterial(Turn turn) {
	return matScores[turn.asIndex()];
}
int SimpleEvaluation::evaluatePosition(Turn turn) {
	double earliness = materialLeft(!turn);

	Position kingPos = Game::getPieces(turn, Piece::KING()).ToPosition();
#pragma warning (disable: 4244)//Double to int
	int kingPosValue = earliness*kingEarlygame[kingPos.perspective(turn).index()] +
		(1 - earliness)*kingLateGame[kingPos.perspective(turn).index()];
#pragma warning (default:4244)

	return posScores[turn.asIndex()] + kingPosValue;
}

void SimpleEvaluation::synchronize() {
	FOR_TURN(turn) {
		matScores[turn.asIndex()] = 0;
		posScores[turn.asIndex()] = 0;

		FOR_PIECE_ALL(piece) {
			matScores[turn.asIndex()] += Game::getPieces(turn, piece).count() * pieceValue(piece);

			FOR_BIT(bit, Game::getPieces(turn, piece)) {
				posScores[turn.asIndex()] += getPieceSquare(piece, bit.ToPosition().perspective(turn));
			}
		}
	}
}

void SimpleEvaluation::notifyMove(Move move, Turn turn) {
	adjustScores(move, turn, +1);
}

void SimpleEvaluation::notifyUndoMove(Move move, Turn turn) {
	adjustScores(move, turn, -1);
}