#include <iostream>
#include "Position.h"
#include "BitBoard.h"
#include "Game.h"
using namespace std;

int main() {
	GameConfiguration conf("rnbqkbnr/ppp1p1pp/8/8/3p1p2/8/PPPPPPPP/RNBQKBNR w - -");
	Game::configure(conf);

	Game::makeMove(Move(MoveType::PAWN_JUMP, Position("e2"), Position("e4"), Piece::PAWN, Piece::EMPTY));

	return 0;
}