#pragma once

#include "Position.h"
#include "BitBoard.h"

class AttackFields {
public:
	static void init();

	// The squares a king attacks from the given position.
	static BitBoard kingTargs(Position position);

	// The squares a knight attacks from the given position.
	static BitBoard knightTargs(Position position);

	// The squares the given knights can attack.
	static BitBoard knightTargs(BitBoard knights);

	// The squares a pawn owned by turn at position can attack.
	static BitBoard pawnTargs(Position position, Turn turn);

	// The squares the pawns owned by turn can attack.
	static BitBoard pawnTargs(BitBoard pawns, Turn turn);

	// The squares a bishop could attack given the blocking pieces.
	static BitBoard bishopTargs(Position position, BitBoard blockers);

	// The squares a rook could attack given the blocking pieces.
	static BitBoard rookTargs(Position position, BitBoard blockers);

	// The squares a queen could attack given the blocking pieces.
	static BitBoard queenTargs(Position position, BitBoard blockers);

	// Given a pinned piece, where could it possibly move to.
	static BitBoard pinnedTargs(Position kingPos, Position pinnedPos);

	// If the kind is in check, where could we move a piece to block?
	// Does not include kingPos or attackerPos
	static BitBoard blockingTargs(Position kingPos, Position attackerPos);


	// These squares must not be occupied for the castle to happen.
	static BitBoard castleEmptySquares(Turn turn, Side side);

	// These squares must not be threatened for the castle to happen.
	static BitBoard castleSafeSquares(Turn turn, Side side);

	// If a pawn moves from here, it will be promoted
	static BitBoard pawnPromoZone(Turn turn);

	// If a pawn is here, it can move forward 2 squares.
	static BitBoard pawnJumpZone(Turn turn);

	// The non-pawn pieces start here.
	static BitBoard backRow(Turn turn);

	// Where are pawn moves to when making an EP
	static Position enpeasentTo(Turn turn, int enpeasentColumn);

	// The position of the pawn that gets captured by EP
	static Position enpeasentCaptured(Turn turn, int enpeasentColumn);

private:
	static void initKingKnightPawn();
	static void initBishopRook();
	static void initBlockingPinning();
};

