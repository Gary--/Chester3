#pragma once
#include "AI_SearchConfiguration.h"
#include "AI_SearchResult.h"
#include "GameConfiguration.h"
#include "Search_SearchResult.h"

// The brains.
class Search {
public:

	// synchronously starts the search
	static void startSearch(AI_SearchConfiguration conf);


	//static void stopAsync();


	static AI_SearchResult getSearchResult();

	// Get the Game state to where you want it.
	static void configureGame(GameConfiguration conf);
	//static void makeMove(Move move);
	//static Move undoMove();

	
	

private:
	static Search_SearchResult search(int depth,int ply, int alpha, int beta);

	static void searchMakeMove(Move move);
	static Move searchUndoMove();

	static Search_SearchResult searchResult;
};