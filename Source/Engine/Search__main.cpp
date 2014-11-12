#include "Search.h"
#include "Evaluate_simple.h"
#include "Game.h"

Search_SearchResult Search::search(const int depth, const int ply, int alpha, int beta) {
	if (depth == 0) {
		Search_SearchResult result;
		//result.score = SimpleEvaluation::evaluateFull(Game::getTurn()) - 
	}
}