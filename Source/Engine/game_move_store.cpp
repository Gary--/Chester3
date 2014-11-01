#include "Game.h"
#include "attack_fields.h"

void Game::addMove(Move move) {
	moves.push_back(move);
	numMovesAvail++;
}

void Game::addPawnMove(Move move) {
	if (AttackFields::pawnPromoZone(curTurn).contains(move.getFrom())) {
		FOR_PIECE(promo, Piece::KNIGHT, Piece::QUEEN) {
			addMove(Move(promoType(promo), move.getFrom(), move.getTo(), Piece::PAWN, move.getTarg()));
		}
	} else {
		addMove(move);
	}
}

void Game::generateMoves() {
	if (numMovesAvail == -1) {
		numMovesAvail = 0;
		//if (curTurn == Turn::WHITE) {
			generateMovesImpl();
		//} else {
		//	generateMovesImpl_BLACK();
		//}
	}
}

int Game::getNumValidMoves() {
	Game::generateMoves();
	return numMovesAvail;
}
Move Game::getMove(int n) {
	_ASSERTE(0 <= n && n < getNumValidMoves());
	return moves[movePtr + n];
}