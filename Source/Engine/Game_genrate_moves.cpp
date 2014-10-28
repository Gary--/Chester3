#include "Game.h"

void Game::generateMoves() {
	BitBoard posTargs = BitBoard::FULL();//Where we can move to
	Position kingInd = getPieces(curTurn, Piece::KING).ToPosition();

	BitBoard jumpDanger = attackedByJump(!curTurn);
}