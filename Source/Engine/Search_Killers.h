#pragma once
#include "Search_Parameters.h"
#include "Move.h"
class Search_Killers {
public:
	static void reset();
	static void addKiller(Search_Parameters params, Move move);
	static bool isKiller(Search_Parameters params, Move move);
private:
	static const int nKillers = 2;
	static Move killers[Search_Parameters::MAX_NORMAL_PLY][nKillers];
};