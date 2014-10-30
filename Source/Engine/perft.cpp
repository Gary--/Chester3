#include "perft.h"
#include "Game.h"
using namespace std;
namespace {
	int perft(int depth, bool full) {
		if (depth == 0) {
			if (full) {
				return 1;
			} else {
				return Game::getNumValidMoves();
			}
		}

#ifdef _DEBUG
		string FEN = GameConfiguration::extractFromGame().str();
#endif
		int numMoves = Game::getNumValidMoves();
		int res = 0;
		for (int i = 0; i < numMoves; ++i) {
			Move move = Game::getMove(i);

			Game::makeMove(move);
			res += perft(depth - 1, full);

			Game::undoMove();
		}
		return res;
	}
}

int Perft::perftLazy(const char* FEN, int depth) {
	GameConfiguration conf(FEN);
	Game::configure(conf);
	return perft(depth-1, false);
}

int Perft::perftFull(const char* FEN, int depth) {
	GameConfiguration conf(FEN);
	Game::configure(conf);
	return perft(depth, true);
}