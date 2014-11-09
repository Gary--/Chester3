#include "Evaluate_simple.h"
#include "Game.h"

namespace {
	int matScores[2] = { 0 };
	int posScores[2] = { 0 };

#pragma region PieceSqr tables
int pieceSquare[7][64] = {
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

    //{//KING
    //    -50,-40,-30,-20,-20,-30,-40,-50,
    //    -30,-20,-10,  0,  0,-10,-20,-30,
    //    -30,-10, 20, 30, 30, 20,-10,-30,
    //    -30,-10, 30, 40, 40, 30,-10,-30,
    //    -30,-10, 30, 40, 40, 30,-10,-30,
    //    -30,-10, 20, 30, 30, 20,-10,-30,
    //    -30,-30,  0,  0,  0,  0,-30,-30,
    //    -50,-30,-30,-30,-30,-30,-30,-50
    //}


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

}


int evaluateFull(Turn turn) {
	return evaluateMaterial(turn) + evaluatePosition(turn);
}
int evaluateMaterial(Turn turn) {
	return matScores[turn.asIndex()];
}
int evaluatePosition(Turn turn) {
	return posScores[turn.asIndex()];
}

void SimpleEvaluation::synchronize() {
	FOR_TURN(turn) {
		FOR_PIECE_ALL(piece) {
			matScores[turn.asIndex()] += Game::getPieces(turn, piece).count() * pieceValue(piece);

			FOR_BIT(bit, Game::getPieces(turn, piece)) {
				posScores[turn.asIndex()] += pieceSquare[piece.asIndex()][bit.ToPosition().index()];
			}
		}
	}
}

void SimpleEvaluation::notifyMove(Move move, Turn turn) {
	synchronize();
}

void SimpleEvaluation::notifyUndoMove(Move move, Turn turn) {
	synchronize();
}