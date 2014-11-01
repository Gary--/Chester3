#include "Game.h"
#include "attack_fields.h"

using namespace AttackFields;

bool Game::posAttackedByJump(Position position, Turn turn) {
	return (kingTargs(position) & getPieces(turn,Piece::KING)) != BitBoard::EMPTY() ||
			(knightTargs(position) & getPieces(turn, Piece::KNIGHT)) != BitBoard::EMPTY() ||
			(pawnTargs(position, !turn) & getPieces(turn, Piece::PAWN)) != BitBoard::EMPTY();
}

bool Game::posAttackedByLOS(Position position, Turn turn) {
	return (bishopTargs(position, ALL) & (getPieces(turn, Piece::BISHOP) | getPieces(turn, Piece::QUEEN))) != BitBoard::EMPTY() ||
		(rookTargs(position, ALL) & (getPieces(turn, Piece::ROOK) | getPieces(turn, Piece::QUEEN))) != BitBoard::EMPTY();
}

bool Game::posAttackedBy(Position position, Turn turn) {
	return posAttackedByJump(position, turn) || posAttackedByLOS(position, turn);
}

BitBoard Game::attackedByJump(Turn turn) {
	BitBoard res = BitBoard::EMPTY();
	res |= kingTargs(getPieces(turn, Piece::KING).ToPosition());

	BitBoard pawnsForward = getPieces(turn, Piece::PAWN).shiftForward(turn);
	res |= pawnsForward.shiftLeft() | pawnsForward.shiftRight();

	FOR_BIT(bit, getPieces(turn, Piece::KNIGHT)) {
		res |= knightTargs(bit.ToPosition());
	}
	return res;
}

