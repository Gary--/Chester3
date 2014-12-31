#include "Search.h"

using namespace std;


bool Search::shouldStopSearch() {
	return canExit && exitSignal;
}


void Search::prepareSearchStart() {
	canExit = false;
	exitSignal = false;
}

