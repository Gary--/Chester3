#pragma once
#include "Search_Configuration.h"
#include <wtypes.h>
#include "Search_SearchResult.h"
#include "SearchThreadCallBack.h"
#include <atomic>


// A search terminated by the depth limit or time limit.
// Do not run more than one at once.
class SearchThread {
public:
	// Do not use this if search is running
	static void setSearchConfiguration(Search_Configuration conf);

	// Do not use this if search is running
	static void setCallBack(SearchThreadCallBack* callBackPtr);

	// Asynchronously start. The timer will start at this point.
	static void start();

	// Asynchrounously stop the search early.
	static void stopAsync();

	// Call this to indicate the engine can exit from INFINITE. stopAsync calls this
	static void allowStop();

	// Wait for the worker thread to exit.
	static void waitForFinish();

	// Call only after getHandle() has signalled.
	static Search_SearchResult getSearchResult();

	// Call after 

private:
	static Search_SearchResult searchResult;

	// The worker thread. Thread termination limited by search depth, time, and endSearchEvent
	static HANDLE workerHandle;
	static SearchThreadCallBack* callBack;
	static Search_Configuration conf;

	static unsigned __stdcall callSearch(void* param);
	static unsigned __stdcall callSearchWithTimeLimit(void* param);

	// If the search time was infinite, worker handle thread waits for this event too
	static HANDLE endSearchAllowedEvent;

	static std::atomic<bool> stopRequested;

	static SearchTerminationCondition condition;

	static unsigned __stdcall makeCallBack(void* param);
};

