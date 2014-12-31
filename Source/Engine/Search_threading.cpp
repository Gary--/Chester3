#include "Search.h"
#include <process.h>

using namespace std;


bool Search::shouldStopSearch() {
	return canExit && exitSignal;
}



unsigned int __stdcall Search::startSearch(void* confPtr) {
	const Search_Configuration conf = *(Search_Configuration*)confPtr;

	startSearchImpl(conf);

	return 0;
}



HANDLE Search::getSearchHandle(Search_Configuration conf) {
	canExit = false;
	exitSignal = false;
	synchronize();

	HANDLE handle = (HANDLE)_beginthreadex(NULL, // security
												  0,             // stack size
												  startSearch,// entry-point-function
												  (void*)&conf,           // arg list holding the "this" pointer
												  CREATE_SUSPENDED, // so we can later call ResumeThread()
												  NULL// thread ID
												  );
	if (handle == INVALID_HANDLE_VALUE) {
		throw exception("Could not create a search thread.");
	}
	return handle;
}

