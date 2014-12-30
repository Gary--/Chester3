#include "ConsoleMode.h"
#include "Game.h"
#include "display.h"
#include <iostream>
#include <string>
#include <sstream>
#include "AI.h"
#include "EvaluationManager.h"


using namespace std;



void ConsoleMode::run() {
	Game::configure(GameConfiguration("rnbqkb1r/pppppppp/5n2/8/8/5N2/PPPPPPPP/RNBQKB1R w KQkq -"));
	Move move;
	Turn me = Turn::WHITE();
	while (Game::areMovesAvailable()) {
		
		cout << "Last Move: " << move.str() << endl;
		Display::displayText();

		EvaluationManager::synchronize();
		auto eval = EvaluationManager::getScore();
		cout << "Material: " << eval.getRelativeMaterial(me) << endl;
		cout << "Mobility: " << eval.getRelativeMobility(me) << endl;
		cout << "Pawns: " << eval.getPawns(me) << '/' << eval.getPawns(!me) << endl;
		cout << "King: " << eval.getKingDanger(me) << '/' << eval.getKingDanger(!me) << endl;
		cout << "Center: " << eval.getRelativeCenter(me) << endl;
		cout << "Misc: " << eval.getMisc(me) << '/' << eval.getMisc(!me) << endl;

		//system("CLS");
		cout << endl << endl << endl << "===========" << endl;
		if (Game::getTurn() == me) {
			auto aiRes = computerMove();
			cout << "Score: " << aiRes.score << endl;
			move = aiRes.bestMove;
		} else {
			move = humanMove();
		}
		
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
		
		Move move = Game::getMoveUciString(moveStr);
		if (move != Move::INVALID()) {
			return move;
		}

		cout << "Bad move: [" << moveStr << "]";
	}
}

AI_SearchResult ConsoleMode::computerMove() {
	AI_SearchConfiguration conf;
	conf.maxDepth = 9;

	AI::configureSearch(conf);
	AI::startSearch();

	AI::stopSearch();

	return AI::getSearchResult();
}

