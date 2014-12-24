#include "Search.h"
#include "EvaluationManager.h"
#include "Game.h"
#include <cstdint>

Search_SearchResult Search::searchResult;


void Search::startSearch(const AI_SearchConfiguration conf){
	Search::synchronize();

	searchResult = Search_SearchResult();


	for (int depth = 1; depth < conf.maxDepth; ++depth) {
		Search_Parameters params;
		params.depth = depth;
		searchResult = search(params);
	}

}

AI_SearchResult Search::getSearchResult() {
	AI_SearchResult result;
	result.score = searchResult.score;
	result.bestMove = searchResult.bestMove;

	return result;
}