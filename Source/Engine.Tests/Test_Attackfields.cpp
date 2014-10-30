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
			, AttackFields::pawnTargs(Position(4, 4),Turn::BLACK ));
		Assert::AreEqual(
			Position(3, 3).ToSingletonBoard() | Position(3, 5).ToSingletonBoard()
			, AttackFields::pawnTargs(Position(4, 4),Turn::WHITE ));
	}
	

	TEST_METHOD(Rook_Targs) {
		FOR_8(r) {
			FOR_8(c) {
				Position pos(r, c);
				BitBoard unblocked = AttackFields::rookTargs(pos, BitBoard::EMPTY());
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
		Assert::AreEqual(7, AttackFields::bishopTargs(Position(0, 0), BitBoard::EMPTY()).count());
		Assert::AreEqual(7, AttackFields::bishopTargs(Position(0, 7), BitBoard::EMPTY()).count());
		Assert::AreEqual(7, AttackFields::bishopTargs(Position(7, 0), BitBoard::EMPTY()).count());
		Assert::AreEqual(7, AttackFields::bishopTargs(Position(7, 7), BitBoard::EMPTY()).count());

		Assert::AreEqual(13, AttackFields::bishopTargs(Position(4, 4), BitBoard::EMPTY()).count());
		Assert::AreEqual(13, AttackFields::bishopTargs(Position(3, 4), BitBoard::EMPTY()).count());
		Assert::AreEqual(13, AttackFields::bishopTargs(Position(3, 4), BitBoard::EMPTY()).count());
		Assert::AreEqual(13, AttackFields::bishopTargs(Position(3, 3), BitBoard::EMPTY()).count());

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

	TEST_METHOD(Pinned_Targs) {
		FOR_POSITION_64(kingPos) {
			FOR_POSITION_64(pinnedPos) {
				BitBoard targs = AttackFields::pinnedTargs(kingPos, pinnedPos);
				Assert::AreNotEqual(BitBoard::EMPTY(), targs);

				//We are not pinned
				if (!AttackFields::queenTargs(kingPos, BitBoard::EMPTY()).contains(pinnedPos)) {
					Assert::AreEqual(BitBoard::FULL(), targs);
					continue;
				}

				Assert::AreEqual(targs& ~kingPos.ToSingletonBoard(), 
								 AttackFields::queenTargs(kingPos, BitBoard::EMPTY()) & targs);
			}
		}
	}

	TEST_METHOD(Blocking_Targs) {
		FOR_POSITION_64(kingPos) {
			FOR_POSITION_64(attackerPos) {
				BitBoard targs = AttackFields::blockingTargs(kingPos, attackerPos);
				Assert::AreNotEqual(BitBoard::EMPTY(), targs);
				Assert::IsTrue(targs.contains(attackerPos));

				//Does not actually attack
				if (!AttackFields::queenTargs(attackerPos, BitBoard::EMPTY()).contains(kingPos)) {
					Assert::AreEqual(BitBoard::FULL(), targs);
					continue;
				}

				

				FOR_BIT(candBit,targs) {
					Position candPos = candBit.ToPosition();
					if (candPos == kingPos || candPos == attackerPos) {
						continue;
					}

					Assert::IsFalse(AttackFields::queenTargs(attackerPos, candBit).contains(kingPos));
				}
			}
		}
	}

	TEST_METHOD(AttackFields_Castling_Empty){
		Assert::AreEqual(
			Position("b1").ToSingletonBoard() | 
			Position("c1").ToSingletonBoard() | 
			Position("d1").ToSingletonBoard()
			, AttackFields::castleEmptySquares(Turn::WHITE, Side::LEFT));

		Assert::AreEqual(
			Position("f1").ToSingletonBoard() |
			Position("g1").ToSingletonBoard() 
			, AttackFields::castleEmptySquares(Turn::WHITE, Side::RIGHT));
	}

	TEST_METHOD(AttackFields_Castling_Safe){
		Assert::AreEqual(
			Position("c1").ToSingletonBoard() |
			Position("d1").ToSingletonBoard() |
			Position("e1").ToSingletonBoard()
			, AttackFields::castleSafeSquares(Turn::WHITE, Side::LEFT));

		Assert::AreEqual(
			Position("e1").ToSingletonBoard() |
			Position("f1").ToSingletonBoard() |
			Position("g1").ToSingletonBoard()
			, AttackFields::castleSafeSquares(Turn::WHITE, Side::RIGHT));
	}

	TEST_METHOD(Castle_Symmetry){
		FOR_SIDE(side){
			Assert::IsTrue(AttackFields::castleEmptySquares(Turn::WHITE, side) ==
				AttackFields::castleEmptySquares(Turn::BLACK, side).verticalFlip());
			Assert::IsTrue(AttackFields::castleEmptySquares(Turn::WHITE, side) ==
				AttackFields::castleEmptySquares(Turn::BLACK, side).verticalFlip());
		}
	}

	};


}