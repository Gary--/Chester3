#pragma once
#include "Move.h"
#include "AI_SearchResult.h"
// Interactive console session.
class ConsoleMode {
public:

	// Starts an interactive console session.
	static void run();
private:

	static Move humanMove();
	static AI_SearchResult computerMove();
};