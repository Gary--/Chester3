#pragma once
#include "AI_SearchConfiguration.h"
#include "AI_SearchResult.h"
#include "GameConfiguration.h"
#include "Search_SearchResult.h"
#include "Search_Parameters.h"
// The brains.
// Configure Game to where you want and call startSearch.
class Search {
public:

	// synchronously starts the search
	static void startSearch(AI_SearchConfiguration conf);
	static AI_SearchResult getSearchResult();


	
	

private:
	static void synchronize();

	// Called after already made move
	static Search_SearchResult callSearch(Search_Parameters previousParams, int bestScore);

	static Search_SearchResult search(Search_Parameters params);

	static Search_SearchResult callQuiescenceSearch(Search_Parameters previousParams, int bestScore);
	static Search_SearchResult quiescenceSearch(Search_Parameters params);

	static Search_SearchResult nullMoveSearch(Search_Parameters params);

	static void searchMakeMove(Move move);
	static Move searchUndoMove();

	static Search_SearchResult searchResult;

	static Search_SearchResult gameOverScore();
};