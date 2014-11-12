#pragma once
#include "AI_search_result.h"
#include "AI_search_configuration.h"
#include "GameConfiguration.h"


// Interface with the UCI protocol
// Manages the worker thread
class AI {

public:
	static void configureGame(GameConfiguration conf);
	static void makeMove(Move move);
	static Move undoMove();

	// Free the memory used to support undo feature.
	static void clearHistory();
	
	static void configureSearch(SearchConfiguration conf);
	static void startSearch();

	// When this returns, Game state will be reset.
	static void stop();

	static SearchResult getSearchResult();

//private:
//	
//	pthread_t 
};