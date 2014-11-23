#include "Game_MoveIterator.h"


GameMoveIterator::GameMoveIterator(const std::vector<Move>* const moves, 
								   const  uint16_t cur, const  uint8_t left, const  bool tacticalOnly) :
moves(moves), cur(cur), left(left), tacticalOnly(tacticalOnly){
	if (left && tacticalOnly && !(**this).isTactical()) {
		++(*this);
	}
}

Move GameMoveIterator::operator*()const {
	return moves->at(cur);
}

void GameMoveIterator::operator++() {

	do {
		cur++;
		left--;
	} while (tacticalOnly && left && !(**this).isTactical());

}

bool GameMoveIterator::operator!=(const GameMoveIterator& other) const {
	return cur != other.cur;
}




GameMoveIteratorGenerator::GameMoveIteratorGenerator(const std::vector<Move>* const moves, 
													 const  uint16_t start, const  uint16_t finish, const  bool tacticalOnly) :
moves(moves), start(start), finish(finish), tacticalOnly(tacticalOnly){
	_ASSERTE(start <= finish);
}

GameMoveIterator GameMoveIteratorGenerator::begin() {
	return GameMoveIterator(moves, start, finish-start, tacticalOnly);
}

GameMoveIterator GameMoveIteratorGenerator::end() {
	return GameMoveIterator(moves, finish, 0, tacticalOnly);
}