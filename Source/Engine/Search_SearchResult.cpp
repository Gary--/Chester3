#include "Search_SearchResult.h"
#include <cstdint>



Search_SearchResult::Search_SearchResult() {
	score = -(MATE_SCORE + 1);
	pv = PV_Node();
}

void Search_SearchResult::adjustForMateScore() {
	if (score > MATE_SCORE - 100000) {
		score--;
	}
}

bool Search_SearchResult::isMateScore() const {
	return score > MATE_SCORE - 100000 || score < -MATE_SCORE + 100000;
}

int Search_SearchResult::mateInN() const {
	if (!isMateScore()) {
		return 0;
	}

	if (score > 0) {
		return MATE_SCORE - score;
	} else {
		return  -MATE_SCORE - score;
	}
}
