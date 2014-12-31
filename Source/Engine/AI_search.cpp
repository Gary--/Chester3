#include "AI.h"
#include "Search.h"

void AI::startSearch() {
	Search::startSearchImpl(searchConfiguration);
}

void AI::stopSearch() {
	return;
}