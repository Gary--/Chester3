#include "stdafx.h"
#include "CppUnitTest.h"
#include "Evaluation.h"
#include "Evaluation_test_helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation_kingDanger) {
public:

	TEST_METHOD(Initial_Position_no_Danger) {
		confSync("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		Assert::AreEqual(0, Evaluation::kingDanger(Turn::WHITE()));
		Assert::AreEqual(0, Evaluation::kingDanger(Turn::BLACK()));
		Assert::AreEqual(AttackPattern(), Evaluation::DEBUG_kingDangerPattern(Turn::WHITE()));
		Assert::AreEqual(AttackPattern(), Evaluation::DEBUG_kingDangerPattern(Turn::BLACK()));

	}

	void assertPatten(const char* str, Turn turn) {
		AttackPattern pat = Evaluation::DEBUG_kingDangerPattern(turn);
		Assert::AreEqual(std::string(str), pat.str().substr(2));
	}
	int danger(const char* FEN, Turn turn) {
		confSync(FEN);
		return Evaluation::kingDanger(turn);
	}
	TEST_METHOD(Case_0) {
		confSync("rnb1kbnr/pppp1ppp/3qp3/8/8/7P/PPPPPPP1/RNBQ1RK1 w - -");
		Assert::IsTrue(Evaluation::kingDanger(Turn::WHITE()) > 0);
		Assert::AreEqual(0, Evaluation::kingDanger(Turn::BLACK()));

		assertPatten("", Turn::BLACK());
		assertPatten("q", Turn::WHITE());
	}

	TEST_METHOD(Case_1) {
		confSync("5rk1/Q4pPp/2p1p3/3p4/5N1N/7q/1pPPP2r/3K4 b - -");
		Assert::IsTrue(Evaluation::kingDanger(Turn::WHITE()) > 0);
		Assert::IsTrue(Evaluation::kingDanger(Turn::BLACK()) > 0);

		assertPatten("pnq", Turn::BLACK());
		assertPatten("prq", Turn::WHITE());
	}

	TEST_METHOD(More_Pattern_more_danger_0) {
		Assert::AreEqual(0,danger("rnbqkb1r/pppppppp/8/6n1/8/3BPN2/PPPP1PPP/RNBQ2KR w - -",Turn::WHITE()));//too little threat
		Assert::IsTrue(danger(    "rnb1kb1r/pppqpppp/3p4/6n1/8/3BPN2/PPPP1PPP/RNBQ2KR w - -", Turn::WHITE()) > 0);	
	}

	TEST_METHOD(Defending_Squares_Helps) {
		Assert::IsTrue(danger("rnb1kb1r/ppp1pppp/3q4/6n1/8/3BPN2/PPPP1PPP/RNBQ1RK1 w - -", Turn::WHITE()) <
					   danger("rnb1kb1r/ppp1pppp/3q4/6n1/8/3BP3/PPPPNPPP/RNBQ1RK1 w - -",Turn::WHITE()));
	}

	TEST_METHOD(Having_Blocker_Helps) {
		Assert::IsTrue(danger("rnb1kb1r/ppp1pppp/3q4/6n1/8/3BP2P/PPPPNPP1/RNBQ1RK1 w - -", Turn::WHITE()) >
					   danger("rnb1kb1r/ppp1pppp/3q4/6n1/8/3BP3/PPPPNPPP/RNBQ1RK1 w - -", Turn::WHITE()));
	}


	TEST_METHOD(High_danger) {
		Assert::IsTrue(danger("3r1rk1/B4ppp/2pb4/8/1n4n1/2N2N1q/PP2QP2/R4RK1 w - -", Turn::WHITE()) > 100);
	}

	TEST_METHOD(King_Out_of_Back_row) {
		Assert::AreNotEqual(0, danger("rnbqkbnr/pppppppp/8/8/8/4P3/PPPPKPPP/RNBQ1BNR w- -", Turn::WHITE()));
		Assert::IsTrue(danger("rnbqkbnr/pppppppp/8/8/8/4P3/PPPPKPPP/RNBQ1BNR w - -", Turn::WHITE()) <
					   danger("rnbqkbnr/pppppppp/8/8/8/3KP3/PPPP1PPP/RNBQ1BNR w - -", Turn::WHITE()));
	}

	TEST_METHOD(King_Out_of_Back_row_less_than_2_minors) {
		Assert::IsTrue(danger("r2qk2r/pppppppp/8/8/8/3KP3/PPPP1PPP/RNBQ1BNR w - -", Turn::WHITE()) > 0);
		Assert::AreEqual(0, danger("r2qk3/pppppppp/8/8/8/3KP3/PPPP1PPP/RNBQ1BNR w - -",Turn::WHITE()));
	}

	};
}

