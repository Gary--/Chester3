#include "AttackFields.h"


BitBoard AttackFields::castleEmptySquares(const Turn turn, const  Side side) {
	const int r = turn.isWhite() ? 7 : 0;
	if (side==Side::LEFT){
		return Position(r, 1).asSingletonBitboard() |
			Position(r, 2).asSingletonBitboard() |
			Position(r, 3).asSingletonBitboard();
	}
	else {
		return Position(r, 5).asSingletonBitboard() |
			Position(r, 6).asSingletonBitboard();
	}
}


BitBoard AttackFields::castleSafeSquares(const Turn turn, const  Side side) {
	const int r = turn.isWhite() ? 7 : 0;
	if (side == Side::LEFT){
		return
			Position(r, 2).asSingletonBitboard() |
			Position(r, 3).asSingletonBitboard() |
			Position(r, 4).asSingletonBitboard();
	}
	else {
		return 
			Position(r, 4).asSingletonBitboard() |
			Position(r, 5).asSingletonBitboard() |
			Position(r, 6).asSingletonBitboard();
	}
}

