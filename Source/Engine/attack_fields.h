#pragma once

#include "Position.h"
#include "BitBoard.h"

//NO FUNCTION AVAILABLE BEFORE MAIN
namespace AttackFields {
	void init();


	BitBoard kingTargs(Position position);
	BitBoard knightTargs(Position position);
	BitBoard pawnTargs(Position position,Turn turn);
	BitBoard bishopTargs(Position position, BitBoard blockers);
	BitBoard rookTargs(Position position, BitBoard blockers);
	BitBoard queenTargs(Position position, BitBoard blockers);

	// Given a pinned piece, where could it possibly move to.
	BitBoard pinnedTargs(Position kingPos, Position pinnedPos);

	// If the kind is in check, where coul we move a piece to block?
	BitBoard blockingTargs(Position kingPos, Position attackerPos);


	// These squares must not be occupied for the castle to happen.
	BitBoard castleEmptySquares(Turn turn, Side side);

	// These squares must not be threatened for the castle to happen.
	BitBoard castleSafeSquares(Turn turn, Side side);

	// If a pawn moves from here, it will be promoted
	BitBoard pawnPromoZone(Turn turn);

	// If a pawn is here, it can move forward 2 squares.
	BitBoard pawnJumpZone(Turn turn);
}

