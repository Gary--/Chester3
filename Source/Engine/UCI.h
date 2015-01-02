#pragma once
#include <string>
#include "SearchThreadCallBack.h"

class UCI {
public:
	// Call this after recieving the "uci" command
	static void run();

private:
	friend class UCISearchThreadCallBack;

	static void searchCallback(SearchTerminationCondition condition);

	// Initial response after recieving the "uci" command
	static void identify();
	static void ouputBestMove();
	static void position(const std::string& line);
	static void stopSearchThread();
};

