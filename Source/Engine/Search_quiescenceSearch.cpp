#include "Search.h"
#include "SimpleEvaluation.h"
#include "Game.h"
#include "EvaluationManager.h"
#include <algorithm>

using namespace std;

//int Quiesce(int alpha, int beta) {
//	int stand_pat = Evaluate();
//	if (stand_pat >= beta)
//		return beta;
//	if (alpha < stand_pat)
//		alpha = stand_pat;
//
//	until(every_capture_has_been_examined) {
//		MakeCapture();
//		score = -Quiesce(-beta, -alpha);
//		TakeBackMove();
//
//		if (score >= beta)
//			return beta;
//		if (score > alpha)
//			alpha = score;
//	}
//	return alpha;
//}

namespace {
	const int maxQuiesceDepth = 6;
}

Search_SearchResult Search::quiescenceSearch(const int ply,const int alpha,const int beta) {
	if (!Game::areMovesAvailable()) {
		return gameOverScore();
	}

	int standPat = -Search_SearchResult::MATE_SCORE;
	if (!Game::getCheck()) {
		standPat = EvaluationManager::getScore().getOverall(Game::getTurn());
	}
	if (standPat >= beta) {
		Search_SearchResult result;
		result.score = beta;
		result.nodeType = NodeType::FAIL_HIGH;
		return result;
	}
	int bestScore = alpha;
	bestScore = max(bestScore, standPat);

	// Make sure we have the evaluation saved.
	EvaluationManager::calcScoreCurrent();

	Move bestMove = Move::INVALID();
	auto movesToUse = Game::getCheck() ? Game::getAllMoves() : Game::getTacticalMoves();
	for (Move move : movesToUse) {
		searchMakeMove(move);
		Search_SearchResult moveResult = quiescenceSearch(ply + 1, -beta, -bestScore);
		searchUndoMove();

		if (-moveResult.score > bestScore) {
			bestScore = -moveResult.score;
			bestMove = move;
		}

		if (bestScore >= beta) {
			Search_SearchResult result;
			result.score = beta;
			result.nodeType = NodeType::FAIL_HIGH;
			result.bestMove = move;
			return result;
		}
	}

	Search_SearchResult result;
	result.score = bestScore;
	result.bestMove = bestMove;
	result.nodeType = bestScore <= alpha ? NodeType::FAIL_LOW : NodeType::PV;
	return result;
}