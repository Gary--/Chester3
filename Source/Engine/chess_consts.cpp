#include "chess_consts.h"
#include <crtdbg.h>
#include <iostream>


#include "BitBoard.h"
using namespace std;


Piece randPiece() {
	return (Piece)(1 + rand() % 6);
}

Side operator!(Side side) {
#pragma warning(disable : 4800) //Forcing to bool
	return (Side)(!(bool)side);
#pragma warning(default : 4800)
}

#pragma region Turn
Turn::Turn() : value(false) {}
Turn::Turn(bool value) : value(value) {}

Turn Turn::operator!() const {
	return Turn(!value);
}

bool Turn::asIndex() const {
	return value;
}

Turn Turn::fromChar(char c) {
	return ('a' <= c && c < 'z') ? Turn::BLACK() : Turn::WHITE();
}

Turn Turn::BLACK() {
	return Turn(false);
}

Turn Turn::WHITE() {
	return Turn(true);
}

bool Turn::operator==(const Turn other) const {
	return value == other.value;
}
bool Turn::operator!=(const Turn other) const {
	return !(*this == other);
}

#pragma endregion


Piece ChessUtils::pieceFromChar(char c) {
	if ('a' <= c && c < 'z') {
		c -= 'a' - 'A';
	}

	switch (c) {
	case 'K': return Piece::KING;
	case 'Q': return Piece::QUEEN;
	case 'R': return Piece::ROOK;
	case 'B': return Piece::BISHOP;
	case 'N': return Piece::KNIGHT;
	case 'P': return Piece::PAWN;
	case '.': return Piece::EMPTY;


	default:
		_ASSERT(false);
		return Piece::UNKNOWN;
		break;

	}
}



char ChessUtils::charFromPieceTurn(Turn turn, Piece piece) {
	char res='?';

	switch (piece) {
	case Piece::KING: res = 'K'; break;
	case Piece::QUEEN: res = 'Q'; break;
	case Piece::ROOK: res = 'R'; break;
	case Piece::BISHOP: res = 'B'; break;
	case Piece::KNIGHT: res = 'N'; break;
	case Piece::PAWN: res = 'P'; break;
	case Piece::EMPTY: return '.'; break;

	default:
		_ASSERT(false);
		break;
	}

	if (turn == Turn::BLACK()) {
		res += 'a' - 'A';
	}
	
	return res;
}