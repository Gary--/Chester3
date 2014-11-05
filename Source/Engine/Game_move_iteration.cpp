#include "Game_move_iteration.h"


AllMoveIterator::AllMoveIterator(const std::vector<Move>* const moves, uint16_t cur, bool tacticalOnly) :
moves(moves), cur(cur), tacticalOnly(tacticalOnly){}

Move AllMoveIterator::operator*()const {
	return moves->at(cur);
}

void AllMoveIterator::operator++() {
	cur++;
}

bool AllMoveIterator::operator!=(const AllMoveIterator& other) const {
	return cur != other.cur;
}




AllMoveIteratorGenerator::AllMoveIteratorGenerator(const std::vector<Move>* const moves, uint16_t start, uint16_t finish, bool tacticalOnly) :
moves(moves), start(start), finish(finish), tacticalOnly(tacticalOnly){
	_ASSERTE(start <= finish);
}

AllMoveIterator AllMoveIteratorGenerator::begin() {
	return AllMoveIterator(moves, start, tacticalOnly);
}

AllMoveIterator AllMoveIteratorGenerator::end() {
	return AllMoveIterator(moves, finish, tacticalOnly);
}