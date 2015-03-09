#include "UCI.h"
#include <iostream>
#include <string>
#include <thread>
#include <windows.h> 
#include "StringUtils.h"
#include "Game.h"
#include "Search.h"

using namespace std;

std::thread UCI::searchThread;
std::atomic<int> UCI::searchCount = 0;
std::mutex UCI::mtx;

void UCI::identify() {
	cout << "id name TheChester 0.0" << endl;
	cout << "id author Gary Z" << endl;
	cout << "uciok" << endl;
}

void UCI::run() {
	identify();

	string line;
	while (getline(cin, line)) {
		if (line == "quit") {
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
		cout << "SignaledSearchStop" << endl;
		Search::signalStop();
	} else {
		cout << "AlreadyStopped" << endl;
	}

	mtx.unlock();
}

void UCI::stopSearch() {
	mtx.lock();
	Search::signalStop();
	searchThread.join();

	mtx.unlock();
}


