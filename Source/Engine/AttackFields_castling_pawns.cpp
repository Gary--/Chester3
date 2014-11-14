#include "AttackFields.h"


BitBoard AttackFields::castleEmptySquares(Turn turn, Side side){
	int r = turn == Turn::WHITE() ? 7 : 0;
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


BitBoard AttackFields::castleSafeSquares(Turn turn, Side side){
	int r = turn == Turn::WHITE() ? 7 : 0;
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

// If a pawn moves from here, it will be promoted
BitBoard AttackFields::pawnPromoZone(Turn turn) {
	return BitBoard::rowBits(turn == Turn::WHITE() ? 1 : 6);
}

// If a pawn is here, it can move forward 2 squares.
BitBoard AttackFields::pawnJumpZone(Turn turn) {
	return pawnPromoZone(!turn);
}

Position AttackFields::enpeasentTo(Turn turn, int enpeasentColumn) {
	return Position(turn == Turn::WHITE() ? 2 : 5, enpeasentColumn);
}
Position AttackFields::enpeasentCaptured(Turn turn, int enpeasentColumn) {
	return Position(turn == Turn::WHITE() ? 3 : 4, enpeasentColumn);
}