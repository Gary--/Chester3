#pragma once
#include "Move.h"

// Given back to the UI thread
struct AI_SearchResult {
	int score;
	Move bestMove;

};