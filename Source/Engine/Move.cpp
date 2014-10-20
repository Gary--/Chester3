#include "Move.h"


Move::Move() : type(MoveType::INVALID), from(Position()), to(Position())
{
}


Move::~Move()
{
}

Move::Move(MoveType type, Position from, Position to) :
type(type), from(from), to(to){}