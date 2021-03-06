#include "Search_Killers.h"
#include <algorithm>
#include "Search.h"
using namespace std;


Move Search_Killers::killers[Search_Killers::maxKillerDepth][Search_Killers::nKillers];

void Search_Killers::addKiller(const Search_Parameters params,const Move move) {
	if (move.isTactical() || params.isQuiesce() || Search::nNullsMade>0) {
		return;
	}
	if (params.ply >= maxKillerDepth) {
		return;
	}
	// Duplicate..
	for (int i = 0; i < nKillers; ++i) {
		if (killers[params.ply][i] == move) {
			return;
		}
	}

	// Insert, push out
	for (int i = nKillers-2; i>=0 ; --i) {
		killers[params.ply][i + 1] = killers[params.ply][i];
	}
	killers[params.ply][0] = move;
}

bool Search_Killers::isKiller(const Search_Parameters params,const Move move) {
	if (params.isQuiesce()) {
		return false;
	}

	for (int i = params.ply; i >=max(0,params.ply-2); i -= 2) {
		for (Move killer : killers[i]) {
			if (killer == move) {
				return true;
			}
		}
	}

	return false;
}