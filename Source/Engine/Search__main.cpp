#include "Search.h"
#include "EvaluationManager.h"
#include "Game.h"
#include <cstdint>
#include <iostream>
Search_SearchResult Search::searchResult;

namespace {
	const int windows[2] = { 50, 200};

	int bound(int prevScore, int fact, int lvl) {
		if (lvl >= 2) {
			return fact*(Search_SearchResult::MATE_SCORE+1);
		}

		return prevScore + fact*windows[lvl];
	}

}
void Search::startSearch(const AI_SearchConfiguration conf){
	Search::synchronize();

	searchResult = Search_SearchResult();

	int prevScore = 0;
	for (int depth = 1; depth <= conf.maxDepth; ++depth) {
		Search_Parameters params;
		params.depth = depth;


		
		int alphaLvl = 0, betaLvl = 0;
		if (depth > 1) {
			for (int i = 0; i < 3; ++i) {
				params.alpha = bound(prevScore, -1, alphaLvl);
				params.beta = bound(prevScore, +1, betaLvl);

				searchResult = search(params);

				if (searchResult.score >= params.beta) {
					betaLvl++;
				} else if (searchResult.score <= params.alpha) {
					alphaLvl++;
				} else {
					break;
				}

			}

		} else {
			searchResult = search(params);
		}

		prevScore = searchResult.score;
		
	}


}

AI_SearchResult Search::getSearchResult() {
	AI_SearchResult result;
	result.score = searchResult.score;
	result.bestMove = searchResult.bestMove;

	return result;
}