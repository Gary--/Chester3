#include "Search_SearchResult.h"
#include <cstdint>



Search_SearchResult::Search_SearchResult() {
	score = -(MATE_SCORE + 1);
	pv = PV_Node();
}