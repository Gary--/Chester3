#include "Search.h"
#include "EvaluationManager.h"
#include "Game.h"
#include <cstdint>
#include <iostream>
using namespace std;

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

	
	Search_SearchResult prevResult;
	for (int depth = 1; depth <= conf.maxDepth; ++depth) {
		Search_Parameters params;
		params.depth = depth;
		params.pv = prevResult.pv;

		//cout << "Depth: " << depth << endl;
		int alphaLvl = 0, betaLvl = 0;
		if (depth > 1) {
			for (int i = 0; i < 3; ++i) {
				params.alpha = bound(prevResult.score, -1, alphaLvl);
				params.beta = bound(prevResult.score, +1, betaLvl);
				//cout << params.alpha << ' ' << params.beta << endl;
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

		if (searchResult.score <= params.alpha || searchResult.score >= params.beta) {
			cout << "NOT PV:!!" << endl;
			system("pause");
		}
		prevResult = searchResult;
		//cout << "Depth: " << depth << "   Score: " << searchResult.score << endl;
		//for (PV_Node* x = &searchResult.pv; x; x = x = x->next.get()) {
		//	cout << x->move.str() << ' ';
		//}
		//cout << endl;

		
	}


}

AI_SearchResult Search::getSearchResult() {
	AI_SearchResult result;
	result.score = searchResult.score;
	result.bestMove = searchResult.pv.move;

	return result;
}