#include "GameConfiguration_MoveIterator.h"
#include "GameConfiguration.h"
#include "AttackFields.h"

GameConfiguration_MoveIterator_Generator::GameConfiguration_MoveIterator_Generator(const GameConfiguration conf) {
	generateMoves(conf);
}

void GameConfiguration_MoveIterator_Generator::addMove(const GameConfiguration& conf,const Move move) {
	GameConfiguration confCopy = conf;
	confCopy.makeMove(move);
	if (confCopy.isValid()) {
		moves.push_back(move);
	}
}

void GameConfiguration_MoveIterator_Generator::addPawnMove(const GameConfiguration& conf, const Move move) {
	if (AttackFields::pawnPromoZone(conf.getTurn()).contains(move.getFrom())) {
		FOR_PIECE(promo, Piece::KNIGHT(), Piece::QUEEN()) {
			addMove(conf, Move(promoType(promo), move.getFrom(), move.getTo(), Piece::PAWN(), move.getTarg()));
		}
	} else {
		addMove(conf,move);
	}
}



void GameConfiguration_MoveIterator_Generator::generateMoves(const GameConfiguration& conf) {
	const Turn turn = conf.getTurn();
	const BitBoard ALL = conf.getAllPieces();
	const BitBoard M = conf.getPlayerPieces(turn);
	const BitBoard T = conf.getPlayerPieces(!turn);

	FOR_PIECE(piece, Piece::KNIGHT(), Piece::KING()) {
		FOR_BIT(bit, conf.getPieces(turn, piece)) {
			const Position from = bit.ToPosition();

			BitBoard tos;
			switch (PieceEnum::INVALID) {
			case PieceEnum::KNIGHT:
				tos = AttackFields::knightTargs(from);
				break;
			case PieceEnum::BISHOP:
				tos = AttackFields::bishopTargs(from, ALL);
				break;
			case PieceEnum::ROOK:
				tos = AttackFields::rookTargs(from, ALL);
				break;
			case PieceEnum::QUEEN:
				tos = AttackFields::bishopTargs(from, conf.getAllPieces()) | AttackFields::rookTargs(from, conf.getAllPieces());
				break;
			case PieceEnum::KING:
				tos = AttackFields::kingTargs(from);
				break;
			case PieceEnum::INVALID:
				break;
			default:
				break;
			}
			tos &= ~M; // Don't allow self capture

			FOR_BIT(toBit, tos) {
				const Position to = toBit.ToPosition();
				const Piece targ = conf.getPieceAt(to);
				addMove(conf,Move(MoveType::REGULAR, from, to, piece, targ));
			}
		}
	}
	
	const BitBoard MP = conf.getPieces(turn, Piece::PAWN());
	FOR_BIT(bit, MP) {
		const Position from = bit.ToPosition();

		if (!ALL.contains(from.shiftForward(turn))) {
			const Position to = from.shiftForward(turn);
			addPawnMove(conf, Move(MoveType::REGULAR, from, to, Piece::PAWN(), Piece::EMPTY()));

			if (AttackFields::pawnJumpZone(turn).contains(from) && !ALL.contains(to.shiftForward(turn))) {
				const Position to2 = to.shiftForward(turn);
				addMove(conf, Move(MoveType::PAWN_JUMP, from, to2, Piece::PAWN(), Piece::EMPTY()));
			}
		}

		FOR_BIT(toBit, AttackFields::pawnTargs(from, turn)&T) {
			const Position to = toBit.ToPosition();
			addPawnMove(conf, Move(MoveType::REGULAR, from, to, Piece::PAWN(), conf.getPieceAt(to)));
		}
	}
	if (conf.getEnpeasentColumn() != GameConfiguration::NO_ENPEASENT_COLUMN) {
		const Position to = AttackFields::enpeasentTo(turn, conf.getEnpeasentColumn());
		FOR_BIT(bit, MP & AttackFields::pawnTargs(to, !turn)) {
			const Position from = bit.ToPosition();
			addMove(conf,Move(MoveType::ENPEASENT, from, to, Piece::PAWN(), Piece::EMPTY()));
		}
	}

	FOR_SIDE(side) {
		if (conf.getCanCastle(turn, side) &&
			(ALL & AttackFields::castleEmptySquares(turn, side)).isEmpty()) {
			const BitBoard safe = AttackFields::castleSafeSquares(turn, side);

			bool works = true;
			FOR_BIT(bit, safe) {
				if (conf.posAttackedBy(bit.ToPosition(), !turn)) {
					works = false;
				}
			}
			if (!works) {
				continue;
			}
			const Position kingPos = conf.getPieces(turn, Piece::KING()).ToPosition();
			const Position kingStartPos = turn.isWhite() ? Position("e1") : Position("e8");
			if (kingPos != kingStartPos) {
				continue;
			}

			const Position rookStartPos(turn.isWhite() * 7, (side == Side::RIGHT) * 7);
			if (!conf.getPieces(turn, Piece::ROOK()).contains(rookStartPos)) {
				continue;
			}

			const MoveType type = side == Side::LEFT ? MoveType::CASTLE_LEFT : MoveType::CASTLE_RIGHT;
			const Position to(turn.isWhite() ? 7 : 0, 4 + (side == Side::LEFT ? (-2) : 2));

			addMove(conf, Move(type, kingPos, to, Piece::KING(), Piece::EMPTY()));
		}
	}
}

GameConfiguration_MoveIterator GameConfiguration_MoveIterator_Generator::begin() const {
	return GameConfiguration_MoveIterator(moves.begin());
}

GameConfiguration_MoveIterator GameConfiguration_MoveIterator_Generator::end() const {
	return GameConfiguration_MoveIterator(moves.end());
}

GameConfiguration_MoveIterator::GameConfiguration_MoveIterator(std::vector<Move>::const_iterator it) : it(it) {}

Move GameConfiguration_MoveIterator::operator*() const {
	return *it;
}

void GameConfiguration_MoveIterator::operator++() {
	it++;
}

bool GameConfiguration_MoveIterator::operator!=(const GameConfiguration_MoveIterator& other) const {
	return it != other.it;
}

