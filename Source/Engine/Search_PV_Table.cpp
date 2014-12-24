#include "Search_PV_Table.h"



PV_Entry Search_PV_Table::pvTable[Search_PV_Table::PV_TABLE_SIZE];

void Search_PV_Table::storePVMove(uint64_t hash, Move move) {
	pvTable[hash%PV_TABLE_SIZE].hash = hash;
	pvTable[hash%PV_TABLE_SIZE].move = move;
}

Move Search_PV_Table::getPVMove(uint64_t hash) {
	return pvTable[hash%PV_TABLE_SIZE].move;
}
