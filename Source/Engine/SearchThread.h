#pragma once
#include "Search_Configuration.h"
#include <wtypes.h>
#include "Search_SearchResult.h"

// A search terminated by the depth limit or time limit.
// Do not run more than one at once.
class SearchThread {
public:
	SearchThread(Search_Configuration conf);

	// Asynchronously start. The timer will start at this point.
	void start();

	// Handle to the worker thread. Wait on this.
	const HANDLE getHandle() const;

	// Asynchrounously stop the search early.
	void stopAsync();


	// Use this if you don't want to handle the HANDLEs :P .
	void waitForFinish();

	// Call only after getHandle() has signalled.
	Search_SearchResult getSearchResult() const;

	SearchThread();
	~SearchThread();

private:
	HANDLE workerHandle;
	HANDLE timerHandle;
};

