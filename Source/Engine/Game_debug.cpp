#include "Game.h"
#include <crtdbg.h>

void Game::integrityCheck() {
#ifdef _DEBUG
	_ASSERTE(hash.toInt64() == GameHash(GameConfiguration::extractFromGame()).toInt64());

	_ASSERTE(ALL == (WA ^ BA));
	_ASSERTE((WA & BA) == BitBoard::EMPTY());

	FOR_TURN(turn) {
		BitBoard turnAll = BitBoard::EMPTY();
		FOR_PIECE_ALL(piece) {
			turnAll ^= *s(turn, piece);
		}
	}

	

	FOR_PIECE_ALL(piece) {
		BitBoard pieceAll = BitBoard::EMPTY();
		FOR_POSITION_64(pos) {
			if (getPieceAt(pos) == piece) {
				pieceAll ^= pos.ToSingletonBoard();
			}
		}

		_ASSERTE((*s(Turn::WHITE, piece) ^ *s(Turn::BLACK, piece)) == pieceAll);
	}

#endif
}