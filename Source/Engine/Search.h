#pragma once
#include "Search_Configuration.h"
#include "GameConfiguration.h"
#include "Search_SearchResult.h"
#include "Search_Parameters.h"

// The brains.
// Configure Game to where you want and call startSearch.
class Search {
public:
	// Call this before
	static void prepareSearch();


	// Asynchronously tell the search thread to exit ASAP.
	static void signalStop();

	// How many null moves have been made.
	static int nNullsMade;


	// Synchronously starts the search. The thread should be created to run this method.
	static Search_SearchResult startSearch(Search_Configuration conf);

private:
	friend class MoveOrdering;



	static volatile bool exitSignal;

	// Have we done a minimum amount of work needed for exit? IE have a best move of some depth?
	static bool canExit;

	// The search method will poll this to see if it should continue to search.
	static bool shouldStopSearch();


	// Synchronize everything with Game.
	static void synchronize();

	// Called after already made move
	static Search_SearchResult callSearch(Search_Parameters previousParams, int alpha, int beta, int moveNum);

	static Search_SearchResult search(Search_Parameters params);
	static int nChecks;
	static int reduction1;

	static Search_SearchResult nullMoveSearch(Search_Parameters params);


	static void searchMakeMove(Move move);
	static Move searchUndoMove();


	static Search_SearchResult gameOverScore();
};
