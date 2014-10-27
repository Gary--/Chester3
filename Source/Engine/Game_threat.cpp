#include "Game.h"
#include "attack_fields.h"

using namespace AttackFields;

bool Game::posAttackedByJump(Position position, Turn turn) {
	return (kingTargs(position) & *s(turn, Piece::KING)) != BitBoard::EMPTY() ||
		(knightTargs(position) & *s(turn, Piece::KNIGHT)) != BitBoard::EMPTY() ||
		(pawnTargs(position, turn) & *s(turn, Piece::PAWN)) != BitBoard::EMPTY();
}

bool Game::posAttackedByLOS(Position position, Turn turn) {
	return (bishopTargs(position, ALL) & (*s(turn, Piece::BISHOP) | *s(turn, Piece::QUEEN))) != BitBoard::EMPTY() ||
			(rookTargs(position, ALL) & (*s(turn, Piece::ROOK) | *s(turn, Piece::QUEEN))) != BitBoard::EMPTY();
}

bool Game::posAttackedBy(Position position, Turn turn) {
	return posAttackedByJump(position, turn) || posAttackedByLOS(position, turn);
}