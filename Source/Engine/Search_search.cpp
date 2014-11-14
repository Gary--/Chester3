#include "Search.h"
#include "SimpleEvaluation.h"
#include <cstdint>
#include "Game.h"
#include <algorithm>
#include <iostream>
using namespace std;

Search_SearchResult Search::search(const int depth, const int ply,const int alpha,const int beta) {

	if (!Game::areMovesAvailable()) {
		Search_SearchResult result;
		if (Game::getCheck()) {// We got checkmated.
			result.score = -Search_SearchResult::MATE_SCORE;
		} else {// Stalemate.
			result.score = 0;
		}
		return result;
	}

	if (depth == 0) {
		Search_SearchResult result;
		result.score = SimpleEvaluation::evaluate();
		return result;
	}
	
	Move bestMove = Move::INVALID();
	int bestScore = alpha;

	for (const Move move : Game::getAllMoves()) {

		if (depth == 5 && move.getTo() == Position("d1")) {
			cout << "";
		}

		searchMakeMove(move);
		const Search_SearchResult moveResult = search(depth - 1, ply + 1, -beta, -bestScore);
		searchUndoMove();

		{
			const int moveScore = -moveResult.score;
			if (moveScore > bestScore) {
				bestScore = moveScore;
				bestMove = move;
			}
		}

		if (bestScore >= beta) {
			Search_SearchResult result;
			result.score = beta;
			result.bestMove = bestMove;
			return result;
		}
	}

	Search_SearchResult result;
	result.score = bestScore;
	result.bestMove = bestMove;
	return result;
}