#pragma once

struct SearchConfiguration {
	int searchTimeMs;
	bool mateOnly;
	int maxDepth;

	static const int MAX_DEPTH_INF = -1;
	static const int SEARCH_TIME_INF = -1;

private:

};