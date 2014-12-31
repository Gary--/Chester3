#pragma once
#include "Move.h"
#include "Search_SearchResult.h"

// Interactive console session.
class ConsoleMode {
public:

	// Starts an interactive console session.
	static void run();
private:

	static Move humanMove();
	static Search_SearchResult computerMove();
};