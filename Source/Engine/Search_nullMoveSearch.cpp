#include "Search.h"
#include "Game.h"

namespace {
	bool hasStuff(Turn turn) {//not just pawns left
		return Game::getPlayerPieces(turn).count() > Game::getPieces(turn, Piece::PAWN()).count() + 1;
	}
}

Search_SearchResult Search::nullMoveSearch(const Search_Parameters p) {
	Search_SearchResult result;
	if (p.isQuiesce()) {
		return result;
	}

	
	
	if (p.depth >= 3 && 
		!Game::getCheck() &&
		hasStuff(Turn::WHITE()) &&
		hasStuff(Turn::BLACK())
		) {
		Search_Parameters newParams;
		newParams.alpha = -p.beta;
		newParams.beta = -(p.beta - 1);
		newParams.ply = p.ply + 1;

		newParams.depth = p.depth == 3 ? 1 : p.depth - 3;

		Search::searchMakeMove(Move::NULL_MOVE());
		const Search_SearchResult nullMoveResult = search(newParams);
		Search::searchUndoMove();


		result.score = -nullMoveResult.score;
		
	}

	return result;
}