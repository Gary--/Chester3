#pragma once

#include "Position.h"
#include "BitBoard.h"

//NO FUNCTION AVAILABLE BEFORE MAIN
class AttackFields {
public:
	static void init();


	static BitBoard kingTargs(Position position);
	static BitBoard knightTargs(Position position);
	static BitBoard knightTargs(BitBoard knights);

	static BitBoard pawnTargs(Position position, Turn turn);
	static BitBoard bishopTargs(Position position, BitBoard blockers);
	static BitBoard rookTargs(Position position, BitBoard blockers);
	static BitBoard queenTargs(Position position, BitBoard blockers);

	// Given a pinned piece, where could it possibly move to.
	static BitBoard pinnedTargs(Position kingPos, Position pinnedPos);

	// If the kind is in check, where coul we move a piece to block?
	static BitBoard blockingTargs(Position kingPos, Position attackerPos);


	// These squares must not be occupied for the castle to happen.
	static BitBoard castleEmptySquares(Turn turn, Side side);

	// These squares must not be threatened for the castle to happen.
	static BitBoard castleSafeSquares(Turn turn, Side side);

	// If a pawn moves from here, it will be promoted
	static BitBoard pawnPromoZone(Turn turn);

	// If a pawn is here, it can move forward 2 squares.
	static BitBoard pawnJumpZone(Turn turn);

	// Where are pawn moves to when making an EP
	static Position enpeasentTo(Turn turn, int enpeasentColumn);

	// The position of the pawn that gets captured by EP
	static Position enpeasentCaptured(Turn turn, int enpeasentColumn);

private:
	static void initKingKnightPawn();
	static void initBishopRook();
	static void initBlockingPinning();
};

