#pragma once
#include "Move.h"

enum class NodeType : char {
	PV,
	FAIL_LOW,
	FAIL_HIGH,
	UNKNOWN,
};

// used internally within Search
struct Search_SearchResult {
	int score;
	Move bestMove;
	NodeType nodeType;
	Search_SearchResult();

	static const int MATE_SCORE = 100000;
};