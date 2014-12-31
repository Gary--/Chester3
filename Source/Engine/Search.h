#pragma once
#include "Search_Configuration.h"
#include "GameConfiguration.h"
#include "Search_SearchResult.h"
#include "Search_Parameters.h"
#include <atomic>
#include <wtypes.h>


// The brains.
// Configure Game to where you want and call startSearch.
class Search {
public:

	
	
	static HANDLE getSearchHandle(Search_Configuration conf);

	// Call this only when the search thread has exited.
	static Search_SearchResult getSearchResult();

	// Asynchronously tell the search thread to exit ASAP.
	static void signalStop();
	
	// How many null moves have been made.
	static int nNullsMade;

private:
	friend class MoveOrdering;

	// Calls startSearchImpl
	static unsigned int __stdcall  startSearch(void* conf);

	// Synchronously starts the search. The thead should be created to run this method.
	static void startSearchImpl(Search_Configuration conf);
	static std::atomic<bool> exitSignal;

	// Have we done a minimum amount of work needed for exit? IE have a best move of some depth?
	static bool canExit;

	// The search method will poll this to see if it should continue to search.
	static bool shouldStopSearch();

	
	
	static void synchronize();

	// Called after already made move
	static Search_SearchResult callSearch(Search_Parameters previousParams, int alpha, int beta, int moveNum);

	static Search_SearchResult search(Search_Parameters params);
	static int nChecks;
	static int reduction1;

	static Search_SearchResult nullMoveSearch(Search_Parameters params);

	
	static void searchMakeMove(Move move);
	static Move searchUndoMove();

	static Search_SearchResult searchResult;

	static Search_SearchResult gameOverScore();
};
