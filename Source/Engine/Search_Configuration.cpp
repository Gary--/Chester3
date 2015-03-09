#include "Search_Configuration.h"


Search_Configuration::Search_Configuration() {
	maxDepth = MAX_DEPTH_INF;
	maxTimeMs = SEARCH_TIME_INF;
	ponder = false;
	btime = wtime = winc = binc = 0;
	infinite = false;
}
