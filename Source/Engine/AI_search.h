#pragma once
#include "AI_search_result.h"
#include "AI_search_configuration.h"
class Search {
public:

	// Takes a SearchConfiguration
	static void startSearch(SearchConfiguration conf);

	static void stopAsync();
	static SearchResult getSearchResult();
	
};