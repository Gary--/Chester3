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


	if (p.isQuiesce()){

		// Try a lazy standpat
		{
			const auto prevScore = EvaluationManager::getScore(1);
			const bool wasInCheck = prevScore.getCheck();
			if (!wasInCheck && !Game::getCheck()) {
				const Turn turn = !Game::getTurn();

				// How much Lazy might underestimate our score
				int margin = 50 + prevScore.getOverall(turn) - prevScore.getSimple(turn);

				if (EvaluationManager::getSimpleScore(turn) + margin < -p.beta) {
					Search_SearchResult result;
					result.score = p.beta;
					result.nodeType = NodeType::FAIL_HIGH;
					return result;
				}
			}
		}

		// Try a full eval standpat
		{
			int standPat = -Search_SearchResult::MATE_SCORE;
			if (!Game::getCheck()) { // need to check for hanging pieces
				AttackMap::precompute();
				standPat = EvaluationManager::getScore().getOverall(Game::getTurn());
			}
			if (standPat >= p.beta) {
				Search_SearchResult result;
				result.score = p.beta;
				result.nodeType = NodeType::FAIL_HIGH;
				return result;
			}

			bestScore = max(bestScore, standPat);

		}

	}

	
	if (!p.isQuiesce()){
		const Search_SearchResult nullMoveResult = nullMoveSearch(p);
		if (nullMoveResult.nodeType == NodeType::FAIL_HIGH) {
			return Search_Transposition::addTransposition(p, nullMoveResult);
		}
	}

	

	AttackMap::precompute();
	EvaluationManager::calcScoreCurrent();

	MoveOrdering orderedMoves = MoveOrdering(p, (!p.isQuiesce() || Game::getCheck()) ? Game::getAllMoves() : Game::getTacticalMoves());
	for (const OrderedMove orderedMove : orderedMoves) {
		const Move move = orderedMove.move;
		if (p.isQuiesce() && !Game::getCheck() && AttackMap::SEE(move) < 0) {
			continue;
		}


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
			if (!p.isQuiesce()) {
				Search_Killers::addKiller(p, move);
				Search_History::addHistory(p, move);
			}

			Search_SearchResult result;
			result.score = bestScore;
			result.bestMove = bestMove;
			result.nodeType = NodeType::FAIL_HIGH;

			return  result;
		}
	}

	Search_SearchResult result;
	result.score = bestScore;
	result.bestMove = bestMove;
	result.nodeType = bestScore <= p.alpha ? NodeType::FAIL_LOW : NodeType::PV;


	return  result;
}