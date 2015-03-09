#pragma once
#include "Search_Configuration.h"
#include <mutex>
#include <thread>
#include <atomic>
class UCI {
public:
	static void run();
private:

	// Commands
	static void identify();
	static void position(const std::string& line);

	static void stopSearch();
	static void startSearch();
	static void allowStop();

	static Search_Configuration conf;


	

	// Signal a stop after givne milliseconds
	static void setStopSearchDelay(int ms);
	static void searchStopper(int ms,int count);

	static std::mutex mtx;
	static std::thread searchThread;
	static std::atomic<int> searchCount;
	
};

