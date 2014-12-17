#pragma once
#include "AI_SearchResult.h"
#include "AI_SearchConfiguration.h"
#include "GameConfiguration.h"


// Interface with the UCI protocol
// Manages the worker thread
class AI {

public:
	// Set the Game state.
	static void configureGame(GameConfiguration conf);

	// Used to control the Game state
	static void makeMove(Move move);

	// Used to control the Game state
	static Move undoMove();


	static void configureSearch(AI_SearchConfiguration conf);
	static void startSearch();

	// When this returns, Game state will be reset.
	static void stopSearch();

	static AI_SearchResult getSearchResult(); 

private:
	static AI_SearchConfiguration searchConfiguration;
};