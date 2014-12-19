#include "ConsoleMode.h"
#include "Game.h"
#include "display.h"
#include <iostream>
#include <string>
#include <sstream>
#include "AI.h"
#include "MoveResolver.h"

using namespace std;

void ConsoleMode::run() {
	Game::configure(GameConfiguration::INITIAL);

	while (Game::areMovesAvailable()) {
		system("CLS");

		Display::displayText();

		Move move = computerMove();
		Game::makeMove(move);
	}
}

namespace {
	istringstream getLineStream() {
		string line;
		while (line.size() == 0) {
			getline(cin, line);
		}
		

		istringstream stream(line);

		return stream;
	}
}

Move ConsoleMode::humanMove() {
	while (true) {
		
		cout << "Enter move: ";

		auto stream = getLineStream();
		string moveStr;
		stream >> moveStr;
		
		Move move = MoveResolver::resolveUCI(moveStr);
		if (move != Move::INVALID()) {
			return move;
		}

		cout << "Bad move: [" << moveStr << "]";
	}
}

Move ConsoleMode::computerMove() {
	AI_SearchConfiguration conf;
	conf.maxDepth = 3;

	AI::configureSearch(conf);
	AI::startSearch();

	AI::stopSearch();

	return AI::getSearchResult().bestMove;
}

