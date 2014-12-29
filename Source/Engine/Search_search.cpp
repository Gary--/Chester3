#include "Search.h"
#include <cstdint>
#include "Game.h"
#include <algorithm>
#include "MoveOrdering.h"
#include "Search_Killers.h"
#include "AttackMap.h"
#include "EvaluationManager.h"
#include "Search_History.h"
#include "Search_Transposition.h"
#include "Search_Counter.h"
using namespace std;

Search_SearchResult Search::callSearch(const Search_Parameters previousParams,const int alpha,const int beta,bool isPv) {
	Search_Parameters newParams;
	newParams.depth = previousParams.depth - 1;
	newParams.ply = previousParams.ply + 1;
	newParams.alpha = alpha;
	newParams.beta = beta;

	// Check extension
	if (!previousParams.isQuiesce() && EvaluationManager::getScore(1).getCheck() && nChecks>1) {
		newParams.depth++;
	}

	if (isPv && previousParams.pv.next) {
		newParams.pv = *previousParams.pv.next;
	}

	return search(newParams);
}

Search_SearchResult Search::search(const Search_Parameters p) {
	Search_SearchResult result;
	result.score = p.alpha;
	if (!Game::areMovesAvailable()) {
		return gameOverScore();
	}

	if (p.ply > 0 && Game::getRepeatCount() > 1) {
		result.score = 0;
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
				int margin = 50 + prevScore.getOverall(turn) - prevScore.getRelativeSimple(turn);

				if (EvaluationManager::getRelativeSimpleScore(turn) + margin <= -p.beta) {
					result.score = p.beta;
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
			result.score = max(result.score, standPat);
			if (result.score >= p.beta) {
				return result;
			}
			

		}

	}

	
	if (!p.isQuiesce()){
		const Search_SearchResult nullMoveResult = nullMoveSearch(p);
		if (nullMoveResult.score >= p.beta) {
			return nullMoveResult;
		}
	}

	

	AttackMap::precompute();
	EvaluationManager::calcScoreCurrent();

	MoveOrdering orderedMoves = MoveOrdering(p, (!p.isQuiesce() || Game::getCheck()) ? Game::getAllMoves() : Game::getTacticalMoves());

	int i = -1;
	for (const OrderedMove orderedMove : orderedMoves) {
		i++;

		const Move move = orderedMove.move;
		if (p.isQuiesce() && !Game::getCheck() && AttackMap::SEE(move) < 0) {
			continue;
		}
		if (p.isQuiesce() && !Game::getCheck() && move.isPromotion() && move.promotionPiece() != Piece::QUEEN()) {
			continue;
		}

		const bool useNullWindow = i > 0 && !p.isQuiesce();

		Search_SearchResult moveResult;

		// Initial search
		searchMakeMove(move);
		moveResult = callSearch(p, useNullWindow ? -result.score-1 : -p.beta, -result.score, i == 0);
		searchUndoMove();
		Search_Counter::nullSearches += useNullWindow;
		// Re-search
		if (useNullWindow && (-moveResult.score > result.score) && (-moveResult.score < p.beta)) {
			Search_Counter::researches++;
			searchMakeMove(move);
			moveResult = callSearch(p, -p.beta, moveResult.score, i == 0);
			searchUndoMove();
		}

		{
			const int moveScore = -moveResult.score;
			if (moveScore > result.score) {
				result.score = moveScore;
				if (!p.isQuiesce()) {
					result.pv = PV_Node(move, moveResult.pv);
				}
			}
		}

		if (result.score >= p.beta) {
			if (!p.isQuiesce()) {
				Search_Killers::addKiller(p, move);
				Search_History::addHistory(p, move);
			}

			break;
		}
	}
	orderedMoves.dispose();
	
	result.adjustForMateScore();
	return  result;
}