#include "UCI.h"
#include <iostream>
#include <string>
#include <thread>
#include <windows.h> 
#include "StringUtils.h"
#include "Game.h"
#include "Search.h"
#include "Search_Configuration.h"

using namespace std;

std::thread UCI::searchThread;
std::atomic<int> UCI::searchCount = 0;
std::mutex UCI::mtx;
Search_SearchResult UCI::result;

Search_Configuration UCI::conf;


void UCI::identify() {
	cout << "id name TheChester 0.0" << endl;
	cout << "id author Gary Z" << endl;
	cout << "uciok" << endl;
	cout << "option name Ponder type check default true" << endl;
}

void UCI::run() {
	identify();

	string line;
	while (getline(cin, line)) {
		if (line == "quit") {
			stopSearch();
			return;
		}
		if (line == "isready") {
			cout << "readyok" << endl;
			setStopSearchDelay(2000);
			continue;
		}
		if (StringUtils::startsWith(line, "position ")) {
			stopSearch();
			position(line);
			continue;
		}

		if (StringUtils::startsWith(line, "go")) {
			go(line);
			continue;
		}


		if (line == "stop") {
			stopSearch();
		}

		if (line == "ponderhit") {
			setStopSearchDelay(decideSearchTime());
		}
	}
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

	} else if (type == "fen") {
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
			cout << "INVALID MOVE: " << move.str() << endl;
		}

		Game::makeMove(move);
	}
}


void UCI::setStopSearchDelay(int ms) {
	thread stopper(UCI::searchStopper,ms,(int)searchCount);
	stopper.detach();
}

void UCI::searchStopper(int ms,int count) {
	Sleep(ms);
	mtx.lock();
	if (count == searchCount) {
		Search::signalStop();
	}

	mtx.unlock();
}

void UCI::stopSearch() {
	Search::signalStop();
	if (searchThread.joinable()) {
		searchThread.join();
	}
}

void UCI::searchEntry() {
	Search_Configuration searchConf;
	searchConf.maxDepth = Search_Configuration::MAX_DEPTH_INF;
	searchConf.maxTimeMs = 2000;
	result = Search::startSearch(searchConf);

	mtx.lock();

	// Score
	if (result.isMateScore()) {
		cout << "score mate " << result.mateInN();
	} else {
		cout << "score cp " << result.score;
	}
	cout << ' ';

	// pv
	cout << "pv ";
	for (auto* pv = &result.pv; pv; pv = pv->next.get()) {
		if (pv->move != Move::INVALID()) {
			cout << pv->move.str() << ' ';
		}

	}

	cout << endl;

	cout << "bestmove " << result.pv.move.str();
	if (result.pv.next) {
		cout << " ponder " << result.pv.next->move.str();
	}
	cout << endl;

	mtx.unlock();
}

void UCI::startSearch() {
	stopSearch();

	mtx.lock();
	searchCount++;
	Search::prepareSearch();


	searchThread = thread(searchEntry);

	if (conf.maxTimeMs != Search_Configuration::SEARCH_TIME_INF) {
		setStopSearchDelay(conf.maxTimeMs);
	}
	

	mtx.unlock();
}

void UCI::go(const std::string& line) {
	populateConf(line);

	if (!conf.ponder) {
		conf.maxTimeMs = decideSearchTime();
	}

	startSearch();
}

void UCI::populateConf(const std::string& line) {
	conf = Search_Configuration();

	istringstream cin(line);
	string opt;
	cin >> opt;//go

	while (cin >> opt) {
		if (opt == "depth") {
			cin >> conf.maxDepth;
		}
		if (opt == "infinite") {
			conf.infinite = true;
			conf.maxTimeMs = Search_Configuration::SEARCH_TIME_INF;
		}
		if (opt == "movetime") {
			cin >> conf.maxTimeMs;
		}
		if (opt == "btime") {
			cin >> conf.btime;
		}
		if (opt == "wtime") {
			cin >> conf.wtime;
		}
		if (opt == "winc") {
			cin >> conf.winc;
		}
		if (opt == "binc") {
			cin >> conf.binc;
		}
		if (opt == "ponder") {
			conf.ponder = true;
			conf.infinite = true;
			conf.maxTimeMs = Search_Configuration::SEARCH_TIME_INF;
		}
	}
}

int UCI::decideSearchTime() {

	return 2000;
}

