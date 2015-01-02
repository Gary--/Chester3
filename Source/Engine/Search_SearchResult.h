#pragma once
#include "Move.h"
#include "PV_Node.h"


// used internally within Search
struct Search_SearchResult {
	int score;
	PV_Node pv;
	Search_SearchResult();
	
	static const int MATE_SCORE = 1000000;

	// If abs(score) > this, then we have a sure mate
	static const int PSEUDO_MATE_SCORE = 5000;

	// If we have a mate score, reduce it by 1. This will make faster mates more favourable.
	void adjustForMateScore();
	bool isMateScore() const;
	bool isPseudoMateScore() const;

	// Only valid if isMateScore(). In moves, not plies. Positive for turn player mating.
	int mateInN() const;
};