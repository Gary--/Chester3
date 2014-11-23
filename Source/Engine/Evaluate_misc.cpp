#include "Evaluation.h"
#include "Game.h"

int Evaluation::misc(Turn turn) {
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