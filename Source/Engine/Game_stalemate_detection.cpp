#include "Game.h"
#include "attack_fields.h"

using namespace AttackFields;

bool Game::isDefinitelyAMoveAvailable() {
	if (getCheck()) { // Should probably be dealing with the check..
		return false;
	}
	
	Position kingPos = getPieces(getTurn(), Piece::KING()).ToPosition();
	BitBoard kingSees = queenTargs(kingPos, ALL);
	

	BitBoard freePawnsForward = (getPieces(getTurn(), Piece::PAWN()) &~kingSees).shiftForward(getTurn());

	// A pawn can move forward
	if ((freePawnsForward&~ALL) != BitBoard::EMPTY()) {
		return true;
	}

	// A pawn can capture
	if (((freePawnsForward.shiftLeft() | freePawnsForward.shiftRight())
		&getPlayerPieces(!getTurn())) != BitBoard::EMPTY()) {
		return true;
	}

	BitBoard M = getPlayerPieces(getTurn());

	// A knight can move
	if ((knightTargs(getPieces(getTurn(), Piece::KNIGHT())&~kingSees)&~M)!=BitBoard::EMPTY()) {
		return true;
	}

	// A rook can move
	BitBoard MR = (getPieces(getTurn(), Piece::ROOK()) | getPieces(getTurn(), Piece::QUEEN()))&~kingSees;
	if (MR != BitBoard::EMPTY()) {
		if (((MR.shiftUp() | MR.shiftDown() | MR.shiftLeft() | MR.shiftRight())&~M) != BitBoard::EMPTY()) {
			return true;
		}
	}

	// A bishop can move
	BitBoard MB = (getPieces(getTurn(), Piece::BISHOP()) | getPieces(getTurn(), Piece::QUEEN()))&~kingSees;
	if (MB != BitBoard::EMPTY()) {
		BitBoard vert = MB.shiftUp() | MB.shiftDown();

		if (((vert.shiftLeft() | vert.shiftRight())&~M) != BitBoard::EMPTY()) {
			return true;
		}
	}
	return false;
}