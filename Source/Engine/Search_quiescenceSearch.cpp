#include "Search.h"
#include "SimpleEvaluation.h"
#include "Game.h"
#include "EvaluationManager.h"
#include <algorithm>
#include "AttackMap.h"

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
		standPat = EvaluationManager::getScore().getOverall(Game::getTurn());
	}
	if (standPat >= p.beta) {
		Search_SearchResult result;
		result.score = p.beta;
		result.nodeType = NodeType::FAIL_HIGH;
		return result;
	}
	int bestScore = p.alpha;
	bestScore = max(bestScore, standPat);

	// Make sure we have the evaluation saved.
	EvaluationManager::calcScoreCurrent();



	Move bestMove = Move::INVALID();
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