#pragma once
#include "Search_Configuration.h"
#include <wtypes.h>
#include "Search_SearchResult.h"

// A search terminated by the depth limit or time limit.
// Do not run more than one at once.
class SearchThread {
public:

	// Call this when the board has been set to where you want to search from.
	static void configure(Search_Configuration conf);

	// Asynchronously start. The timer will start at this point.
	static void start();

	// Asynchrounously stop the search early.
	static void stopAsync();


	// Use this if you don't want to handle the HANDLEs :P .
	static void waitForFinish();

	// Call only after getHandle() has signalled.
	static Search_SearchResult getSearchResult();

	SearchThread();
	~SearchThread();

private:
	static Search_SearchResult searchResult;
	static Search_Configuration conf;
	static HANDLE workerHandle;
	static HANDLE timerHandle;

	static unsigned __stdcall callSearch(void*);
};

