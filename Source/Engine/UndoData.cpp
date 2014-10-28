#include "UndoData.h"

UndoData::UndoData(Move move, GameHash hash,int numMovesAvail,bool check) :
move(move), hash(hash),numMovesAvailable(numMovesAvail),check(check) {}