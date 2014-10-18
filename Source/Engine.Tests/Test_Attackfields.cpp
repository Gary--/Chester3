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
			BitBoard(4, 3) |
			BitBoard(4, 5) |
			BitBoard(5, 4) |
			BitBoard(3, 4) |
			BitBoard(5, 5) |
			BitBoard(3, 3) |
			BitBoard(3, 5) |
			BitBoard(5, 3)
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
			BitBoard(6, 3) |
			BitBoard(2, 3) |
			BitBoard(6, 5) |
			BitBoard(2, 5) |
			BitBoard(3, 2) |
			BitBoard(3, 6) |
			BitBoard(5, 2) |
			BitBoard(5, 6)
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
	

	TEST_METHOD(Rook_Targs) {
		FOR_8(r) {
			FOR_8(c) {
				Position pos(r, c);
				BitBoard unblocked = AttackFields::rookTargs(pos, BitBoard::EMPTY);
				Assert::AreEqual(BitBoard::colBits(c) ^ BitBoard::rowBits(r),
								 unblocked);
			}
		}

		BitBoard surroundedBlockers =
			BitBoard(4, 5) | BitBoard(3, 4) | BitBoard(5, 4) | BitBoard(4, 3);
		Assert::AreEqual(surroundedBlockers,
						 AttackFields::rookTargs(Position(4, 4),surroundedBlockers));
	}
	

	TEST_METHOD(Bishop_Targs) {
		Assert::AreEqual(7, AttackFields::bishopTargs(Position(0, 0), BitBoard::EMPTY).count());
		Assert::AreEqual(7, AttackFields::bishopTargs(Position(0, 7), BitBoard::EMPTY).count());
		Assert::AreEqual(7, AttackFields::bishopTargs(Position(7, 0), BitBoard::EMPTY).count());
		Assert::AreEqual(7, AttackFields::bishopTargs(Position(7, 7), BitBoard::EMPTY).count());

		Assert::AreEqual(13, AttackFields::bishopTargs(Position(4, 4), BitBoard::EMPTY).count());
		Assert::AreEqual(13, AttackFields::bishopTargs(Position(3, 4), BitBoard::EMPTY).count());
		Assert::AreEqual(13, AttackFields::bishopTargs(Position(3, 4), BitBoard::EMPTY).count());
		Assert::AreEqual(13, AttackFields::bishopTargs(Position(3, 3), BitBoard::EMPTY).count());

		BitBoard surroundedBlockers =
			BitBoard(3 ,3) | BitBoard(3, 5) | BitBoard(5, 3) | BitBoard(5, 5);
		Assert::AreEqual(surroundedBlockers,
						 AttackFields::bishopTargs(Position(4, 4), surroundedBlockers));
	}

	TEST_METHOD(Queen_Targs) {

		for (int j = 0; j < 10; ++j) {
			BitBoard blockers = BitBoard::random() & BitBoard::random();
			FOR_64(i) {
				Position pos(i);
				Assert::AreEqual(AttackFields::bishopTargs(pos, blockers) |
								 AttackFields::rookTargs(pos, blockers),
								 AttackFields::queenTargs(pos, blockers)
								 );
			}
		}

	}
	};


}