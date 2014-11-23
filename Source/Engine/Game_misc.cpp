#include "Game.h"
#include "AttackFields.h"
bool Game::canEnpeasent(const Turn turn,const int column) {
	if (column == 8) {
		return false;
	}
	const Turn other = !turn;
	const Position to = AttackFields::enpeasentTo(turn, column);
	const BitBoard fromMid = to.shiftBackward(turn).asSingletonBitboard();
	const BitBoard capturedBit = AttackFields::enpeasentCaptured(turn, column).asSingletonBitboard();

	const BitBoard enpeasentFrom = fromMid.shiftLeft() | fromMid.shiftRight();
	FOR_BIT(pawn, getPieces(turn, Piece::PAWN()) & enpeasentFrom) {
		const Position theirKingPos = getPieces(turn, Piece::KING()).ToPosition();
		const BitBoard newBlockers = getAllPieces() ^ pawn^capturedBit^
			AttackFields::enpeasentTo(turn, column).asSingletonBitboard();
		const BitBoard diagProblems = (getPieces(other, Piece::QUEEN()) | getPieces(other, Piece::BISHOP()))&
			AttackFields::bishopTargs(theirKingPos, newBlockers);
		const BitBoard rightProblems = (getPieces(other, Piece::QUEEN()) | getPieces(other, Piece::ROOK()))&
			AttackFields::rookTargs(theirKingPos, newBlockers);

		if ((diagProblems | rightProblems).isEmpty()) {
			return true;
		}
	}

	return false;
}