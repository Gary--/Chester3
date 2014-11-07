#include "stdafx.h"
#include "CppUnitTest.h"
#include "AttackDefend.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_AttackDefendByte) {
public:
	Piece randomPiece() {
		int val = rand() % 6;
		return Piece(1 + val);
	}

	TEST_METHOD(Initializes_To_Empty) {
		AtkPat pat;
		Assert::IsTrue(pat.isEmpty());
		FOR_PIECE_ALL(piece) {
			Assert::IsFalse(pat.contains(piece));
		}
	}
	
	TEST_METHOD(Knights_and_Bishops_Share) {
		AtkPat pat;
		pat.add(Piece::KNIGHT);
		pat.add(Piece::BISHOP);
		Assert::AreEqual(2, pat.getCount());
		Assert::IsTrue(pat.contains(Piece::KNIGHT));
		Assert::IsTrue(pat.contains(Piece::BISHOP));

		pat = AtkPat();
		pat.add(Piece::KNIGHT);
		pat.add(Piece::KNIGHT);
		Assert::AreEqual(2, pat.getCount());
		Assert::IsTrue(pat.contains(Piece::KNIGHT));
		Assert::IsTrue(pat.contains(Piece::BISHOP));

		pat = AtkPat();
		pat.add(Piece::BISHOP);
		pat.add(Piece::BISHOP);
		Assert::AreEqual(2, pat.getCount());
		Assert::IsTrue(pat.contains(Piece::KNIGHT));
		Assert::IsTrue(pat.contains(Piece::BISHOP));
	}

	TEST_METHOD(Adding_Single_Piece_Works) {
		FOR_PIECE_ALL(piece) {
			AtkPat pat;
			pat.add(piece);

			Assert::AreEqual(1, pat.getCount());
			FOR_PIECE_ALL(piece2) {
				bool shouldEqual = piece == piece2 ||
					(piece == Piece::KNIGHT && piece2 == Piece::BISHOP) ||
					(piece == Piece::BISHOP && piece2 == Piece::KNIGHT);
				Assert::AreEqual(shouldEqual, pat.contains(piece2));
			}
		}
	}

	TEST_METHOD(Count_Works) {
		for (int trials = 0; trials < 1000; ++trials) {
			AtkPat pat;
			for (int i = 1; i <= 7; ++i) {
				Piece pieceToAdd = randomPiece();
				pat.add(pieceToAdd);
				Assert::IsFalse(pat.isEmpty());
				Assert::IsTrue(pat.contains(pieceToAdd));
				Assert::AreEqual(i, pat.getCount());
			}
		}
	}

	TEST_METHOD(String_Representation) {
		AtkPat pat0;
		pat0.add(Piece::KNIGHT);
		pat0.add(Piece::QUEEN);
		pat0.add(Piece::BISHOP);
		Assert::AreEqual("3:NQ", pat0.str().c_str());
	}

	};
}