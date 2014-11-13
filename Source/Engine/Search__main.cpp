#include "Search.h"
#include "Evaluate_simple.h"
#include "Game.h"
#include <cstdint>

Search_SearchResult Search::searchResult;

void Search::configureGame(GameConfiguration conf) {
	Game::configure(conf);
	SimpleEvaluation::synchronize();
}

void Search::startSearch(const AI_SearchConfiguration conf){
	searchResult = Search_SearchResult();
	searchResult = search(conf.maxDepth, 0, INT_MIN, INT_MAX);
}

AI_SearchResult Search::getSearchResult() {
	AI_SearchResult result;
	result.score = searchResult.score;
	result.bestMove = searchResult.bestMove;

	return result;
}