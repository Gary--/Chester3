#include "Game.h"
#include "Game_UndoData.h"

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
	cur.check = posAttackedBy(getPieces(getTurn(), Piece::KING()).ToPosition(), !getTurn());

	cur.hash = Game_Hash(config);
	if (!canEnpeasent(getTurn(), cur.hash.getEnpeasent())) {
		cur.hash.setEnpeasent(GameConfiguration::NO_ENPEASENT_COLUMN);
	}


	integrityCheck();
}