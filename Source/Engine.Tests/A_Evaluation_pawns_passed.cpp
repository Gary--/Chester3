#include "stdafx.h"
#include "CppUnitTest.h"
#include "Evaluation_test_helpers.h"
#include "Evaluation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation_pawns_passed) {
public:
	BitBoard getPassedPawns(GameConfiguration conf) {
		confSync(conf);
		return Evaluation::DEBUG_passedPawns(Turn::WHITE());
	}
	BitBoard getPassedPawns(const char* FEN) {
		return getPassedPawns(GameConfiguration(FEN));
	}
	int score(const char* FEN) {
		confSync(FEN);
		return Evaluation::DEBUG_passedPawnScore(Turn::WHITE());
	}


	TEST_METHOD(No_passed_pawns_initially) {
		Assert::AreEqual(BitBoard::EMPTY(), getPassedPawns(GameConfiguration::INITIAL));
	}

	TEST_METHOD(All_pawns_passed) {
		Assert::AreEqual(BitBoard::rowBits(6), getPassedPawns("rnbqkbnr/8/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -"));
	}

	TEST_METHOD(Single_passed_0) {
		Assert::AreEqual(Position("a2").asSingletonBitboard(), getPassedPawns("rnbqkbnr/2pppppp/2p5/2p5/8/8/PPPPPPPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Single_passed_1) {
		Assert::AreEqual(Position("d5").asSingletonBitboard(), getPassedPawns("rnbqkbnr/pp3ppp/6p1/2pPp3/8/8/PPP1PPPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Single_passed_2) {
		Assert::AreEqual(Position("d5").asSingletonBitboard(), getPassedPawns("rnbqkbnr/pp4pp/6p1/2pPp3/2PpP3/8/PP3PPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(No_passed_0) {
		Assert::AreEqual(BitBoard::EMPTY(), getPassedPawns("rnbqkbnr/p2p2p1/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
		Assert::AreEqual(BitBoard::EMPTY(), getPassedPawns("rnbqkbnr/1p2p2p/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Passed_pawn_non_zero_score) {
		Assert::IsTrue(score("rnbqkbnr/2pppppp/2p5/2p5/8/8/PPPPPPPP/RNBQKBNR w - -") > 0);
		Assert::IsTrue(score("rnbqkbnr/pp3ppp/6p1/2pPp3/8/8/PPP1PPPP/RNBQKBNR w - -") > 0);
		Assert::IsTrue(score("rnbqkbnr/pp4pp/6p1/2pPp3/2PpP3/8/PP3PPP/RNBQKBNR w - -") > 0);
	}

	TEST_METHOD(No_Passed_Pawn_No_Score) {
		Assert::AreEqual(0, score(GameConfiguration::INITIAL.str_min().c_str()));
		Assert::AreEqual(0, score("rnbqkbnr/p2p2p1/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
		Assert::AreEqual(0, score("rnbqkbnr/1p2p2p/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Clear_Way_is_Good_0) {
		// The 3 squares in front being threatened and not defended is bad
		Assert::AreNotEqual(0, score("r6k/7p/8/7b/7b/2P5/1R1K3P/1N6 w - -"));
		Assert::IsTrue(score("r6k/5b1p/8/8/7b/2P5/1R1K3P/1N6 w - -") <
					   score("r6k/7p/8/7b/7b/2P5/1R1K3P/1N6 w - -"));
		Assert::AreEqual(score("r6k/7p/8/7b/7b/2P5/1R1K3P/1N6 w - -"),
						 score("r6k/5b1p/8/8/7b/2P1N3/1R1K3P/8 w - -"));
		Assert::IsTrue(score("r6k/4bb1p/8/8/8/2P1N3/1R1K3P/8 w - -") <
					   score("r6k/7p/8/7b/7b/2P5/1R1K3P/1N6 w - -"));
		Assert::AreEqual(score("r6k/7p/8/7b/7b/2P5/1R1K3P/1N6 w - -"),
						 score("r6k/4bb1p/8/1R6/8/2P1N3/3K3P/8 w - -"));
		Assert::IsTrue(score("7k/4bb1p/r7/1R6/8/2P1N3/3K3P/8 w - -") <
					   score("r6k/4bb1p/8/1R6/8/2P1N3/3K3P/8 w - -"));
		Assert::AreEqual(score("7k/4bb1p/r7/1R6/8/2P1N3/3K2BP/8 w - -"),
						 score("r6k/7p/8/7b/7b/2P5/1R1K3P/1N2B3 w - -"));
	}

	TEST_METHOD(Blocked_By_Enemy) {
		// The 3 squares in front being blocked is bad
		Assert::IsTrue(score("7k/7p/8/7b/2n4b/2P5/2R2NBP/7K w - -") <
					   score("7k/7p/5n2/7b/7b/2P5/2R2NBP/7K w - -"));
		Assert::IsTrue(score("7k/7p/8/7b/2n4b/2P5/2R2NBP/7K w - -") <
					   score("7k/7p/8/2n4b/7b/2P5/2R2NBP/7K w - -"));
		Assert::IsTrue(score("7k/7p/8/2n4b/7b/2P5/2R2NBP/7K w - -") <
					   score("7k/7p/2n5/7b/7b/2P5/2R2NBP/7K w - -"));
		Assert::AreEqual(score("7k/2n4p/8/7b/7b/2P5/2R2NBP/7K w - -"),
						 score("6nk/7p/8/7b/7b/2P5/2R2NBP/7K w - -"));
	}

	TEST_METHOD(More_points_lateness) {
		// Passed pawns worth more when less material on the board
		Assert::IsTrue(score("4rrnk/5ppp/P7/7b/7b/5NBq/2R2PPP/R6K w - -") <
					   score("6nk/5ppp/P7/8/8/5N2/5PPP/R6K w - -"));
	}

	TEST_METHOD(Us_block_better_than_them_block) {
		// A blocked passed pawn is worth more if we are blocking it
		Assert::IsTrue(score("5r1k/5ppp/8/8/2n5/2PN4/2R2PPP/7K w - -") <
					   score("5r1k/5ppp/n7/8/2N5/2P5/2R2PPP/7K w - -"));
	}

	TEST_METHOD(Defended_blocked) {
		// If a passed pawn is blocked, give points if we have >= 2 pieces defending it
		Assert::IsTrue(score("5r1k/5ppp/8/8/2n5/2P5/2R2PPP/N6K w - -") <
					   score("5r1k/5ppp/8/8/2n5/2P5/2R2PPP/1N5K w - -"));
	}

	TEST_METHOD(Blocked_Square_in_front_controlled) {
		// More points if we are blocked, but we control the next square
		Assert::IsTrue(score("5r1k/5ppp/8/8/2n3N1/2P5/2R2PPP/7K w - -") <
					   score("5r1k/5ppp/8/8/2n5/2P1N3/2R2PPP/7K w - -"));
	}
	
	TEST_METHOD(Connected_passed_pawn_is_good) {
		Assert::IsTrue(score("4nr1k/5ppp/8/8/1pP5/7N/P4PPP/6RK w - -") <
					   score("4nr1k/5ppp/8/8/1pP5/1P5N/5PPP/6RK w - -"));
	
	}

	TEST_METHOD(Rook_Defending_from_in_front_is_REALLY_bad) {
		Assert::IsTrue(score("4nr1k/5ppp/4p3/R7/8/P5PN/5P1P/7K w - -") < 0);
		Assert::IsTrue(score("4nr1k/5ppp/4p3/8/8/P5PN/R4P1P/7K w - -") > 0);//make sure we don't count our rooks behind the pawn

		Assert::IsTrue(score("4nr1k/5ppp/4p3/R7/8/P5PN/5P1P/7K w - -") <
					   score("4nr1k/5ppp/4p3/4R3/8/P5PN/5P1P/7K w - -"));

		// Worse if pawn is threatened
		Assert::IsTrue(score("4nr1k/5ppp/4p3/R7/8/P5PN/r4P1P/7K w - -") <
					   score("4nr1k/5ppp/4p3/R7/8/P5PN/5P1P/7K w - -"));

		// Make sure defending our pawn from front against threat is REALLY bad
		Assert::IsTrue(score("4nr1k/5ppp/4p3/R7/8/P5PN/r4P1P/7K w - -") < -100);
	}

	TEST_METHOD(King_Support_is_good) {
		Assert::IsTrue(score("r3nr1k/5ppp/4p3/8/8/P5PN/2K2P1P/R7 w - -") <
					   score("r3nr1k/5ppp/4p3/8/8/P5PN/1K3P1P/R7 w - -"));
	}

	TEST_METHOD(Distance_to_their_king) {
		Assert::IsTrue(score("6k1/5ppp/8/n7/P7/5N2/5PPP/R6K w - -") <
					   score("7k/5ppp/8/n7/P7/5N2/5PPP/R6K w - -"));
		Assert::IsTrue(score("5k2/5ppp/8/n7/P7/5N2/5PPP/R6K w - -") <
					   score("6k1/5ppp/8/n7/P7/5N2/5PPP/R6K w - -"));
		Assert::IsTrue(score("8/4kppp/8/n7/P7/5N2/5PPP/R6K w - -") <
					   score("5k2/5ppp/8/n7/P7/5N2/5PPP/R6K w - -"));
	}

	};


}