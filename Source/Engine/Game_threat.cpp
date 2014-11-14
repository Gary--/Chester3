#include "Game.h"
#include "AttackFields.h"



bool Game::posAttackedByJump(Position position, Turn turn) {
	return (AttackFields::kingTargs(position) & getPieces(turn, Piece::KING())) != BitBoard::EMPTY() ||
		(AttackFields::knightTargs(position) & getPieces(turn, Piece::KNIGHT())) != BitBoard::EMPTY() ||
		(AttackFields::pawnTargs(position, !turn) & getPieces(turn, Piece::PAWN())) != BitBoard::EMPTY();
}

bool Game::posAttackedByLOS(Position position, Turn turn) {
	return (AttackFields::bishopTargs(position, ALL) & (getPieces(turn, Piece::BISHOP()) | getPieces(turn, Piece::QUEEN()))) != BitBoard::EMPTY() ||
		(AttackFields::rookTargs(position, ALL) & (getPieces(turn, Piece::ROOK()) | getPieces(turn, Piece::QUEEN()))) != BitBoard::EMPTY();
}

bool Game::posAttackedBy(Position position, Turn turn) {
	return posAttackedByJump(position, turn) || posAttackedByLOS(position, turn);
}

BitBoard Game::attackedByJump(Turn turn) {
	BitBoard res = BitBoard::EMPTY();
	res |= AttackFields::kingTargs(getPieces(turn, Piece::KING()).ToPosition());

	BitBoard pawnsForward = getPieces(turn, Piece::PAWN()).shiftForward(turn);
	res |= pawnsForward.shiftLeft() | pawnsForward.shiftRight();

	res |= AttackFields::knightTargs(getPieces(turn, Piece::KNIGHT()));
	return res;
}

