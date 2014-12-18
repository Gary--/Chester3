#pragma once
#include "Move.h"
// Interactive console session.
class ConsoleMode {
public:

	// Starts an interactive console session.
	static void run();
private:

	static Move humanMove();
	static Move computerMove();
};