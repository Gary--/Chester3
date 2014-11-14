#include "Search.h"
#include "SimpleEvaluation.h"
#include "Game.h"
#include <cstdint>

Search_SearchResult Search::searchResult;

void Search::configureGame(GameConfiguration conf) {
	Game::configure(conf);
	SimpleEvaluation::synchronize();
}

void Search::startSearch(const AI_SearchConfiguration conf){
	searchResult = Search_SearchResult();
	searchResult = search(conf.maxDepth, 0, -Search_SearchResult::MATE_SCORE, Search_SearchResult::MATE_SCORE);
}

AI_SearchResult Search::getSearchResult() {
	AI_SearchResult result;
	result.score = searchResult.score;
	result.bestMove = searchResult.bestMove;

	return result;
}