#include "Game.h"

void Game::resign() {
	result = getTurn() == Turn::WHITE ? GameResult::BLACK_WIN : GameResult::WHITE_WIN;
}

void Game::makeMove(Move move) {
	if (move.type == MoveType::RESIGN) {
		return resign();
	}
}