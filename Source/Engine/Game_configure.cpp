#include "Game.h"

void Game::configure(const GameConfiguration& config) {
	reset();
	result = GameResult::IN_PROGRESS;//TODO: draw tests etc

	hash = GameHash(config);

	curTurn = config.getTurn();
	halfMoveCount = config.getHalfMoveClock();
	moveCount = config.getMoveNumber();

	FOR_POSITION_64(pos) {
		setPieceAt(pos, config.getPieceAt(pos));
		if (config.getPieceAt(pos) != Piece::EMPTY) {
			toggleBit(config.getOwnerAt(pos), pos, config.getPieceAt(pos));
		}
	}


}