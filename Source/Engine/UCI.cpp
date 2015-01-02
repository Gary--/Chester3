#include "UCI.h"
#include <iostream>
#include <string>
#include "SearchThread.h"
#include "StringUtils.h"
#include <sstream>
#include "Game.h"
#include "UCISearchThreadCallBack.h"
using namespace std;

void UCI::run() {
	identify();

	SearchThread::setCallBack(UCISearchThreadCallBack::getInstance());
	string line;
	while (getline(cin,line)) {
		if (line == "quit") {
			return;
		}

		if (line == "isready") {
			cout << "readyok" << endl;
			continue;
		}

		if (line == "stop") {
			stopSearchThread();
			continue;
		}

		if (StringUtils::startsWith(line, "go")) {
			Search_Configuration searchConf;
			searchConf.maxDepth = Search_Configuration::MAX_DEPTH_INF;
			searchConf.maxTimeMs = 2000;
			//searchConf.maxDepth = Search_Configuration::SEARCH_TIME_INF;

			SearchThread::setSearchConfiguration(searchConf);
			SearchThread::start();
		}

		if (StringUtils::startsWith(line, "position ")) {
			stopSearchThread();
			position(line);
			continue;
		}

	}
}

void UCI::identify() {
	cout << "id name Chester 1.0" << endl;
	cout << "id author Gary Z" << endl;
	cout << "uciok" << endl;
}

void UCI::ouputBestMove() {
	stopSearchThread();

	const auto result = SearchThread::getSearchResult();
	cout << "info score cp " << result.score << endl;
	cout << "bestmove " << result.pv.move.str() << endl;
}

void UCI::searchCallback(SearchTerminationCondition condition)
{
	ouputBestMove();
	//cout << "Search callback: " << (int)condition << endl;
}

void UCI::position(const std::string& line) {
	

	istringstream cin(line);

	string scratch;
	cin >> scratch; // position

	// fen or startpos
	string type;
	cin >> type;
	if (type == "startpos") {
		Game::configure(GameConfiguration::INITIAL);

	} else if (type=="fen") {
		string fen;
		for (int i = 0; i < 6; ++i) {
			string part;
			cin >> part;
			fen += part + " ";
		}
		fen.pop_back();
		Game::configure(GameConfiguration(fen));
	} else {
		cout << "ERROR: bad 'position' command" << endl;
	}

	string moveStr;
	cin >> moveStr; // moves

	while (cin >> moveStr) {
		const Move move = Game::getGameConfiguration().getMoveUciString(moveStr);
		if (move == Move::INVALID()) {
			cout << "INVALID MOVE" << endl;
		}

		Game::makeMove(move);
	}
}

void UCI::stopSearchThread() {
	SearchThread::stopAsync();
	SearchThread::waitForFinish();
}
