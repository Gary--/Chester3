#include "Search_SearchResult.h"
#include <cstdint>

Search_SearchResult::Search_SearchResult() {
	score = INT_MIN;
	bestMove = Move::INVALID();
	nodeType = NodeType::UNKNOWN ;
}