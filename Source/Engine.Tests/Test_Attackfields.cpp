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

	TEST_METHOD(King_Targs) {
		// King on e5
		Assert::AreEqual(
			Position(4, 3).ToSingletonBoard() |
			Position(4, 5).ToSingletonBoard() |
			Position(5, 4).ToSingletonBoard() |
			Position(3, 4).ToSingletonBoard() |
			Position(5, 5).ToSingletonBoard() |
			Position(3, 3).ToSingletonBoard() |
			Position(3, 5).ToSingletonBoard() |
			Position(5, 3).ToSingletonBoard() 
			, AttackFields::kingTargs(Position(4, 4)));

		//Kings generally hit 8 squres. 5 on edge. 3 on corner.
		FOR_8(r) {
			FOR_8(c) {
				BitBoard targs = AttackFields::kingTargs(Position(r, c));
				bool edge1 = r == 0 || r == 7;
				bool edge2 = c == 0 || c == 7;
				if (edge1 && edge2) {
					Assert::AreEqual(3, targs.count());
				} else if (edge1 || edge2) {
					Assert::AreEqual(5, targs.count());
				} else {
					Assert::AreEqual(8, targs.count());
				}
			}
		}
	}

	TEST_METHOD(Knight_Targs) {
		// Knight on e5
		Assert::AreEqual(
			Position(6, 3).ToSingletonBoard() |
			Position(2, 3).ToSingletonBoard() |
			Position(6, 5).ToSingletonBoard() |
			Position(2, 5).ToSingletonBoard() |
			Position(3, 2).ToSingletonBoard() |
			Position(3, 6).ToSingletonBoard() |
			Position(5, 2).ToSingletonBoard() |
			Position(5, 6).ToSingletonBoard()
			, AttackFields::knightTargs(Position(4, 4)));

		Assert::AreEqual(8, AttackFields::knightTargs(Position(2, 2)).count());
		Assert::AreEqual(6, AttackFields::knightTargs(Position(1, 2)).count());
		Assert::AreEqual(2, AttackFields::knightTargs(Position(7, 7)).count());
		Assert::AreEqual(4, AttackFields::knightTargs(Position(6, 6)).count());
	}


	TEST_METHOD(Pawn_Targs) {
		Assert::AreEqual(
			Position(5, 3).ToSingletonBoard() |Position(5, 5).ToSingletonBoard()
			, AttackFields::pawnTargs(Turn::BLACK, Position(4, 4)));
		Assert::AreEqual(
			Position(3, 3).ToSingletonBoard() | Position(3, 5).ToSingletonBoard()
			, AttackFields::pawnTargs(Turn::WHITE, Position(4, 4)));
	}
	
	};


}