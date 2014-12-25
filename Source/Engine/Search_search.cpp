#include "Search.h"
#include <cstdint>
#include "Game.h"
#include <algorithm>
#include "MoveOrdering.h"
#include "Search_Killers.h"
#include "AttackMap.h"
#include "Search_PV_Table.h"
#include "EvaluationManager.h"
#include "Search_History.h"
#include "Search_Transposition.h"
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
	Move bestMove = Move::INVALID();

	if (!Game::areMovesAvailable()) {
		return gameOverScore();
	}

	if (p.ply > 0 && Game::getRepeatCount() > 1) {
		Search_SearchResult result;
		result.score = 0;
		result.nodeType = NodeType::PV;
		return result;
	}

	{
		TTItem ttItem = Search_Transposition::getTransposition(p);
		if (ttItem.depth >= p.depth && ttItem.type != NodeType::UNKNOWN) {
			if (ttItem.type == NodeType::PV) {
				Search_SearchResult result;
				result.score = ttItem.score;
				result.bestMove = ttItem.bestMove;
				result.nodeType = NodeType::PV;
				return result;
			}

			if (ttItem.type == NodeType::FAIL_HIGH) {
				bestScore = max(bestScore, ttItem.score);
				if (ttItem.score >= p.alpha) {
					bestMove = ttItem.bestMove;
				}

				if (ttItem.score >= p.beta) {
					Search_SearchResult result;
					result.score = ttItem.score;
					result.bestMove = ttItem.bestMove;
					result.nodeType = NodeType::FAIL_HIGH;
					return result;
				}
			}
			
			if (ttItem.type == NodeType::FAIL_LOW && ttItem.score <= p.alpha) {
				Search_SearchResult result;
				result.score = ttItem.score;
				result.nodeType = NodeType::FAIL_LOW;
				return result;
			}
		}
	}

	if (p.depth <= 0) {
		return callQuiescenceSearch(p, bestScore);
	}
	
	{
		const Search_SearchResult nullMoveResult = nullMoveSearch(p);
		if (nullMoveResult.nodeType == NodeType::FAIL_HIGH) {
			return Search_Transposition::addTransposition(p, nullMoveResult);
		}
	}

	

	AttackMap::precompute();
	EvaluationManager::calcScoreCurrent();

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
			Search_Killers::addKiller(p, move);
			Search_History::addHistory(p, move);

			Search_SearchResult result;
			result.score = bestScore;
			result.bestMove = bestMove;
			result.nodeType = NodeType::FAIL_HIGH;

			return Search_Transposition::addTransposition(p, result);
		}
	}

	Search_SearchResult result;
	result.score = bestScore;
	result.bestMove = bestMove;
	result.nodeType = bestScore <= p.alpha ? NodeType::FAIL_LOW : NodeType::PV;

	if (result.nodeType == NodeType::PV) {
		Search_PV_Table::storePVMove(Game::getHash(), result.bestMove);
	}

	return Search_Transposition::addTransposition(p, result);
}