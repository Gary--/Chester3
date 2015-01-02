#include "ConsoleMode.h"
#include "Game.h"
#include "display.h"
#include <iostream>
#include <string>
#include <sstream>
#include "EvaluationManager.h"
#include "UCISearchThreadCallBack.h"
#include "SearchThread.h"

using namespace std;



void ConsoleMode::run() {
	Game::configure(GameConfiguration::INITIAL);
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
			move = aiRes.pv.move;
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


Search_SearchResult ConsoleMode::computerMove() {
	Search_Configuration searchConf;
	searchConf.maxDepth = Search_Configuration::MAX_DEPTH_INF;
	searchConf.maxTimeMs = 2000;
	SearchThread::start();
	SearchThread::waitForFinish();


	return SearchThread::getSearchResult();
}

