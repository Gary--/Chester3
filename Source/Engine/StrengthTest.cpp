#include "StrengthTest.h"
#include <string>
#include "ExtendedPositionDescription.h"
#include "Game.h"
#include <ctime>
#include "Search_Counter.h"
#include <algorithm>
#include "Search_Configuration.h"
#include "Search.h"
#include <windows.h>
#include "SearchThread.h"
#include "UCISearchThreadCallBack.h"

using namespace std;


namespace {

}

void StrengthTest::epdTest(std::istream& cin, std::ostream& cout) {
	string line;
	cout << "=== Test started." << endl;
	clock_t start = clock();
	int total = 0, correct = 0;

	SearchThread::setCallBack(nullptr);
	while (getline(cin, line)) {
	
		const ExtendedPositionDescription epd(line);
		const GameConfiguration gameConf = epd.getGameConfiguration();
		if (!gameConf.isValid()) {
			cout << "Bad Game configuration." << gameConf.str() << endl;
			continue;
		}
		Game::configure(gameConf);

		
		
		Search_Configuration searchConf;
		searchConf.maxDepth =  8;
		searchConf.maxTimeMs = Search_Configuration::SEARCH_TIME_INF;

		SearchThread::setSearchConfiguration(searchConf);
		SearchThread::start();
		SearchThread::allowStop();
		SearchThread::waitForFinish();

		const auto result = SearchThread::getSearchResult();


		const Move moveComputedBestMove = result.pv.move;
		total++;
		if (std::find(epd.bestMoves.begin(), epd.bestMoves.end(), moveComputedBestMove) != epd.bestMoves.end()) {
			cout << "Correct" << endl;
			correct++;
		} else {
			cout << "Incorrect" << endl;
			cout << line << endl;
			cout << "Calculated Score: " << result.score << "  Computed move: " << moveComputedBestMove.str() << endl;
			cout << "Expected Move:  ";
			for (Move bestMove : epd.bestMoves) {
				cout << bestMove.str() << ", ";
			}
			cout << endl;
		}
	}

	cout << correct << '/' << total << endl;

	cout << "Total test run time: " << ((std::clock() - start) / (double)CLOCKS_PER_SEC) << endl;
	cout << "Full nodes/quiesce nodes: " << Search_Counter::full << ' ' << Search_Counter::quiesce << endl;

}
