#include "StrengthTest.h"
#include <string>
#include "ExtendedPositionDescription.h"
#include "AI.h"
#include "Game.h"

using namespace std;


void StrengthTest::epdTest(std::istream& cin, std::ostream& cout) {
	string line;
	cout << "=== Test started." << endl;
	while (getline(cin, line)) {
		//cout << "===== " << line << endl;
		const ExtendedPositionDescription epd(line);
		const GameConfiguration gameConf = epd.getGameConfiguration();

		if (!gameConf.isValid()) {
			cout << "Bad Game configuration." << gameConf.str() << endl;
			continue;
		}

		if (epd.bestMove == Move::INVALID()) {
			cout << "Invalid best move." << endl;
			continue;
		}

		AI_SearchConfiguration searchConf;
		searchConf.maxDepth = 4;
		Game::configure(gameConf);
		AI::configureSearch(searchConf);
		AI::startSearch();
		AI::stopSearch();
		auto result = AI::getSearchResult();

		if (result.bestMove == epd.bestMove) {
			cout << "Correct" << endl;
		} else {
			cout << "Incorrect" << endl;
		}
	}
}
