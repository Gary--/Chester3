#include "stdafx.h"
#include "CppUnitTest.h"
#include "chess_macros.h"
#include "attack_fields.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_Attack_Fields) {
public:
	TEST_CLASS_INITIALIZE(CallAttackFieldInit) {
		AttackFields::init();
	}

	TEST_METHOD(Defaults) {
		GameConfiguration conf;
		Assert::AreEqual(Turn::WHITE, conf.getTurn());
		Assert::AreEqual(0, conf.getHalfMoveClock());
		Assert::AreEqual(1, conf.getMoveNumber());

		Assert::IsFalse(conf.getCanCastle(Turn::WHITE, Side::LEFT));
		Assert::IsFalse(conf.getCanCastle(Turn::WHITE, Side::RIGHT));
		Assert::IsFalse(conf.getCanCastle(Turn::BLACK, Side::LEFT));
		Assert::IsFalse(conf.getCanCastle(Turn::BLACK, Side::RIGHT));

		Assert::AreEqual(GameConfiguration::NO_ENPEASENT_COLUMN, conf.getEnpeasentColumn());

		FOR_POSITION_64(pos) {
			Assert::AreEqual(Piece::EMPTY, conf.getPieceAt(pos));
		}
	}

	TEST_METHOD(Getters_Setters) {
		GameConfiguration conf;

		conf.setTurn(Turn::BLACK);
		Assert::AreEqual(Turn::BLACK, conf.getTurn());
		conf.setTurn(Turn::WHITE);
		Assert::AreEqual(Turn::WHITE, conf.getTurn());

		conf.setHalfMoveClock(42);
		Assert::AreEqual(42, conf.getHalfMoveClock());

		conf.setMoveNumber(42);
		Assert::AreEqual(42, conf.getMoveNumber());

		conf.setEnpeasentColumn(3);
		Assert::AreEqual(3, conf.getEnpeasentColumn());

		Position pos1(10);
		conf.setPieceAt(pos1, Turn::WHITE, Piece::KING);
		Assert::AreEqual(Turn::WHITE, conf.getOwnerAt(pos1));
		Assert::AreEqual(Piece::KING, conf.getPieceAt(pos1));

		Position pos2(10);
		conf.setPieceAt(pos2, Turn::BLACK, Piece::PAWN);
		Assert::AreEqual(Turn::BLACK, conf.getOwnerAt(pos2));
		Assert::AreEqual(Piece::PAWN, conf.getPieceAt(pos2));
	}

	};


}