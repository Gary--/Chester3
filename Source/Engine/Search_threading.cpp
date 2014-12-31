#include "Search.h"
#include <process.h>

using namespace std;


bool Search::shouldStopSearch() {
	return canExit && exitSignal;
}


void Search::signalStop() {
	exitSignal = true;
}


void Search::prepareSearch() {
	canExit = false;
	exitSignal = false;
	synchronize();
}


