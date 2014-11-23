#include "stdafx.h"
#include "CppUnitTest.h"
#include "Evaluation_test_helpers.h"
#include "Evaluation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation_misc) {
public:

	int bishopPair(const char* FEN) {
		confSync(FEN);
		return Evaluation::DEBUG_bishopPairScore(Turn::WHITE());
	}

	TEST_METHOD(Bishop_pair_is_good) {
		Assert::IsTrue(bishopPair("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -") > 0);
		Assert::AreEqual(0, bishopPair("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQK1NR w - -"));

		Assert::AreEqual(0, bishopPair("rnbqkbnr/pppppppp/8/8/8/B7/PPPPPPPP/RNBQK1NR w - -"));
		Assert::AreEqual(0, bishopPair("rnbqkbnr/pppppppp/8/8/8/7B/PPPPPPPP/RN1QKBNR w - -"));
	}

	TEST_METHOD(Bishop_pair_scales_with_pawns) {
		Assert::IsTrue(bishopPair("rnbqkbnr/pppppp1p/8/8/8/8/PPPPPPPP/RNBQKBNR w - -") >
					   bishopPair("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
		Assert::IsTrue(bishopPair("rnbqkbnr/pppppp2/8/8/8/8/PPPPPPPP/RNBQKBNR w - -") >
					   bishopPair("rnbqkbnr/pppppp1p/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Bishop_pair_better_when_they_no_light_pieces) {
		Assert::IsTrue(bishopPair("r2qk2r/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -") >
					   bishopPair("r2qkb1r/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));

		Assert::IsTrue(bishopPair("r2qk2r/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -") >
					   bishopPair("r2qkb1r/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));

		Assert::AreEqual(bishopPair("r2qkb1r/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"),
						 bishopPair("r2qk1nr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
	}


	};


}