#include "stdafx.h"
#include "CppUnitTest.h"
#include "BitBoard.h"
#include <random>
#include "Position.h"
#include "chess_macros.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests
{
	TEST_CLASS(BitBoard_Position)
	{
	public:

		//Some randomly generated 64bit numbers. Assumed to be non symmetric.
		const int64_t a = 0xab900b5573db768e;
		const int64_t b = 0xf647ae931f3e323d;
		const int64_t c = 0x614bac23febd04f1;


		TEST_METHOD(BitBoard_Basic_Bitwise)
		{


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
		TEST_METHOD(Iter_Bits_0){
			testIter(BitBoard(a));
			testIter(BitBoard(b));
			testIter(BitBoard(c));
		}


		TEST_METHOD(Single_Board_Position_Conversion){
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
		TEST_METHOD(Flip_HardCore){
			flip_HardCore(BitBoard(a));
			flip_HardCore(BitBoard(b));
			flip_HardCore(BitBoard(c));
		}
	};
}