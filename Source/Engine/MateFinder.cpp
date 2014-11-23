#include "MateFinder.h"
#include "Game.h"

namespace {
	bool canEscape(int depth);

	// 1 for mate 0 otherwise
	Move findMatingMoveImpl(const int depth) {
		
		for (Move move : Game::getAllMoves()) {
			Game::makeMove(move);
			const bool escape = canEscape(depth);
			Game::undoMove();
			if (!escape) {
				return move;
			}
		}

		return Move::NULL_MOVE();
	}

	bool canEscape(const int depth) {
		if (depth == 1) {
			return !(Game::getCheck() && !Game::areMovesAvailable());
		}

		for (Move move : Game::getAllMoves()) {
			Game::makeMove(move);
			const Move matingMove = findMatingMoveImpl(depth - 1);
			Game::undoMove();
			if (matingMove == Move::NULL_MOVE()) {
				return true;
			}
		}

		return false;
	}
}

Move MateFinder::findMatingMove(const GameConfiguration conf, const  int moves) {
	_ASSERTE(moves >= 1);
	Game::configure(conf);
	return findMatingMoveImpl(moves);
}