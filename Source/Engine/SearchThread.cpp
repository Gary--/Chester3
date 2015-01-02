#include "SearchThread.h"
#include "Search.h"
#include <stdio.h>
#include <process.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>

using namespace std;

HANDLE SearchThread::endSearchAllowedEvent;
Search_Configuration SearchThread::conf;
SearchThreadCallBack* SearchThread::callBack;
HANDLE SearchThread::workerHandle;
Search_SearchResult SearchThread::searchResult;
std::atomic<bool> SearchThread::stopRequested;
SearchTerminationCondition SearchThread::condition;



unsigned __stdcall SearchThread::callSearch(void* param) {
	const Search_Configuration conf = *(Search_Configuration*)param;
	searchResult = Search::startSearch(conf);
	return 0;
}


unsigned __stdcall SearchThread::callSearchWithTimeLimit(void* param) {
	Search_Configuration conf = *(Search_Configuration*) param;
	const int time = conf.maxTimeMs;
	bool isForeverSearch = time == Search_Configuration::SEARCH_TIME_INF;


	HANDLE searchHandle = (HANDLE)_beginthreadex(NULL, // security
										   0,            // stack size
										   callSearch,// entry-point-function
										   param,           // arg list holding the "this" pointer
										   CREATE_SUSPENDED, // so we can later call ResumeThread()
										   NULL// thread ID
										   );

	ResumeThread(searchHandle);

	const bool timeLimitExceeded = WAIT_OBJECT_0 != WaitForSingleObject(searchHandle, isForeverSearch ? INFINITE : time);


	Search::signalStop();
	WaitForSingleObject(searchHandle, INFINITE);

	WaitForSingleObject(endSearchAllowedEvent, INFINITE);


	if (timeLimitExceeded) {
		condition = SearchTerminationCondition::TIME_EXCEEDED;
	} else if (stopRequested) {
		condition = SearchTerminationCondition::STOP_REQUESTED;
	} else {
		condition = SearchTerminationCondition::DEPTH_REACHED;
	}

	if (callBack) {
		HANDLE callbackHandle = (HANDLE)_beginthreadex(NULL, // security
													 0,            // stack size
													 makeCallBack,// entry-point-function
													 param,           // arg list holding the "this" pointer
													 CREATE_SUSPENDED, // so we can later call ResumeThread()
													 NULL// thread ID
													 );

		ResumeThread(callbackHandle);
	}

	return 0;
}





void SearchThread::start() {
	condition = SearchTerminationCondition::INVALID;
	stopRequested = false;
	Search::prepareSearch();

	const int time = conf.maxTimeMs;
	bool isForeverSearch = time == Search_Configuration::SEARCH_TIME_INF;
	endSearchAllowedEvent = CreateEvent(
		NULL,               // default security attributes
		TRUE,               // manual-reset event
		!isForeverSearch,              // If searching forever, set as non-signaled
		NULL  // object name
		);


	workerHandle = (HANDLE)_beginthreadex(NULL, // security
										  0,             // stack size
										  callSearchWithTimeLimit,// entry-point-function
										  &conf,           // arg list holding the "this" pointer
										  CREATE_SUSPENDED, // so we can later call ResumeThread()
										  NULL// thread ID
										  );
	ResumeThread(workerHandle);

}


void SearchThread::allowStop() {
	SetEvent(endSearchAllowedEvent);
}



void SearchThread::stopAsync() {
	stopRequested = true;
	Search::signalStop();
	allowStop();
}

void SearchThread::waitForFinish() {
	WaitForSingleObject(workerHandle, INFINITE);
}

Search_SearchResult SearchThread::getSearchResult() {
	return searchResult;
}

void SearchThread::setCallBack(SearchThreadCallBack* callBackPtr) {
	callBack = callBackPtr;
}

void SearchThread::setSearchConfiguration(Search_Configuration conf) {
	SearchThread::conf = conf;
}

unsigned __stdcall SearchThread::makeCallBack(void* param) {

	//TODO lock callback
	if (callBack) {
		callBack->stCallbackFunction(condition);
	}
	return 0;
}



