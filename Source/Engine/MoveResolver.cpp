#include "MoveResolver.h"
#include "Game.h"


Move MoveResolver::resolveUCI(std::string uciString) {
	for (Move move : Game::getAllMoves()) {
		if (move.str() == uciString) {
			return move;
		}
	}
	return Move::INVALID();
}
