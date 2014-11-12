#include "AI_search_configuration.h"

SearchConfiguration::SearchConfiguration() {
	maxTimeMs = SEARCH_TIME_INF;
	maxDepth = MAX_DEPTH_INF;
	mateOnly = false;
}