#include "attack_fields.h"


BitBoard AttackFields::castleEmptySquares(Turn turn, Side side){
	int r = turn == Turn::WHITE ? 7 : 0;
	if (side==Side::LEFT){
		return Position(r, 1).ToSingletonBoard() |
			Position(r, 2).ToSingletonBoard() |
			Position(r, 3).ToSingletonBoard();
	}
	else {
		return Position(r, 5).ToSingletonBoard() |
			Position(r, 6).ToSingletonBoard();
	}
}


BitBoard AttackFields::castleSafeSquares(Turn turn, Side side){
	int r = turn == Turn::WHITE ? 7 : 0;
	if (side == Side::LEFT){
		return
			Position(r, 2).ToSingletonBoard() |
			Position(r, 3).ToSingletonBoard() |
			Position(r, 4).ToSingletonBoard();
	}
	else {
		return 
			Position(r, 4).ToSingletonBoard() |
			Position(r, 5).ToSingletonBoard() |
			Position(r, 6).ToSingletonBoard();
	}
}