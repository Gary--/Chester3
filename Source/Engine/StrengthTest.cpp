#include "StrengthTest.h"
#include <string>
#include "ExtendedPositionDescription.h"
#include "AI.h"
#include "Game.h"
#include <ctime>
#include "Search_Counter.h"
#include <algorithm>
using namespace std;


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

		

		AI_SearchConfiguration searchConf;
		searchConf.maxDepth = 8;
		Game::configure(gameConf);
		AI::configureSearch(searchConf);
		AI::startSearch();
		AI::stopSearch();
		auto result = AI::getSearchResult();

		total++;
		if (std::find(epd.bestMoves.begin(),epd.bestMoves.end(),result.bestMove)!=epd.bestMoves.end() ) {
			cout << "Correct" << endl;
			correct++;
		} else {
			cout << "Incorrect" << endl;
			cout << line << endl;
			cout << "Calculated Score: " << result.score << "  Computed move: " << result.bestMove.str() << endl;
			cout << "Expected Move:  ";
			for (Move bestMove : epd.bestMoves) {
				cout << bestMove.str() << ", ";
			}
			cout << endl;
		}
	}

	cout << correct << '/' << total << endl;

	cout << "Time: " << ((std::clock() - start) / (double)CLOCKS_PER_SEC) << endl;
	cout << "Counts: " << Search_Counter::full << ' ' << Search_Counter::quiesce << endl;

}
