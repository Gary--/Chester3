#include "Search.h"
#include "EvaluationManager.h"
#include "Game.h"
#include <cstdint>
#include <iostream>
using namespace std;

Search_SearchResult Search::searchResult;
int Search::nNullsMade = 0;
int Search::nChecks = 0;
int Search::reduction1 = 0;
std::atomic<bool> Search::exitSignal = false;
bool Search::canExit = false;
namespace {
	const int windows[2] = { 50, 200};

	int bound(int prevScore, int fact, int lvl) {
		if (lvl >= 2) {
			return fact*(Search_SearchResult::MATE_SCORE+1);
		}

		return prevScore + fact*windows[lvl];
	}

}
void Search::startSearchImpl(const Search_Configuration conf){
	canExit = false;

	Search::synchronize();

	searchResult = Search_SearchResult();

	
	Search_SearchResult prevResult;
	for (int depth = 1; depth <= conf.maxDepth; ++depth) {
		Search_Parameters params;
		params.depth = depth;
		params.pv = prevResult.pv;

		int alphaLvl = 0, betaLvl = 0;

		// Open the window completely for first depth
		if (depth <= 1) {
			alphaLvl = betaLvl = 2;
		}

		for (int i = 0;; ++i) {
			params.alpha = bound(prevResult.score, -1, alphaLvl);
			params.beta = bound(prevResult.score, +1, betaLvl);
			
			const Search_SearchResult newResult = search(params);


			if (exitSignal) { // The search may have been cut off by the exit signal. Don't use the result.
				break;
			}
			searchResult = newResult;

			if (searchResult.score >= params.beta) {
				betaLvl++;
			} else if (searchResult.score <= params.alpha) {
				alphaLvl++;
			} else {
				// We have a PV.
				canExit = true;
				break;
			}

			if (i >= 4) {
				cout << "??? Somethin is wrong." << endl;
				system("pause");
			}
		}


		if (searchResult.score <= params.alpha || searchResult.score >= params.beta) {
			cout << "NOT PV:!!" << endl;
			system("pause");
		}
		prevResult = searchResult;

		if (searchResult.isMateScore()) {
			break;
		}
		
	}


}

Search_SearchResult Search::getSearchResult() {
	return searchResult;
}