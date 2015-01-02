#include "Search.h"
#include "EvaluationManager.h"
#include "Game.h"
#include <cstdint>
#include <iostream>
using namespace std;


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
Search_SearchResult Search::startSearch(const Search_Configuration conf) {
	canExit = false;

	Search_SearchResult searchResult;

	
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


			if (shouldStopSearch()) { // The search may have been cut off by the exit signal. Don't use the result.
				break;
			}
			
			if (newResult.score >= params.beta) {
				betaLvl++;
			} else if (newResult.score <= params.alpha) {
				alphaLvl++;
			} else {
				// We have a PV.
				searchResult = newResult;
				canExit = true;
				break;
			}

			if (i >= 4) {
				cout << "??? Somethin is wrong." << endl;
				system("pause");
			}
		}
		if (shouldStopSearch()) {
			break;
		}


		if (searchResult.score <= params.alpha || searchResult.score >= params.beta) {
			cout << "NOT PV:!!" << endl;
			system("pause");
		}
		prevResult = searchResult;

		
		cout << "info depth " << depth << ' ';

		{
			auto result = prevResult;
			cout << "pv ";
			for (auto* pv = &result.pv; pv; pv = pv->next.get()) {
				if (pv->move != Move::INVALID()) {
					cout << pv->move.str() << ' ';
				}

			}
		}
		cout << endl;
		//{
		//	cout << "info ";
		//	auto result = searchResult;
		//	// Score
		//	if (result.isMateScore()) {
		//		cout << "score mate " << result.mateInN();
		//	} else {
		//		cout << "score cp " << result.score;
		//	}
		//	cout << ' ';

		//	cout << "depth " << depth << ' ';

		//	// pv
		//	cout << "pv ";
		//	for (auto* pv = &result.pv; pv; pv = pv->next.get()) {
		//		if (pv->move != Move::INVALID()) {
		//			cout << pv->move.str() << ' ';
		//		}

		//	}
		//}
		if (searchResult.isMateScore()) {
			break;
		}
		
		if (searchResult.isPseudoMateScore() && depth > 8) {
			break;
		}
	}

	return searchResult;
}

