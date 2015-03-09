#pragma once
#include "Search_Configuration.h"
#include <mutex>
#include <thread>
#include <atomic>
#include "Search_SearchResult.h"
class UCI {
public:
	static void run();
private:

	// Commands
	static void identify();
	static void position(const std::string& line);

	static void stopSearch();
	static void startSearch();
	static void searchEntry();
	
	static void allowStop();

	static Search_Configuration conf;
	static Search_SearchResult result;

	static void populateConf(const std::string& line);
	static void go(const std::string& line);
	static int decideSearchTime();

	// Signal a stop after givne milliseconds
	static void setStopSearchDelay(int ms);
	static void searchStopper(int ms,int count);

	static std::mutex mtx;
	static std::thread searchThread;
	static std::atomic<int> searchCount;

	
};

