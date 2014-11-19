#include "stdafx.h"
#include "CppUnitTest.h"
#include "AttackPattern.h"
#include <algorithm>
#include "StaticExchange.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_AttackPattern) {
public:
	TEST_CLASS_INITIALIZE(Call_StaticExchange_init) {
		StaticExchange::init();
	}

#pragma region Basic Contains/Total
	TEST_METHOD(Initializes_To_Empty) {
		AttackPattern pat;
		Assert::IsTrue(pat.isEmpty());
		FOR_PIECE_ALL(piece) {
			Assert::IsFalse(pat.contains(piece));
		}
	}
	
	TEST_METHOD(Knights_and_Bishops_Share) {
		AttackPattern pat;
		pat.add(Piece::KNIGHT());
		pat.add(Piece::BISHOP());
		Assert::AreEqual(2, pat.getCount());
		Assert::IsTrue(pat.contains(Piece::KNIGHT()));
		Assert::IsTrue(pat.contains(Piece::BISHOP()));

		pat = AttackPattern();
		pat.add(Piece::KNIGHT());
		pat.add(Piece::KNIGHT());
		Assert::AreEqual(2, pat.getCount());
		Assert::IsTrue(pat.contains(Piece::KNIGHT()));
		Assert::IsTrue(pat.contains(Piece::BISHOP()));

		pat = AttackPattern();
		pat.add(Piece::BISHOP());
		pat.add(Piece::BISHOP());
		Assert::AreEqual(2, pat.getCount());
		Assert::IsTrue(pat.contains(Piece::KNIGHT()));
		Assert::IsTrue(pat.contains(Piece::BISHOP()));
	}

	TEST_METHOD(Adding_Single_Piece_Works) {
		FOR_PIECE_ALL(piece) {
			AttackPattern pat;
			pat.add(piece);

			Assert::AreEqual(1, pat.getCount());
			FOR_PIECE_ALL(piece2) {
				bool shouldEqual = piece == piece2 ||
					(piece == Piece::KNIGHT() && piece2 == Piece::BISHOP()) ||
					(piece == Piece::BISHOP() && piece2 == Piece::KNIGHT());
				Assert::AreEqual(shouldEqual, pat.contains(piece2));
			}
		}
	}

	TEST_METHOD(Count_Works) {
		for (int trials = 0; trials < 1000; ++trials) {
			AttackPattern pat;
			for (int i = 1; i <= 7; ++i) {
				Piece pieceToAdd = Piece::random();
				pat.add(pieceToAdd);
				Assert::IsFalse(pat.isEmpty());
				Assert::IsTrue(pat.contains(pieceToAdd));
				Assert::AreEqual(i, pat.getCount());
			}
		}
	}

	TEST_METHOD(String_Representation) {
		AttackPattern pat0;
		pat0.add(Piece::KNIGHT());
		pat0.add(Piece::QUEEN());
		pat0.add(Piece::BISHOP());
		Assert::AreEqual("3:NQ", pat0.str().c_str());
	}
#pragma endregion

	TEST_METHOD(Piece_Count_One) {
		FOR_PIECE_ALL(piece) {
			AttackPattern pat;
			pat.add(piece);
			Assert::AreEqual(1, pat.getPieceCount(piece));
		}
	}

	TEST_METHOD(Piece_Count_Total_Matches) {
		for (int trial = 0; trial < 1000; ++trial) {
			AttackPattern pat;
			int n = rand() % 7;
			for (int i = 1; i <= n; ++i) {
				pat.add(Piece::random());
			}

			int m = 0;
			FOR_PIECE_NOT_BISHOP(piece) {
				m += pat.getPieceCount(piece);
			}
			Assert::AreEqual(n, m);
		}
	}

	TEST_METHOD(Multi_Add) {
		for (int trial = 0; trial < 1000; ++trial) {
			AttackPattern pat0;
			int counts[7] = { 0 };

			int n = rand() % 7;
			for (int i = 1; i <= n; ++i) {
				Piece randPiece = Piece::random();
				pat0.add(randPiece);
				counts[randPiece.asIndex()]++;
			}

			AttackPattern pat1;
			FOR_PIECE_ALL(piece) {
				pat1.add(piece, counts[piece.asIndex()]);
			}
			Assert::AreEqual(pat0, pat1);

		}
	}

	TEST_METHOD(Smallest_Piece) {
		for (int trial = 0; trial < 1000; ++trial) {
			Piece smallest = Piece::UNKNOWN();
			AttackPattern pat0;
			int n = rand() % 7;
			for (int i = 1; i <= n; ++i) {
				Piece randPiece = Piece::random();
				if (randPiece == Piece::BISHOP()) {
					continue;
				}
				pat0.add(randPiece);
				smallest = std::min(smallest, randPiece);
			}
			Assert::AreEqual(smallest, pat0.getSmallestPiece());
		}
	}

	TEST_METHOD(NB_Incremented_Before_P) {
		AttackPattern pat;
		pat.add(Piece::BISHOP());
		pat.add(Piece::KNIGHT());
		pat.add(Piece::PAWN());

		Assert::AreEqual(2, pat.getPieceCount(Piece::KNIGHT()));
	}

	TEST_METHOD(Full_Up_0) {
		AttackPattern pat;

		pat.add(Piece::PAWN());
		pat.add(Piece::PAWN());
		Assert::AreEqual(2, pat.getPieceCount(Piece::PAWN()));

		pat.add(Piece::ROOK());
		Assert::AreEqual(1, pat.getPieceCount(Piece::ROOK()));

		pat.add(Piece::KNIGHT());
		Assert::AreEqual(2, pat.getPieceCount(Piece::KNIGHT()));
		Assert::AreEqual(1, pat.getPieceCount(Piece::PAWN()));

		pat.add(Piece::KNIGHT());
		Assert::AreEqual(2, pat.getPieceCount(Piece::PAWN()));

		pat.add(Piece::ROOK());
		Assert::AreEqual(2, pat.getPieceCount(Piece::ROOK()));

		pat.add(Piece::KING());
		Assert::AreEqual(1, pat.getPieceCount(Piece::KING()));
	}

	TEST_METHOD(Full_Up_1) {
		AttackPattern pat;
		pat.add(Piece::QUEEN());
		pat.add(Piece::QUEEN());

		Assert::AreEqual(1, pat.getPieceCount(Piece::QUEEN()));
		Assert::AreEqual(1, pat.getPieceCount(Piece::KNIGHT()));
	}

	AttackPattern randPattern() {
		AttackPattern pat;
		int n = rand() % 7;
		for (int i = 1; i <= n; ++i) {
			pat.add(Piece::random());
		}
		return pat;
	}
	TEST_METHOD(Or_Operator) {
		for (int trial = 0; trial < 1000; trial++) {
			AttackPattern pat0 = randPattern(), pat1 = randPattern();
			AttackPattern or = pat0 | pat1;
			FOR_PIECE_ALL(piece) {
				Assert::AreEqual(pat0.contains(piece)||pat1.contains(piece) , or.contains(piece));
			}
		}
	}

	};
}