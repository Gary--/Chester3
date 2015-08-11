#include "UCI.h"
#include <iostream>
#include <string>
#include <thread>
//#include <windows.h>
#include "StringUtils.h"
#include "Game.h"
#include "Search.h"
#include "Search_Configuration.h"
#include <chrono>

using namespace std;

std::thread UCI::searchThread;
volatile int UCI::searchCount = 0;
std::mutex UCI::mtx;
Search_SearchResult UCI::result;
volatile bool UCI::canExitSearch = true;
Search_Configuration UCI::conf;

std::condition_variable UCI::cv;

int UCI::searchTimeRequestMs = 2000;


void UCI::identify() {
	cout << "id name TheChester 0.0" << endl;
	cout << "id author Gary Z" << endl;

	cout << "option name Ponder type check default true" << endl;
	cout << "option name SearchTime type spin default 2 min 1 max 999" << endl;
	cout << "uciok" << endl;
}

void UCI::run() {
	identify();

	string line;
	while (getline(cin, line)) {
		if (line == "quit") {
			stopSearch();
			return;
		}
		if (line == "ucinewgame") {
			stopSearch();
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

		if (StringUtils::startsWith(line, "setoption ")) {
			setOption(line);
		}

		if (line == "ponderhit") {
			if (!conf.infinite) {
				setStopSearchDelay(decideSearchTime());
			}
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
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	mtx.lock();
	if (count == searchCount) {
		Search::signalStop();
	}

	mtx.unlock();
}

void UCI::stopSearch() {
	canExitSearch = true;


	Search::signalStop();
	cv.notify_all();
	if (searchThread.joinable()) {
		searchThread.join();
	}
}

void UCI::searchEntry() {
	result = Search::startSearch(conf);

	unique_lock<mutex> lock(mtx);

	if (!canExitSearch) {
		cv.wait(lock);
	}

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
	if (result.pv.next && result.pv.next->move != Move::INVALID()) {
		cout << " ponder " << result.pv.next->move.str();
	}

	cout << endl;
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
	canExitSearch = true;



	if (conf.ponder || conf.infinite) {
		canExitSearch = false;
	} else {
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
			conf.maxTimeMs = Search_Configuration::SEARCH_TIME_INF;
		}
	}
}

int UCI::decideSearchTime() {

	return searchTimeRequestMs;
}

void UCI::setOption(const std::string& line) {
	istringstream cin(line);
	string name, scratch;

	cin >> scratch;// "setoption
	cin >> scratch;// "name"
	cin >> name;// actual name
	cin >> scratch; // "value"

	if (name == "SearchTime") {
		int timeS;
		cin >> timeS;
		searchTimeRequestMs = timeS * 1000;
	}
}

