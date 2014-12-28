#include "Game.h"
#include "AttackFields.h"


bool Game::isDefinitelyAMoveAvailable() {
	if (getCheck()) { // Should probably be dealing with the check..
		return false;
	}
	
	const Position kingPos = getKingPosition(getTurn());
	const BitBoard kingSees = AttackFields::queenTargs(kingPos, ALL);

	{
		const BitBoard freePawnsForward = (getPieces(getTurn(), Piece::PAWN()) &~kingSees).shiftForward(getTurn());

		// A pawn can move forward
		if ((freePawnsForward&~ALL).isNotEmpty()) {
			return true;
		}

		// A pawn can capture
		if (((freePawnsForward.shiftLeft() | freePawnsForward.shiftRight())
			&getPlayerPieces(!getTurn())).isNotEmpty()) {
			return true;
		}
	}

	const BitBoard M = getPlayerPieces(getTurn());

	// A knight can move
	if ((AttackFields::knightTargs(getPieces(getTurn(), Piece::KNIGHT())&~kingSees)&~M).isNotEmpty()) {
		return true;
	}

	{ // A rook can move
		const BitBoard MR = (getPieces(getTurn(), Piece::ROOK()) | getPieces(getTurn(), Piece::QUEEN()))&~kingSees;
		if (MR.isNotEmpty()) {
			if (((MR.shiftUp() | MR.shiftDown() | MR.shiftLeft() | MR.shiftRight())&~M).isNotEmpty()) {
				return true;
			}
		}
	}

	{// A bishop can move
		const BitBoard MB = (getPieces(getTurn(), Piece::BISHOP()) | getPieces(getTurn(), Piece::QUEEN()))&~kingSees;
		if (MB.isNotEmpty()) {
			BitBoard vert = MB.shiftUp() | MB.shiftDown();

			if (((vert.shiftLeft() | vert.shiftRight())&~M).isNotEmpty()) {
				return true;
			}
		}
	}
	return false;
}