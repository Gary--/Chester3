#include "Evaluation.h"
#include "BitBoard.h"


namespace {
	BitBoard opposingPawnsArr[2][64];
}


void Evaluation::initPawns() {

	FOR_TURN(turn) {
		FOR_POSITION_64(pos) {
			BitBoard result = BitBoard::EMPTY();
			FOR_BIT(bit, pos.shiftLeft().asSingletonBitboard() |
					pos.asSingletonBitboard() |
					pos.shiftRight().asSingletonBitboard()) {
				result |= BitBoard::colBits(bit.ToPosition().col());
			}
			result &= pos.squaresForward(turn);
			opposingPawnsArr[turn.asIndex()][pos.index()] = result;
		}
	}
}

BitBoard Evaluation::opposingPawns(Position position, Turn turn) {
	return opposingPawnsArr[turn.asIndex()][position.index()];
}