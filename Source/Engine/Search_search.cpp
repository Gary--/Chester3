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
#include <stdlib.h>
#include "StaticExchange.h"
#include "AttackFields.h"
using namespace std;



namespace {
	int reduction1_margin[] = { 0, 0, 0, 500, 500, 700, 700, 900,
		900, 1500 };

	const int fullPlys = 4;
	const int ReductionLimit = 3;
}



Search_SearchResult Search::callSearch(const Search_Parameters previousParams,const int alpha,const int beta,int moveNum) {
	const Move move = Game::getPreviousMove();
	const EvaluationScore prevScore = EvaluationManager::getScore(1);
	const bool wasInCheck = prevScore.getCheck();
	bool isPseudoMate = Evaluation::mating(Turn::WHITE()) != 0;
	const Turn turn = !Game::getTurn();

	Search_Parameters newParams;
	newParams.depth = previousParams.depth - 1;
	newParams.ply = previousParams.ply + 1;
	newParams.alpha = alpha;
	newParams.beta = beta;

	bool extended = false;
	if (moveNum==0 && previousParams.pv.next) {
		newParams.pv = *previousParams.pv.next;
	}

	// Check extension
	if (!previousParams.isQuiesce() && EvaluationManager::getScore(1).getCheck() && nChecks>1) {
		newParams.depth++;
		extended = true;
	}

	bool reduced = false;

	// Material disadvantage reduction
	bool doReduction1 = false;
	bool possibleReduction = 
		!newParams.isQuiesce() &&
		!move.isTactical() &&
		!Game::getCheck() &&
		!wasInCheck &&
		moveNum != 0 &&
		!isPseudoMate &&
		!extended;


	if (possibleReduction) do {
		int prevPressure = prevScore.getKingDanger(!turn);
		if (Search_History::getHistory(move) > 0) {
			possibleReduction = false;
			break;
		}

		// Increasing pressure on their king
		if (EvaluationManager::getScore().getKingDanger(!turn) > prevPressure) {
			possibleReduction = false;
		}

	} while (false);


	if (!reduced && !reduction1 && possibleReduction && newParams.depth > 2) {
		const int margin = newParams.depth < _countof(reduction1_margin) ? reduction1_margin[newParams.depth] : reduction1_margin[_countof(reduction1_margin) - 1];
		
		if (-newParams.beta >  EvaluationManager::getRelativeSimpleScore(turn) + margin) {
			doReduction1 = reduced = true;

			newParams.depth--;
		}
	}

	// Late move reductions
	if (!reduced && moveNum >= fullPlys && newParams.depth >= ReductionLimit && possibleReduction && beta==alpha+1) {
		newParams.depth--;
		reduced = true;
	}

	const auto result = search(newParams);


	if (doReduction1) {
		reduction1 = false;
	}

	return result;
}

Search_SearchResult Search::search(const Search_Parameters p) {
	if (shouldStopSearch()) {
		return Search_SearchResult();
	}

	// Are we in a mate that we know how to do?


	if (p.isQuiesce()) {
		Search_Counter::quiesce++;
	} else {
		Search_Counter::full++;
	}


	const int pseudoMateScore = Evaluation::mating(Game::getTurn());
	const bool isPseudoMate = pseudoMateScore != 0;
	const bool isOurPseudoMate = pseudoMateScore > 0;


	Search_SearchResult result;
	result.score = p.alpha;
	if (!Game::areMovesAvailable()) {
		return gameOverScore();
	}

	if (p.ply > 0 && Game::getRepeatCount() > 1) {
		result.score = 0;
		return result;
	}

	if (p.isQuiesce() && isOurPseudoMate) {
		result.score = pseudoMateScore;
		return result;
	}

	if (Game::getRepeatCount()==1) {
		TTItem ttRes = Search_Transposition::getTransposition(p);
		if (ttRes.depth >= p.depth) {
			if (ttRes.type == TT_Entry_Type::LOWER_BOUND && ttRes.score >= p.beta) {
				result.score = ttRes.score;
				result.pv.move = ttRes.bestMove;
				return result;
			}

			if (ttRes.type == TT_Entry_Type::EXACT && p.beta == p.alpha+1) {
				result.score = ttRes.score;
				result.pv.move = ttRes.bestMove;
				return result;
			}

			if (ttRes.type == TT_Entry_Type::UPPER_BOUND && ttRes.score <= p.alpha) {
				result.score = ttRes.score;
				return result;
			}
		}
	}




	if (p.ply > 0){
		const auto prevScore = EvaluationManager::getScore(1);
		const bool wasInCheck = prevScore.getCheck();


		if (p.depth <= 1 && !wasInCheck && !Game::getCheck() && !isPseudoMate) do {
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

		// Do we want to try quiesce at all?
		if (p.isQuiesce() && !Game::getCheck() && !wasInCheck && !isPseudoMate) {
			const Turn turn = Game::getTurn();
			AttackMap::precompute();
			const int curFullScore = EvaluationManager::getScore().getOverall(turn);
			if (curFullScore - 900 >= p.beta) {
				result.score = p.beta;
				return result;
			}

			int margin = 300;
			int maxHangingVal = -1;
			for (Move move : Game::getTacticalMoves()) {
				maxHangingVal = max(maxHangingVal, 100*StaticExchange::materialChange(move));
			}
			margin += maxHangingVal;

			const BitBoard theirPromoZone = AttackFields::pawnPromoZone(!turn);
			const BitBoard TP = Game::getPieces(!turn, Piece::PAWN());
			const BitBoard ALL = Game::getAllPieces();
			const BitBoard theirPromotablePawns = (TP&theirPromoZone).shiftForward(!turn)&~ALL;
			if (theirPromotablePawns.isNotEmpty()) {
				margin += 600;
			}

			
			if (curFullScore + margin < p.alpha) {
				result.score = p.alpha;
				return result;
			}


		}

		// Try a full eval standpat
		if (p.isQuiesce() && !isPseudoMate) {
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


	AttackMap::precompute();
	EvaluationManager::calcScoreCurrent();

	if (!p.isQuiesce()){
		const Search_SearchResult nullMoveResult = nullMoveSearch(p);
		if (nullMoveResult.score >= p.beta) {
			return nullMoveResult;
		}
	}

	MoveOrdering orderedMoves = MoveOrdering(p, (!p.isQuiesce() || Game::getCheck() || isPseudoMate) ? Game::getAllMoves() : Game::getTacticalMoves());

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
		moveResult = callSearch(p, useNullWindow ? -result.score-1 : -p.beta, -result.score, i );
		searchUndoMove();
		Search_Counter::nullSearches += useNullWindow;
		// Re-search
		if (useNullWindow && (-moveResult.score > result.score) && (-moveResult.score < p.beta)) {
			Search_Counter::researches++;
			searchMakeMove(move);
			moveResult = callSearch(p, -p.beta, -result.score, i );
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
	
	if (shouldStopSearch()) {
		return Search_SearchResult();
	}

	result.adjustForMateScore();

	if (!p.isQuiesce()) {
		Search_Transposition::addTransposition(p, result);
	}

	
	return  result;
}