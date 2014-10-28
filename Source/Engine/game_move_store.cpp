#include "Game.h"

void Game::addMove(Move move) {
	moves.push_back(move);
	numMovesAvail++;
}

int Game::getNumValidMoves() {
	if (numMovesAvail == -1) {
		numMovesAvail = 0;
		generateMoves();
	}
	return numMovesAvail;
}
Move Game::getMove(int n) {
	_ASSERTE(0 <= n && n < getNumValidMoves());
	return moves[movePtr + n];
}