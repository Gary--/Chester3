#include "Search_History.h"
#include "Game.h"
#include <algorithm>

using namespace std;
int Search_History::history[2][7][64] = { 0 };


void Search_History::reset() {
	FOR_TURN(turn) {
		FOR_PIECE_ALL(piece) {
			FOR_POSITION_64(pos) {
				history[turn.asIndex()][piece.asIndex()][pos.index()] = 0;
			}
		}
	}
}

void Search_History::addHistory(const Search_Parameters params,const Move goodMove) {
	if (params.isQuiesce()) {
		return;
	}
	

	bool needHalve = false;

	for (Move move : Game::getAllMoves()) {
		int& v = history[Game::getTurn().asIndex()][move.getPiece().asIndex()][move.getTo().index()];
		if (move == goodMove) {
			
			v += params.depth * params.depth;
			needHalve |= abs(v) > MAX_HISTORY;
			break;
		} else {
			v -= params.depth * params.depth;
			needHalve |= abs(v) > MAX_HISTORY;
		}
	}

	if (needHalve) {
		halve();
	}
}

int Search_History::getHistory(const Move move) {
	return history[Game::getTurn().asIndex()][move.getPiece().asIndex()][move.getTo().index()];
}

void Search_History::halve() {
	FOR_TURN(turn) {
		FOR_PIECE_ALL(piece) {
			FOR_POSITION_64(pos) {
				history[turn.asIndex()][piece.asIndex()][pos.index()] /= 2;
			}
		}
	}
}

