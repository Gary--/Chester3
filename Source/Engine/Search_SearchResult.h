#pragma once

enum class NodeType : char {
	PV,
	FAIL_LOW,
	FAIL_HIGH
};

// used internally within Search
struct Search_SearchResult {
	int score;
	Move bestMove;
};