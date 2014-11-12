#pragma once

struct SearchConfiguration {
	SearchConfiguration();

	int maxTimeMs;
	int maxDepth;
	bool mateOnly;
	

	static const int MAX_DEPTH_INF = -1;
	static const int SEARCH_TIME_INF = -1;

private:

};