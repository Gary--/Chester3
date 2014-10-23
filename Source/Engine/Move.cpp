#include "Move.h"


Move::Move() : 
Move(MoveType::INVALID, Position(), Position(), Piece::EMPTY, Piece::EMPTY)
{
}


Move::~Move()
{
}

Move::Move(MoveType type, Position from, Position to,Piece piece, Piece targ) :
type(type), from(from), to(to), piece(piece),targ(targ){}

Move Move::RESIGN(){
	return Move(MoveType::RESIGN, Position(), Position(),Piece::EMPTY,Piece::EMPTY);
}

Move Move::NULL_MOVE(){
	return Move(MoveType::NULL_MOVE, Position(), Position(), Piece::EMPTY, Piece::EMPTY);
}
