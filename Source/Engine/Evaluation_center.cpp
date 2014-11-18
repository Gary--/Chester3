#include "Evaluation.h"
#include "Game.h"
#include "AttackMap.h"

namespace {
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

	enum class Controller : uint8_t {WHITE, BLACK, NEUTRAL};
	Controller getController(const Position position) {
		const AttackPattern wCtrl = AttackMap::getAttackPattern(Turn::WHITE(), position);
		const AttackPattern bCtrl = AttackMap::getAttackPattern(Turn::BLACK(), position);
		return Controller::NEUTRAL;
	}
}

int Evaluation::center() {
	const BitBoard range(0x0000E7E7E7E70000ULL);
	if (Game::getPieces(Turn::WHITE(), Piece::PAWN()).count() < 4 ||
		Game::getPieces(Turn::BLACK(), Piece::PAWN()).count() < 4) {
		return 0;
	}

	int res = 0;
	FOR_BIT(bit, range) {
		const Position pos = bit.ToPosition();
		const Controller ctrl = getController(pos);
		
		switch (ctrl) {
		case Controller::WHITE:
			res += squareValue[pos.index()];
			break;
		case Controller::BLACK:
			res += squareValue[pos.perspective(Turn::BLACK()).index()];
			break;
		default:
			break;
		}

		

	}
	return 0;
}