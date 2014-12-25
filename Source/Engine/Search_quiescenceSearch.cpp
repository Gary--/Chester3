#include "Search.h"
#include "SimpleEvaluation.h"
#include "Game.h"
#include "EvaluationManager.h"
#include <algorithm>
#include "AttackMap.h"
#include "Search_Transposition.h"

using namespace std;


namespace {
	const int maxQuiesceDepth = 6;
}

Search_SearchResult Search::callQuiescenceSearch(const Search_Parameters previousParams,const int bestScore) {
	Search_Parameters newParams;
	newParams.depth = Search_Parameters::QUIESCE_DEPTH;


	if (previousParams.isQuiesce()) {
		newParams.alpha = -previousParams.beta;
		newParams.beta = -bestScore;
		newParams.ply = previousParams.ply + 1;
	} else {
		newParams.alpha = previousParams.alpha;
		newParams.beta = previousParams.beta;
		newParams.ply = 0;
	}

	return quiescenceSearch(newParams);
}

Search_SearchResult Search::quiescenceSearch(const Search_Parameters p) {
	int bestScore = p.alpha;
	Move bestMove = Move::INVALID();
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
					result.score = p.beta;
					result.bestMove = ttItem.bestMove;
					result.nodeType = NodeType::FAIL_HIGH;
					return result;
				}
			}

			if (ttItem.type == NodeType::FAIL_LOW && ttItem.score <= p.alpha) {
				Search_SearchResult result;
				result.score = p.alpha;
				result.nodeType = NodeType::FAIL_LOW;
				return result;
			}
		}
	}

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



	if (!Game::areMovesAvailable()) {
		return gameOverScore();
	}

	
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

	// Make sure we have the evaluation saved.
	EvaluationManager::calcScoreCurrent();



	auto movesToUse = Game::getCheck() ? Game::getAllMoves() : Game::getTacticalMoves();
	for (Move move : movesToUse) {
		if (!Game::getCheck() && AttackMap::SEE(move)<0) {
			continue;
		}

		searchMakeMove(move);


		Search_SearchResult moveResult = callQuiescenceSearch(p,bestScore);
		searchUndoMove();

		if (-moveResult.score > bestScore) {
			bestScore = -moveResult.score;
			bestMove = move;
		}

		if (bestScore >= p.beta) {
			Search_SearchResult result;
			result.score = p.beta;
			result.nodeType = NodeType::FAIL_HIGH;
			result.bestMove = move;
			return result;
		}
	}

	Search_SearchResult result;
	result.score = bestScore;
	result.bestMove = bestMove;
	result.nodeType = bestScore <= p.alpha ? NodeType::FAIL_LOW : NodeType::PV;
	return result;
}