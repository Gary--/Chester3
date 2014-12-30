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
#include "Evaluation.h"
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


	{
		TTItem ttRes = Search_Transposition::getTransposition(p);
		if (ttRes.depth >= p.depth) {
			if (ttRes.type == TT_Entry_Type::LOWER_BOUND || ttRes.type == TT_Entry_Type::EXACT) {
				result.score = max(result.score, ttRes.score);
				result.pv.move = ttRes.bestMove;
			}

			if (ttRes.type == TT_Entry_Type::EXACT && p.beta > p.alpha+1) {
				return result;
			}

			if (ttRes.type == TT_Entry_Type::UPPER_BOUND && ttRes.score <= p.alpha) {
				return result;
			}

			if (result.score >= p.beta) {
				return result;
			}
		}
	}




	if (p.ply > 0){
		const auto prevScore = EvaluationManager::getScore(1);
		const bool wasInCheck = prevScore.getCheck();


		if (p.depth <= 1 && !wasInCheck && !Game::getCheck()) do {
			if (!p.wasQuiesce() && Game::getPreviousMove().isTactical()) {
				break;
			}

			const Turn turn = !Game::getTurn();
			
			const int marginBase = p.wasQuiesce() ? 50 : (int)(p.isQuiesce() ? 300 + 200*Evaluation::lateness() : 500);
			const int margin = marginBase + prevScore.getOverall(turn) - prevScore.getRelativeSimple(turn);

			const int curLazy = EvaluationManager::getRelativeSimpleScore(turn);
			const int minEstScore = curLazy + margin;
			if (minEstScore <= -p.beta) {
				result.score = p.beta;
				return result;
			}
			
		} while (0);

			// Try a full eval standpat
		if (p.isQuiesce()) {
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
			moveResult = callSearch(p, -p.beta, -result.score, i == 0);
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

	if (!p.isQuiesce()) {
		Search_Transposition::addTransposition(p, result);
	}
	
	return  result;
}