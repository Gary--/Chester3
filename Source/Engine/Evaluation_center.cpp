#include "Evaluation.h"
#include "Game.h"
#include "AttackMap.h"

namespace {
	enum class Controller : uint8_t {WHITE, BLACK, NEUTRAL};
	Controller getController(const Position position) {
		const AttackPattern wCtrl = AttackMap::getAttackPattern(Turn::WHITE(), position);
		const AttackPattern bCtrl = AttackMap::getAttackPattern(Turn::BLACK(), position);

		if (!wCtrl.isEmpty() || !bCtrl.isEmpty()) {
			if (!wCtrl.isEmpty() && bCtrl.isEmpty()) {
				return Controller::WHITE;
			}

			if (wCtrl.isEmpty() && !bCtrl.isEmpty()) {
				return Controller::BLACK;
			}

			if (wCtrl.getSmallestPiece() < bCtrl.getSmallestPiece()) {
				return Controller::WHITE;
			}

			if (wCtrl.getSmallestPiece() > bCtrl.getSmallestPiece()) {
				return Controller::BLACK;
			}
		}

		const bool occed = Game::getPieceAt(position) != Piece::EMPTY();
		const Turn owner = Game::getOwnerAt(position);
		if (occed) {
			return owner.isWhite() ? Controller::WHITE : Controller::BLACK;
		}

		return Controller::NEUTRAL;
	}

	const uint8_t squareValue[64] = {
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 4, 6, 8, 8, 6, 4, 0,
		0, 4, 6, 8, 8, 6, 4, 0,
		0, 0, 4, 6, 6, 8, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0,
	};
}

int Evaluation::center() {


	const BitBoard range(0x00007E7E7E7E0000ULL);//None zero Sqrs in squareValue
	if (Game::getPieces(Turn::WHITE(), Piece::PAWN()).count() < 4 ||
		Game::getPieces(Turn::BLACK(), Piece::PAWN()).count() < 4) {
		return 0;
	}

	int res = 0;
	FOR_POS(pos, range) {
		_ASSERTE(squareValue[pos.index()] + squareValue[pos.mirror().index()] > 0);//make sure we aren't checking useless squares

		const Controller ctrl = getController(pos);
		
		switch (ctrl) {
		case Controller::WHITE:
			res += squareValue[pos.index()];
			break;
		case Controller::BLACK:
			res -= squareValue[pos.perspective(Turn::BLACK()).index()];
			break;
		default:
			break;
		}
	}
	return res;
}

char Evaluation::DEBUG_control(const Position position) {
	switch (getController(position)) {
	case Controller::WHITE:
		return 'w';
	case Controller::BLACK:
		return 'b';
	default:
		return '?';
	}
}