#pragma once
class Search_Counter {


public:
	void reset();
	static int full;
	static int quiesce;
	static int captures;
	static int goodCaptures;
	static int nullSearches;
	static int researches;
};

