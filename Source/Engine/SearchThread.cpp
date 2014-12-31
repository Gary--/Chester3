#include "SearchThread.h"
#include "Search.h"
#include <stdio.h>
#include <process.h>

HANDLE SearchThread::timerHandle;
HANDLE SearchThread::workerHandle;

Search_Configuration SearchThread::conf;
Search_SearchResult SearchThread::searchResult;


void SearchThread::configure(Search_Configuration conf) {
	SearchThread::conf = conf;
	Search::prepareSearch();
}

unsigned __stdcall SearchThread::callSearch(void* param) {
	searchResult = Search::startSearch(conf);

	return 0;
}

void SearchThread::start() {
	workerHandle = (HANDLE)_beginthreadex(NULL, // security
										   0,             // stack size
										   callSearch,// entry-point-function
										   NULL,           // arg list holding the "this" pointer
										   CREATE_SUSPENDED, // so we can later call ResumeThread()
										   NULL// thread ID
										   );


	{
		timerHandle = CreateWaitableTimer(NULL, TRUE, NULL);
		LARGE_INTEGER liDueTime;
		liDueTime.QuadPart = -10000LL * conf.maxTimeMs;
		if (!SetWaitableTimer(timerHandle, &liDueTime, 0, NULL, NULL, 0)) {
			printf("SetWaitableTimer failed (%d)\n", GetLastError());
		}
	}

	ResumeThread(workerHandle);


}

void SearchThread::stopAsync() {
	Search::signalStop();
}

void SearchThread::waitForFinish() {
	HANDLE handles[2] = { workerHandle, timerHandle };
	WaitForMultipleObjects(_countof(handles), handles, false, INFINITE);

	stopAsync();
	WaitForSingleObject(workerHandle, INFINITE);
}

Search_SearchResult SearchThread::getSearchResult() {
	return searchResult;
}




