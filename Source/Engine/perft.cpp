#include "perft.h"
#include "Game.h"
#include <set>
using namespace std;
namespace {
	set<uint64_t> hashes;
	int perft(const int depth, const  bool full, const  bool storeHashes = false) {
		if (depth == 0) {
			if (full) {
				if (storeHashes) {
					hashes.insert(Game::getHash());
				}
				return 1;
			} else {
				return Game::getNumValidMoves();
			}
		}

#ifdef _DEBUG
		const string FEN = Game::getFEN();
#endif
		int res = 0;
		for (const Move move: Game::getAllMoves()){

			Game::makeMove(move);
			res += perft(depth - 1, full, storeHashes);

			Game::undoMove();
		}
		return res;
	}
}

int Perft::perftLazy(const char* FEN, const int depth) {
	const GameConfiguration conf(FEN);
	Game::configure(conf);
	return perft(depth-1, false);
}

int Perft::perftFull(const char* FEN, const int depth) {
	const GameConfiguration conf(FEN);
	Game::configure(conf);
	return perft(depth, true);
}



int Perft::perftUniquePositions(const char* FEN, const int depth) {
	const GameConfiguration conf(FEN);
	Game::configure(conf);

	hashes.clear();

	perft(depth, true, true);

#pragma warning (disable:4267)
	int result = hashes.size();
#pragma warning (default:4267)
	hashes.clear();
	return result;
}
