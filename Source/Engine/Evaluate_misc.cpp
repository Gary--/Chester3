#include "Evaluation.h"
#include "Game.h"
#include "AttackFields.h"

namespace {
	int bishopPairScore(const Turn turn) {
		const Turn other = !turn;
		const BitBoard MB = Game::getPieces(turn, Piece::BISHOP());

		int res = 0;
		// Bishop pair
		if ((BitBoard::WHITE_SQUARES() & MB).isNotEmpty() && (BitBoard::BLACK_SQUARES() & MB).isNotEmpty()) {

			//bonus based on number of pawns they have
			const char bishop_pair[] = { 50, 50, 50, 50, 38, 26, 32, 13, 4 };
			res += bishop_pair[Game::getPieces(other, Piece::PAWN()).count()];

			// bonus if they have no light pieces left
			if ((Game::getPieces(other, Piece::KNIGHT()) | Game::getPieces(other, Piece::BISHOP())).isEmpty()) {
				res += 25;
			}
		}
		return res;
	}




	
}

int Evaluation:: castlingRights(const Turn turn) {
	if (Game::getCanCastle(turn, Side::LEFT) && (Game::getCanCastle(turn, Side::RIGHT))) {
		return (int)(15 * (1-lateness()));
	}
	if (Game::getCanCastle(turn, Side::LEFT) || (Game::getCanCastle(turn, Side::RIGHT))) {
		return (int)(10 * (1 - lateness()));
	}

	return 0;
}

int Evaluation::misc(Turn turn) {
	int res = 0;
	res += bishopPairScore(turn);
	res += castlingRights(turn);
	return res;
}

int Evaluation::DEBUG_bishopPairScore(Turn turn) {
	return bishopPairScore(turn);
}