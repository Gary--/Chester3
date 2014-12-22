#include "Game.h"
#include "Game_UndoData.h"
#include <stdexcept>
void Game::configure(GameConfiguration config) {
	if (!config.isValid()) {
		throw std::invalid_argument("Invalid configuration: " + config.str());
	}
	config.clean();

	reset();


	curTurn = config.getTurn();


	FOR_POSITION_64(pos) {
		setPieceAt(pos, config.getPieceAt(pos));
		if (config.getPieceAt(pos) != Piece::EMPTY()) {
			toggleBit(config.getOwnerAt(pos), pos, config.getPieceAt(pos));
		}
	}

	cur = Game_UndoData();
	cur.halfMoveClock = config.getHalfMoveClock();
	fullMoveCount = config.getMoveNumber();
	cur.check = posAttackedBy(getPieces(getTurn(), Piece::KING()).ToPosition(), !getTurn());

	cur.hash = Game_Hash(config);


	integrityCheck();
}