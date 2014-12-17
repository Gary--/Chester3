#include "Search.h"
#include "SimpleEvaluation.h"
#include "Game.h"

Search_SearchResult Search::quiescenceSearch(int ply, int alpha, int beta) {
	Search_SearchResult result;
	result.score = SimpleEvaluation::all(Game::getTurn());
	return result;
}