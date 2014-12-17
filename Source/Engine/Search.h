#pragma once
#include "AI_SearchConfiguration.h"
#include "AI_SearchResult.h"
#include "GameConfiguration.h"
#include "Search_SearchResult.h"

// The brains.
// Configure Game to where you want and call startSearch.
class Search {
public:

	// synchronously starts the search
	static void startSearch(AI_SearchConfiguration conf);
	static AI_SearchResult getSearchResult();


	
	

private:
	static void synchronize();

	static Search_SearchResult search(int depth,int ply, int alpha, int beta);
	static Search_SearchResult quiescenceSearch(int ply, int alpha, int beta);

	static void searchMakeMove(Move move);
	static Move searchUndoMove();

	static Search_SearchResult searchResult;
};