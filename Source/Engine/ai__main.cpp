#include "AI.h"
#include "Game.h"
#include "AI_SearchConfiguration.h"
#include "Search.h"

AI_SearchConfiguration AI::searchConfiguration;


void AI::configureSearch(AI_SearchConfiguration conf) {
	searchConfiguration = conf;
}

AI_SearchResult AI::getSearchResult() {
	return Search::getSearchResult();
}
