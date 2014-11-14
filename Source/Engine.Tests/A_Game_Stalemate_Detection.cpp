#include "stdafx.h"
#include "CppUnitTest.h"
#include "Move.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Game_stalemate_detection) {
public:

	void testHasMove(const char* FEN, bool hasMove) {
		GameConfiguration conf(FEN);

		Game::configure(conf);
		Assert::AreEqual(hasMove, Game::areMovesAvailable());

		Game::configure(conf.mirror());
		Assert::AreEqual(hasMove, Game::areMovesAvailable());
	}
	void yes(const char* FEN) {
		testHasMove(FEN, true);
	}
	void no(const char* FEN) {
		testHasMove(FEN, false);
	}

	TEST_METHOD(Starting_Position_Has_Move) {
		yes("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
	}

	TEST_METHOD(Stalemate_0) {
		no("8/8/8/8/8/8/7R/k1K5 b - -");
	}

	TEST_METHOD(Stalemate_1) {
		no("8/8/8/p7/P7/8/7R/k1K5 b - -");
	}

	TEST_METHOD(Stalemate_2) {
		no("8/8/2p1p3/1pP1Pp2/1N1n1P2/1p3p2/1Np1pN1R/k1K1Q3 b - -");
	}

	TEST_METHOD(Stalemate_3) {
		no("4R3/8/8/8/R7/5kpp/4p1pp/4K1nq b - - ");
	}
	
	TEST_METHOD(Stalemate_4) {
		no("7b/8/8/8/8/k7/1R1n4/K7 w - - ");
	}

	TEST_METHOD(Stalemate_5) {
		no("2r1r3/8/8/r7/3KB2r/r7/8/6k1 w - -");
	}

	};


}