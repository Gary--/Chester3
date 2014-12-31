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

using namespace std;


namespace {

}

void StrengthTest::epdTest(std::istream& cin, std::ostream& cout) {
	string line;
	cout << "=== Test started." << endl;
	clock_t start = clock();
	int total = 0, correct = 0;
	while (getline(cin, line)) {
	
		const ExtendedPositionDescription epd(line);
		const GameConfiguration gameConf = epd.getGameConfiguration();

		if (!gameConf.isValid()) {
			cout << "Bad Game configuration." << gameConf.str() << endl;
			continue;
		}

		
		
		Search_Configuration searchConf;
		searchConf.maxDepth = 10;
		Game::configure(gameConf);

		{
			HANDLE searchThreatHandle = Search::getSearchHandle(searchConf);
			HANDLE timerHandle  = CreateWaitableTimer(NULL, TRUE, NULL);


			ResumeThread(searchThreatHandle);
			WaitForSingleObject(searchThreatHandle, INFINITE);
		}

		auto result = Search::getSearchResult();


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
