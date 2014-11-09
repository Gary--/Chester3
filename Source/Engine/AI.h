#pragma once
#include "AI_search_result.h"
#include "AI_search_configuration.h"
class AI {

public:
	static void makeMove(Move move);
	
	static void startSearch(SearchConfiguration conf);

	// When this returns, Game state will be reset.
	static void stop();

	static SearchResult getSearchResult();

private:

};