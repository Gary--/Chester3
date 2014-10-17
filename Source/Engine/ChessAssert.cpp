#include "ChessAssert.h"
#include <crtdbg.h>

ChessAssert::ChessAssert()
{
}


ChessAssert::~ChessAssert()
{
}

void ChessAssert::Assert_64(int x)
{
	_ASSERTE(0 <= x && x<64);
}


void ChessAssert::Assert_8(int x)
{
	_ASSERTE(0<=x && x<8);
}
