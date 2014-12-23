#include "Search.h"
#include "EvaluationManager.h"
#include "Game.h"
#include <cstdint>

Search_SearchResult Search::searchResult;


void Search::startSearch(const AI_SearchConfiguration conf){
	Search::synchronize();

	searchResult = Search_SearchResult();
	searchResult = search(conf.maxDepth, 0, -Search_SearchResult::MATE_SCORE, Search_SearchResult::MATE_SCORE);
}

AI_SearchResult Search::getSearchResult() {
	AI_SearchResult result;
	result.score = searchResult.score;
	result.bestMove = searchResult.bestMove;

	return result;
}