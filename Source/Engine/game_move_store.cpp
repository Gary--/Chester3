#include "Game.h"

void Game::addMove(Move move) {
	moves.push_back(move);
	numMovesAvail++;
}

void Game::generateMoves() {
	if (numMovesAvail == -1) {
		numMovesAvail = 0;
		//if (curTurn == Turn::WHITE) {
			generateMovesImpl();
		//} else {
		//	generateMovesImpl_BLACK();
		//}
	}
}

int Game::getNumValidMoves() {
	Game::generateMoves();
	return numMovesAvail;
}
Move Game::getMove(int n) {
	_ASSERTE(0 <= n && n < getNumValidMoves());
	return moves[movePtr + n];
}