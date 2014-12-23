#include "Search.h"
#include "Game.h"
Search_SearchResult Search::nullMoveSearch(const Search_Parameters p) {
	Search_SearchResult result;
	
	if (p.depth >= 3 &&! Game::getCheck()) {
		Search_Parameters newParams;
		newParams.alpha = -p.beta;
		newParams.beta = -(p.beta - 1);
		newParams.ply = p.ply + 1;
		newParams.depth = p.depth - 2;

		Search::searchMakeMove(Move::NULL_MOVE());
		const Search_SearchResult nullMoveResult = search(newParams);
		Search::searchUndoMove();

		if (-nullMoveResult.score >= p.beta) {
			result.nodeType = NodeType::FAIL_HIGH;
			result.score = p.beta;
		}
	}

	return result;
}