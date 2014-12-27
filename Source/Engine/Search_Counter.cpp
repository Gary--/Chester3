#include "Search_Counter.h"


void Search_Counter::reset() {
	full = 0;
	quiesce = 0;
	captures = 0;
	goodCaptures = 0;
	nullSearches = 0;
	researches = 0;
}

int Search_Counter::researches=0;

int Search_Counter::nullSearches=0;

int Search_Counter::goodCaptures = 0;

int Search_Counter::captures = 0;

int Search_Counter::quiesce = 0;

int Search_Counter::full = 0;
