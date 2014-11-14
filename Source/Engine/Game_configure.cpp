#include "Game.h"

void Game::configure(const GameConfiguration& config) {
	reset();


	curTurn = config.getTurn();


	FOR_POSITION_64(pos) {
		setPieceAt(pos, config.getPieceAt(pos));
		if (config.getPieceAt(pos) != Piece::EMPTY()) {
			toggleBit(config.getOwnerAt(pos), pos, config.getPieceAt(pos));
		}
	}

	cur = Game_UndoData();
	cur.check = posAttackedBy(getPieces(curTurn, Piece::KING()).ToPosition(), !curTurn);
	cur.hash = Game_Hash(config);
	integrityCheck();
}