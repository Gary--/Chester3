#include "stdafx.h"
#include "CppUnitTest.h"
#include "BitBoard.h"
#include "Position.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests
{
	TEST_CLASS(A_BitBoard_Position)
	{
	public:

		//Some randomly generated 64bit numbers. Assumed to be non symmetric.
		const int64_t a = 0xab900b5573db768e;
		const int64_t b = 0xf647ae931f3e323d;
		const int64_t c = 0x614bac23febd04f1;

		
		TEST_METHOD(BitBoard_Basic_Bitwise)
		{
			Assert::AreEqual(BitBoard::EMPTY(), ~BitBoard::FULL());
			Assert::IsTrue(BitBoard::WHITE_SQUARES().contains(Position(7, 7)));

			Assert::AreEqual(BitBoard::EMPTY(), BitBoard::WHITE_SQUARES() & BitBoard::BLACK_SQUARES());
			Assert::AreEqual(BitBoard::FULL(), BitBoard::WHITE_SQUARES() ^ BitBoard::BLACK_SQUARES());
			Assert::AreEqual(32, BitBoard::BLACK_SQUARES().count());
			Assert::AreEqual(32, BitBoard::WHITE_SQUARES().count());

			Assert::AreNotEqual(BitBoard(a), BitBoard(b));

			Assert::AreEqual(BitBoard(a^b), BitBoard(a) ^ BitBoard(b));
			Assert::AreEqual(BitBoard(a&b), BitBoard(a) & BitBoard(b));
			Assert::AreEqual(BitBoard(a|b), BitBoard(a) | BitBoard(b));
			Assert::AreEqual(BitBoard(~a), ~BitBoard(a));
		}

		TEST_METHOD(Position_const_char_ctor) {
			Assert::AreEqual(Position(0, 0), Position("a8"));
			Assert::AreEqual(Position(0, 7), Position("h8"));
			Assert::AreEqual(Position(7, 0), Position("a1"));
			Assert::AreEqual(Position(7, 7), Position("h1"));
		}

		TEST_METHOD(Position_string_conversions) {
			FOR_POSITION_64(pos) {
				Assert::AreEqual(pos, Position(pos.str()));
			}
		}

		TEST_METHOD(Position_Get_Row_Col)
		{

			FOR_64(i){
				Position pos(i);
				Assert::AreEqual(i, pos.index());
				Assert::AreEqual(i % 8, pos.col());
				Assert::AreEqual(i / 8, pos.row());
				FOR_64(j) {
					Position pos2(j);
					if (i != j) {
						Assert::AreNotEqual(pos, pos2);
					}
				}
			}

			FOR_8(r){
				FOR_8(c){
					Position pos(r, c);
					Assert::AreEqual(r, pos.row());
					Assert::AreEqual(c, pos.col());
				}
			}
		}

		TEST_METHOD(BitBoard_AsInt64) {
			for (int i = 0; i < 100; ++i) {
				BitBoard bb = BitBoard::random();
				Assert::AreEqual(bb, BitBoard(bb.asInt64()));
			}
		}

		void testIter(BitBoard bb){
			BitBoard acc = BitBoard::EMPTY();
			FOR_BIT(x, bb){
				acc ^= x;
			}
			Assert::AreEqual(bb, acc);
		}
		TEST_METHOD(BitBoard_Iter_Bits_0){
			testIter(BitBoard(a));
			testIter(BitBoard(b));
			testIter(BitBoard(c));
		}


		TEST_METHOD(Position_Singleular_BitBoard_Conversion){
			FOR_64(i){
				Assert::AreEqual(Position(i), Position(i).asSingletonBitboard().ToPosition());
			}

			FOR_BIT(bit, BitBoard::FULL()){
				Assert::AreEqual(bit, bit.ToPosition().asSingletonBitboard());
			}
		}


		TEST_METHOD(BitBoard_Contains){
			FOR_64(i){
				Assert::IsTrue(BitBoard::FULL().contains(Position(i)));
				Assert::IsFalse(BitBoard::EMPTY().contains(Position(i)));
			}
		}

		TEST_METHOD(BitBoard_Count){
			Assert::AreEqual(0,  BitBoard::EMPTY().count());
			Assert::AreEqual(64, BitBoard::FULL().count());

			BitBoard A(a);
			BitBoard B(b);

			// Inclusion Exclusion
			Assert::AreEqual((A | B).count(), A.count() + B.count() - (A&B).count());
		}


		TEST_METHOD(Position_Flip){
			FOR_8(r){
				FOR_8(c){
					Position pos(r, c);
					Assert::AreEqual(c, pos.mirror().col());
					Assert::AreEqual(7-r, pos.mirror().row());
				}
			}
		}


		TEST_METHOD(BitBoard_Flip_Sanity){
			Assert::AreEqual(BitBoard::FULL(), BitBoard::FULL().mirror());
			Assert::AreEqual(BitBoard::EMPTY(), BitBoard::EMPTY().mirror());

			BitBoard A(a);
			BitBoard B(b);
			BitBoard C(c);

			Assert::AreEqual(A, A.mirror().mirror());
			Assert::AreEqual(B, B.mirror().mirror());
			Assert::AreEqual(C, C.mirror().mirror());

			Assert::AreNotEqual(A, A.mirror());
			Assert::AreNotEqual(B, B.mirror());
			Assert::AreNotEqual(C, C.mirror());
		}


		void flip_HardCore(BitBoard bb){
			int total1 = 0, total2 = 0;
			FOR_BIT(bit, bb){
				total1 += bit.ToPosition().index();
			}
			FOR_BIT(bit, bb.mirror()){
				total2 += bit.ToPosition().mirror().index();
			}
			Assert::AreEqual(total1, total2);
		}
		TEST_METHOD(BitBoard_Flip_HardCore){
			flip_HardCore(BitBoard(a));
			flip_HardCore(BitBoard(b));
			flip_HardCore(BitBoard(c));
		}

		TEST_METHOD(BitBoard_perspective) {
			BitBoard A(a);
			Assert::AreEqual(A, A.perspective(Turn::WHITE()));
			Assert::AreEqual(A.mirror(), A.perspective(Turn::BLACK()));
		}

		TEST_METHOD(BitBoard_RowCol_Bits){
			BitBoard acc1 = BitBoard::EMPTY();
			BitBoard acc2 = BitBoard::EMPTY();

			FOR_8(r){
				BitBoard row = BitBoard::rowBits(r);
				acc1 |= row;
				FOR_8(c){
					BitBoard col = BitBoard::colBits(c);
					acc2 |= col;

					Assert::AreEqual(1, (row&col).count());
				}
			}

			Assert::AreEqual(BitBoard::FULL(), acc1);
			Assert::AreEqual(BitBoard::FULL(), acc2);
		}

		TEST_METHOD(BitBoard_Position_Diagonal_Antidiagonal) {
			BitBoard acc1 = BitBoard::EMPTY();
			BitBoard acc2 = BitBoard::EMPTY();
			for (int i = 0; i < 15; ++i) {
				acc1 ^= BitBoard::diagonalBits(i);
				acc2 ^= BitBoard::antiDiagonalBits(i);

				FOR_BIT(bit, BitBoard::diagonalBits(i)) {
					Assert::AreEqual(i, bit.ToPosition().diag());
				}
				FOR_BIT(bit, BitBoard::antiDiagonalBits(i)) {
					Assert::AreEqual(i, bit.ToPosition().antiDiag());
				}
			}
			Assert::AreEqual(BitBoard::FULL(), acc1);
			Assert::AreEqual(BitBoard::FULL(), acc2);

			FOR_POSITION_64(pos) {
				Assert::IsTrue(BitBoard::diagonalBits(pos.diag()).contains(pos));
				Assert::IsTrue(BitBoard::antiDiagonalBits(pos.antiDiag()).contains(pos));
			}
		}
		
		TEST_METHOD(BitBoard_Shifts){
			for (int i = 0; i < 100; i++)
			{
				BitBoard bb = BitBoard::random();
				Assert::AreEqual(bb &~BitBoard::rowBits(0), bb.shiftUp().shiftDown());
				Assert::AreEqual(bb &~BitBoard::rowBits(7), bb.shiftDown().shiftUp());
				Assert::AreEqual(bb &~BitBoard::colBits(0), bb.shiftLeft().shiftRight());
				Assert::AreEqual(bb &~BitBoard::colBits(7), bb.shiftRight().shiftLeft());
			}

			for (int i = 0; i < 7; i++)
			{
				Assert::AreEqual(BitBoard::colBits(i).shiftRight(), BitBoard::colBits(i + 1));
				Assert::AreEqual(BitBoard::rowBits(i).shiftDown(), BitBoard::rowBits(i + 1));
			}

			for (int i = 1; i < 8; ++i){
				Assert::AreEqual(BitBoard::colBits(i).shiftLeft(), BitBoard::colBits(i - 1));
				Assert::AreEqual(BitBoard::rowBits(i).shiftUp(), BitBoard::rowBits(i - 1));
			}
		}


		// Check that everybit is sometimes on and sometimes off.
		TEST_METHOD(BitBoard_random){
			BitBoard ons = BitBoard::EMPTY();
			BitBoard offs = BitBoard::EMPTY();
			for (int i = 0; i < 100; ++i){
				BitBoard bb = BitBoard::random();
				ons |= bb;
				offs |= ~bb;
			}

			Assert::AreEqual(BitBoard::FULL(), ons);
			Assert::AreEqual(BitBoard::FULL(), offs);
		}


		TEST_METHOD(BitBoard_Shift_ForwardBackward) {
			BitBoard row = BitBoard::rowBits(4);

			Assert::AreEqual(BitBoard::rowBits(5), row.shiftForward(Turn::BLACK()));
			Assert::AreEqual(BitBoard::rowBits(3), row.shiftForward(Turn::WHITE()));
			Assert::AreEqual(BitBoard::rowBits(3), row.shiftBackward(Turn::BLACK()));
			Assert::AreEqual(BitBoard::rowBits(5), row.shiftBackward(Turn::WHITE()));
		}

		TEST_METHOD(Position_Shifts) {
			FOR_BIT(bit, ~(BitBoard::rowBits(0) | BitBoard::rowBits(7) |
				BitBoard::colBits(0) | BitBoard::colBits(7))){
				Position pos = bit.ToPosition();
				Assert::AreEqual(bit.shiftDown() , pos.shiftDown().asSingletonBitboard());
				Assert::AreEqual(bit.shiftUp() , pos.shiftUp().asSingletonBitboard());
				Assert::AreEqual(bit.shiftLeft() ,pos.shiftLeft().asSingletonBitboard());
				Assert::AreEqual(bit.shiftRight() , pos.shiftRight().asSingletonBitboard());

				FOR_TURN(turn) {
					Assert::AreEqual(bit.shiftForward(turn), pos.shiftForward(turn).asSingletonBitboard());
					Assert::AreEqual(bit.shiftBackward(turn), pos.shiftBackward(turn).asSingletonBitboard());
				}

			}
		}

		TEST_METHOD(Position_perspective) {
			FOR_POSITION_64(pos) {
				Assert::AreEqual(pos, pos.perspective(Turn::WHITE()));
				Assert::AreEqual(pos.mirror(), pos.perspective(Turn::BLACK()));
			}
		}

		TEST_METHOD(BitBoard_rowsLessThan) {
			FOR_8(r){
				BitBoard before = BitBoard::EMPTY();
				for (int i = 0; i < r; ++i) {
					before |= BitBoard::rowBits(i);
				}
				Assert::AreEqual(before, BitBoard::rowsLessThan(r));


			}
		}
		TEST_METHOD(BitBoard_rowsGreaterThan) {
			FOR_8(r) {
				BitBoard after = BitBoard::EMPTY();
				for (int i = r + 1; i < 8; ++i) {
					after |= BitBoard::rowBits(i);
				}
				Assert::AreEqual(after, BitBoard::rowsGreaterThan(r));
			}
		}
		TEST_METHOD(Position_Squares_Forward_Backward) {
			FOR_POSITION_64(pos) {
				Assert::AreEqual(BitBoard::rowsLessThan(pos.row()), pos.squaresAbove());
				Assert::AreEqual(BitBoard::rowsGreaterThan(pos.row()), pos.squaresBelow());

				Assert::AreEqual(pos.squaresForward(Turn::WHITE()), pos.squaresBackward(Turn::BLACK()));
				Assert::AreEqual(pos.squaresAbove(), pos.squaresForward(Turn::WHITE()));
			}
		}
	};
}