#include "Game.h"
#include "Game_UndoData.h"

namespace {
	BitBoard scratch;
}

BitBoard* Game::s(const Turn turn, const  Piece piece) {
	return &pieces[turn.asIndex()][piece.asIndex()];
}

BitBoard* Game::sp(const Turn turn) {
	return &playerPieces[turn.asIndex()];
}

void Game::toggleBit(const Turn turn, const  Position position, const  Piece piece) {
	*s(turn, piece) ^= position.asSingletonBitboard();
	*sp(turn) ^= position.asSingletonBitboard();
	ALL ^= position.asSingletonBitboard();

	//hash.togglePiece(position, turn, piece);
}


void Game::clearPieceAt(const Position position) {
	const Piece piece = getPieceAt(position);
	if (piece == Piece::EMPTY()) {
		return;
	}

	const Turn turn = getOwnerAt(position);
	
	*s(turn, piece) &= ~position.asSingletonBitboard();
	*sp(turn) &= ~position.asSingletonBitboard();
	ALL &= ~position.asSingletonBitboard();

	setPieceAt(position, Piece::EMPTY());

	cur.hash.togglePiece(position, turn, piece);
}
void Game::addPieceAt(const Turn turn, const Position position, const Piece piece) {
	*s(turn, piece) |= position.asSingletonBitboard();
	*sp(turn) |= position.asSingletonBitboard();
	ALL |= position.asSingletonBitboard();
	setPieceAt(position, piece);
	cur.hash.togglePiece(position, turn, piece);
}


void Game::setPieceAt(const Position position, const Piece piece) {
	pieceTypes[position.index()] = piece;
}