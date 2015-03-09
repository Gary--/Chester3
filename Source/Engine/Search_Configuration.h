#pragma once

struct Search_Configuration {
	Search_Configuration();

	int maxDepth;
	int maxTimeMs;
	bool ponder;
	int btime, wtime, winc, binc;
	bool infinite;

	static const int MAX_DEPTH_INF = 50;
	static const int SEARCH_TIME_INF = 10000000;

private:

};