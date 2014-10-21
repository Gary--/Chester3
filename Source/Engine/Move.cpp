#include "Move.h"


Move::Move() : 
	Move(MoveType::INVALID, Position(), Position())
{
}


Move::~Move()
{
}

Move::Move(MoveType type, Position from, Position to) :
type(type), from(from), to(to){}

Move Move::RESIGN(){
	return Move(MoveType::RESIGN, Position(), Position());
}

Move Move::NULL_MOVE(){
	return Move(MoveType::NULL_MOVE, Position(), Position());
}
