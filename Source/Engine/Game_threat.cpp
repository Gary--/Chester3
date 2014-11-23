#include "Game.h"
#include "AttackFields.h"



bool Game::posAttackedByJump(const Position position, const Turn turn) {
	return (AttackFields::kingTargs(position) & getPieces(turn, Piece::KING())).isNotEmpty() ||
		(AttackFields::knightTargs(position) & getPieces(turn, Piece::KNIGHT())).isNotEmpty() ||
		(AttackFields::pawnTargs(position, !turn) & getPieces(turn, Piece::PAWN())).isNotEmpty();
}

bool Game::posAttackedByLOS(const Position position, const Turn turn) {
	return (AttackFields::bishopTargs(position, ALL) & (getPieces(turn, Piece::BISHOP()) | getPieces(turn, Piece::QUEEN()))).isNotEmpty() ||
		(AttackFields::rookTargs(position, ALL) & (getPieces(turn, Piece::ROOK()) | getPieces(turn, Piece::QUEEN()))).isNotEmpty();
}

bool Game::posAttackedBy(const Position position, const Turn turn) {
	return posAttackedByJump(position, turn) || posAttackedByLOS(position, turn);
}

BitBoard Game::attackedByJump(const Turn turn) {
	BitBoard res = BitBoard::EMPTY();
	res |= AttackFields::kingTargs(getPieces(turn, Piece::KING()).ToPosition());

	res |= AttackFields::pawnTargs(getPieces(turn, Piece::PAWN()), turn);

	res |= AttackFields::knightTargs(getPieces(turn, Piece::KNIGHT()));
	return res;
}

