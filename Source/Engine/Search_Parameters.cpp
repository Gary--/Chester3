#include "Search_Parameters.h"
#include "Search_SearchResult.h"



Search_Parameters::Search_Parameters() {
	alpha = -(Search_SearchResult::MATE_SCORE +1);
	beta = Search_SearchResult::MATE_SCORE +1;
	ply = 0;
	depth = 0;
}

bool Search_Parameters::isQuiesce() const {
	return depth <= 0;
}

bool Search_Parameters::wasQuiesce() const {
	return depth < 0;
}
