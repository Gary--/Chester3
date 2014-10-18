#include "stdafx.h"
#include "CppUnitTest.h"
#include "BitBoard.h"
#include "Position.h"
#include "chess_macros.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests
{
	TEST_CLASS(Test_BitBoard_Position)
	{
	public:

		//Some randomly generated 64bit numbers. Assumed to be non symmetric.
		const int64_t a = 0xab900b5573db768e;
		const int64_t b = 0xf647ae931f3e323d;
		const int64_t c = 0x614bac23febd04f1;


		TEST_METHOD(BitBoard_Basic_Bitwise)
		{
			Assert::AreEqual(BitBoard::EMPTY, ~BitBoard::FULL);
			Assert::IsTrue(BitBoard::WHITE_SQUARES.contains(Position(7, 7)));

			Assert::AreEqual(BitBoard::EMPTY, BitBoard::WHITE_SQUARES & BitBoard::BLACK_SQUARES);
			Assert::AreEqual(BitBoard::FULL, BitBoard::WHITE_SQUARES ^ BitBoard::BLACK_SQUARES);
			Assert::AreEqual(32, BitBoard::BLACK_SQUARES.count());
			Assert::AreEqual(32, BitBoard::WHITE_SQUARES.count());

			Assert::AreNotEqual(BitBoard(a), BitBoard(b));

			Assert::AreEqual(BitBoard(a^b), BitBoard(a) ^ BitBoard(b));
			Assert::AreEqual(BitBoard(a&b), BitBoard(a) & BitBoard(b));
			Assert::AreEqual(BitBoard(a|b), BitBoard(a) | BitBoard(b));
			Assert::AreEqual(BitBoard(~a), ~BitBoard(a));
		}


		TEST_METHOD(Position_Get_Row_Col)
		{
			FOR_64(i){
				Position pos(i);
				Assert::AreEqual(i, pos.index());
				Assert::AreEqual(i % 8, pos.col());
				Assert::AreEqual(i / 8, pos.row());
			}

			FOR_8(r){
				FOR_8(c){
					Position pos(r, c);
					Assert::AreEqual(r, pos.row());
					Assert::AreEqual(c, pos.col());
				}
			}
		}


		void testIter(BitBoard bb){
			BitBoard acc = BitBoard::EMPTY;
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
				Assert::AreEqual(Position(i), Position(i).ToSingletonBoard().ToPosition());
			}

			FOR_BIT(bit, BitBoard::FULL){
				Assert::AreEqual(bit, bit.ToPosition().ToSingletonBoard());
			}
		}


		TEST_METHOD(BitBoard_Contains){
			FOR_64(i){
				Assert::IsTrue(BitBoard::FULL.contains(Position(i)));
				Assert::IsFalse(BitBoard::EMPTY.contains(Position(i)));
			}
		}

		TEST_METHOD(BitBoard_Count){
			Assert::AreEqual(0,  BitBoard::EMPTY.count());
			Assert::AreEqual(64, BitBoard::FULL.count());

			BitBoard A(a);
			BitBoard B(b);

			// Inclusion Exclusion
			Assert::AreEqual((A | B).count(), A.count() + B.count() - (A&B).count());
		}


		TEST_METHOD(Position_Flip){
			FOR_8(r){
				FOR_8(c){
					Position pos(r, c);
					Assert::AreEqual(c, pos.verticalFlip().col());
					Assert::AreEqual(7-r, pos.verticalFlip().row());
				}
			}
		}


		TEST_METHOD(BitBoard_Flip_Sanity){
			Assert::AreEqual(BitBoard::FULL, BitBoard::FULL.verticalFlip());
			Assert::AreEqual(BitBoard::EMPTY, BitBoard::EMPTY.verticalFlip());

			BitBoard A(a);
			BitBoard B(b);
			BitBoard C(c);

			Assert::AreEqual(A, A.verticalFlip().verticalFlip());
			Assert::AreEqual(B, B.verticalFlip().verticalFlip());
			Assert::AreEqual(C, C.verticalFlip().verticalFlip());

			Assert::AreNotEqual(A, A.verticalFlip());
			Assert::AreNotEqual(B, B.verticalFlip());
			Assert::AreNotEqual(C, C.verticalFlip());
		}


		void flip_HardCore(BitBoard bb){
			int total1 = 0, total2 = 0;
			FOR_BIT(bit, bb){
				total1 += bit.ToPosition().index();
			}
			FOR_BIT(bit, bb.verticalFlip()){
				total2 += bit.ToPosition().verticalFlip().index();
			}
			Assert::AreEqual(total1, total2);
		}
		TEST_METHOD(BitBoard_Flip_HardCore){
			flip_HardCore(BitBoard(a));
			flip_HardCore(BitBoard(b));
			flip_HardCore(BitBoard(c));
		}


		TEST_METHOD(BitBoard_RowCol_Bits){
			BitBoard acc1 = BitBoard::EMPTY;
			BitBoard acc2 = BitBoard::EMPTY;

			FOR_8(r){
				BitBoard row = BitBoard::rowBits(r);
				acc1 |= row;
				FOR_8(c){
					BitBoard col = BitBoard::colBits(c);
					acc2 |= col;

					Assert::AreEqual(1, (row&col).count());
				}
			}

			Assert::AreEqual(BitBoard::FULL, acc1);
			Assert::AreEqual(BitBoard::FULL, acc2);
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
			BitBoard ons = BitBoard::EMPTY;
			BitBoard offs = BitBoard::EMPTY;
			for (int i = 0; i < 100; ++i){
				BitBoard bb = BitBoard::random();
				ons |= bb;
				offs |= ~bb;
			}

			Assert::AreEqual(BitBoard::FULL, ons);
			Assert::AreEqual(BitBoard::FULL, offs);
		}


		TEST_METHOD(BitBoard_Shift_ForwardBackward) {
			BitBoard row = BitBoard::rowBits(4);

			Assert::AreEqual(BitBoard::rowBits(5), row.shiftForward(Turn::BLACK));
			Assert::AreEqual(BitBoard::rowBits(3), row.shiftForward(Turn::WHITE));
			Assert::AreEqual(BitBoard::rowBits(3), row.shiftBackward(Turn::BLACK));
			Assert::AreEqual(BitBoard::rowBits(5), row.shiftBackward(Turn::WHITE));
		}
	};
}