#include "Search.h"
#include <cstdint>
#include "Game.h"
#include <algorithm>
#include "MoveOrdering.h"
using namespace std;

Search_SearchResult Search::callSearch(const Search_Parameters previousParams,const int bestScore) {
	Search_Parameters newParams;
	newParams.depth = previousParams.depth - 1;
	newParams.ply = previousParams.ply + 1;
	newParams.alpha = -previousParams.beta;
	newParams.beta = -bestScore;

	return search(newParams);
}

Search_SearchResult Search::search(const Search_Parameters p) {
	int bestScore = p.alpha;
	if (!Game::areMovesAvailable()) {
		return gameOverScore();
	}

	if (p.depth <= 0) {
		return callQuiescenceSearch(p, bestScore);
	}
	
	Move bestMove = Move::INVALID();

	MoveOrdering orderedMoves = MoveOrdering(p, Game::getAllMoves());
	for (const OrderedMove orderedMove : orderedMoves) {
		const Move move = orderedMove.move;
		searchMakeMove(move);
		const Search_SearchResult moveResult = callSearch(p,bestScore);
		searchUndoMove();

		{
			const int moveScore = -moveResult.score;
			if (moveScore > bestScore) {
				bestScore = moveScore;
				bestMove = move;
			}
		}

		if (bestScore >= p.beta) {
			Search_SearchResult result;
			result.score = p.beta;
			result.bestMove = bestMove;
			result.nodeType = NodeType::FAIL_HIGH;
			return result;
		}
	}

	Search_SearchResult result;
	result.score = bestScore;
	result.bestMove = bestMove;
	result.nodeType = bestScore <= p.alpha ? NodeType::FAIL_LOW : NodeType::PV;
	return result;
}