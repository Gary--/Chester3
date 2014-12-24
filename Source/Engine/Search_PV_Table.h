#pragma once
#include <cstdint>
#include "Move.h"

struct PV_Entry {
public:
	uint64_t hash;
	Move move;
};

class Search_PV_Table {
public:
	static void reset();
	static void storePVMove(uint64_t hash, Move move);
	static Move getPVMove(uint64_t hash);
private:
	static const int PV_TABLE_SIZE = 10000;
	static PV_Entry pvTable[PV_TABLE_SIZE];
};