#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Evaluation.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation_kingDanger) {
public:
	void confSync(const char* FEN) {
		Game::configure(GameConfiguration(FEN));
		Evaluation::synchronize();
	}

	TEST_METHOD(Initial_Position_no_Danger) {
		confSync("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		Assert::AreEqual(0, Evaluation::kingDanger(Turn::WHITE()));
		Assert::AreEqual(0, Evaluation::kingDanger(Turn::BLACK()));
	}

	TEST_METHOD(Easy_0) {
		confSync("rnb1kbnr/pppp1ppp/3qp3/8/8/7P/PPPPPPP1/RNBQ1RK1 w - -");
		Assert::IsTrue(Evaluation::kingDanger(Turn::WHITE()) > 0);
		Assert::AreEqual(0, Evaluation::kingDanger(Turn::BLACK()));

	}

	};
}

