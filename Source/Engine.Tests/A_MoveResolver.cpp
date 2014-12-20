#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "MoveResolver.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


namespace EngineTests {
	TEST_CLASS(A_MoveResolver) {
public:
	void assertSame(string uci, string epd) {
		Assert::AreNotEqual(Move::INVALID(),MoveResolver::resolveUCI(uci));
		Assert::AreEqual(MoveResolver::resolveUCI(uci), MoveResolver::resolveEPD(epd));
	}
	void assertInvalidEpd(string epd) {
		Assert::AreEqual(Move::INVALID(), MoveResolver::resolveEPD(epd));
	}

	TEST_METHOD(Basic_EPD) {
		Game::configure(GameConfiguration::INITIAL);

		assertSame("b1c3", "Nc3");
		assertSame("a2a4", "a4");
		assertSame("c2c3", "c3");

		Game::makeMove(MoveResolver::resolveUCI("a2a4"));

		assertSame("a7a5", "a5");
		assertSame("g8f6", "Nf6");

		assertInvalidEpd("a8");
		assertInvalidEpd("qd4");
	}

	TEST_METHOD(Checks) {
		Game::configure(GameConfiguration("5k2/8/4P3/8/7B/4K1R1/8/8 w - -"));
		
		assertSame("g3f3", "Rf3+");
		assertSame("e6e7", "e7+");
		assertSame("h4e7", "Be7+");
	}

	TEST_METHOD(Enpeasent) {
		Game::configure(GameConfiguration("5k2/8/8/3pP3/8/4K3/8/8 w - d6"));

		assertSame("e5d6", "d6+");
	}

	TEST_METHOD(Disambiguate_Column) {
		Game::configure(GameConfiguration("4k3/8/8/8/R6R/8/3K4/8 w - -"));

		assertSame("a4c4", "Rac4");
		assertSame("h4e4", "Rhe4+");

		assertInvalidEpd("Rc4");
		assertInvalidEpd("Rc4+");
	}

	TEST_METHOD(Disambiguate_Row) {
		Game::configure(GameConfiguration("4k3/8/8/5n2/8/5n2/8/K7 b - -"));

		assertSame("f3d4", "N3d4");
		assertSame("f5d4", "N5d4");
		assertSame("f3h4", "N3h4");
		assertSame("f5h4", "N5h4");

		assertInvalidEpd("Nd4");
		assertInvalidEpd("Nh4");
	}

	TEST_METHOD(Disambiguate_Both_Row_and_Column) {
		Game::configure(GameConfiguration("7k/6pp/2Q1Q3/8/8/8/4Q3/7K w - -"));

		assertSame("c6c4", "Qc6c4");
		assertSame("e6c4", "Qe6c4");
		assertSame("e2c4", "Qe2c4");

		assertInvalidEpd("Q6c4");
		assertInvalidEpd("Qec4");
	}

	TEST_METHOD(Caslting) {
		Game::configure(GameConfiguration("r3k2r/8/8/8/8/8/8/R3K2R w KQkq -"));

		assertSame("e1c1", "O-O-O");
		assertSame("e1g1", "O-O");
	}

	};
}