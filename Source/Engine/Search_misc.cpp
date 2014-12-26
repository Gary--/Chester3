#include "Search.h"
#include "Game.h"
Search_SearchResult Search::gameOverScore() {
	_ASSERTE(!Game::areMovesAvailable());
	Search_SearchResult result;
	if (Game::getCheck()) {// We got checkmated.
		result.score = -Search_SearchResult::MATE_SCORE;
	} else {// Stalemate.
		result.score = 0;
	}
	return result;
}