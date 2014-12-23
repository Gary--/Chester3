#include "StrengthTest.h"
#include <string>
#include "ExtendedPositionDescription.h"
#include "AI.h"
#include "Game.h"

using namespace std;


void StrengthTest::epdTest(std::istream& cin, std::ostream& cout) {
	string line;
	while (getline(cin, line)) {
		cout << "===== " << line << endl;
		const ExtendedPositionDescription epd(line);
		const GameConfiguration gameConf = epd.getGameConfiguration();

		if (!gameConf.isValid()) {
			cout << "Bad Game configuration." << gameConf.str() << endl;
			continue;
		}

		if (epd.bestMove == Move::INVALID()) {
			cout << "Invalid best move." << endl;
		} else {
			cout << "Expected best move: " << epd.bestMove.str() << endl;
		}

		AI_SearchConfiguration searchConf;
		searchConf.maxDepth = 6;
		Game::configure(gameConf);
		AI::configureSearch(searchConf);
		AI::startSearch();
		AI::stopSearch();
		auto result = AI::getSearchResult();
		cout << result.bestMove.str() << endl;;
	}
}
