#include "stdafx.h"
#include "CppUnitTest.h"
#include "Evaluation.h"
#include "Evaluation_test_helpers.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation_Mobility) {
public:
	int ex_Bishop(const char* FEN,Turn turn) {
		confSync(GameConfiguration(FEN));
		return Evaluation::DEBUG_bishopExactMobility(turn);
	}
	int rel_Bishop(const char* FEN, Turn turn) {
		confSync(GameConfiguration(FEN));
		return Evaluation::DEBUG_bishopRelativeMobility(turn);
	}
	int ex_Knight(const char* FEN, Turn turn) {
		confSync(GameConfiguration(FEN));
		return Evaluation::DEBUG_knightExactMobility(turn);
	}
	int rel_Knight(const char* FEN, Turn turn) {
		confSync(GameConfiguration(FEN));
		return Evaluation::DEBUG_knightRelativeMobility(turn);
	}
	int ex_Rook(const char* FEN, Turn turn) {
		confSync(GameConfiguration(FEN));
		return Evaluation::DEBUG_rookExactMobility(turn);
	}
	int rel_Rook(const char* FEN, Turn turn) {
		confSync(GameConfiguration(FEN));
		return Evaluation::DEBUG_rookRelativeMobility(turn);
	}

	TEST_METHOD(Bishop_Knight_Minimum_Mobility) {
		Assert::IsTrue(ex_Knight("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -", Turn::WHITE()) < 0);
		Assert::IsTrue(ex_Bishop("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -", Turn::WHITE()) < 0);
	}

	TEST_METHOD(Bishop_Freedom) {
		Assert::IsTrue(rel_Bishop("rnbqkbnr/pppppppp/8/8/8/4P3/PPPP1PPP/RNBQKBNR w - -", Turn::WHITE()) >
					   rel_Bishop("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -", Turn::WHITE()));
	}

	TEST_METHOD(Advancing_Knights_Is_Good) {
		Assert::IsTrue(ex_Knight("rnbqkbnr/pppppppp/8/8/8/2N2N2/PPPPPPPP/R1BQKB1R w - -", Turn::WHITE()) >
					   ex_Knight("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -", Turn::WHITE()));
		Assert::IsTrue(rel_Knight("rnbqkbnr/pppppppp/8/8/8/2N2N2/PPPPPPPP/R1BQKB1R w - -", Turn::WHITE()) >
					   rel_Knight("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -", Turn::WHITE()));
	}

	TEST_METHOD(Knights_Hindered_By_Pawn_Threats) {
		Assert::IsTrue(
			rel_Knight("rnbqkbnr/pppppppp/8/8/8/2N2N2/PPPPPPPP/R1BQKB1R w - -", Turn::WHITE()) >
			rel_Knight("rnbqkbnr/p2pp3/2p2p1p/1p4p1/8/2N2N2/PPPPPPPP/R1BQKB1R w - -", Turn::WHITE()));
	}

	TEST_METHOD(Knight_Outpost) {
		Assert::IsTrue(
			ex_Knight("rnbkqbnr/pppp3p/5N2/4ppp1/8/8/PPPPPPPP/RNBQKB1R w - -", Turn::WHITE()) >
			ex_Knight("rnbkqbnr/pppp2pp/5N2/4pp2/8/8/PPPPPPPP/RNBQKB1R w - -", Turn::WHITE())
			);
	}

	TEST_METHOD(Rook_Half_Open_File) {
		Assert::IsTrue(
			rel_Rook("rnbqkbnr/pppppppp/8/8/8/8/PPPPP1PP/RNBQ1RK1 w - -", Turn::WHITE()) >
			rel_Rook("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQ1RK1 w - -", Turn::WHITE()));
	}

	TEST_METHOD(Rook_Full_Open_File) {
		Assert::IsTrue(
			rel_Rook("rnbqk1nr/pppppbpp/8/8/8/8/PPPPP1PP/RNBQ1RK1 w - -", Turn::WHITE()) >
			rel_Rook("rnbqkbnr/pppppppp/8/8/8/8/PPPPP1PP/RNBQ1RK1 w - -", Turn::WHITE()));
	}

	TEST_METHOD(Rook_Connected) {
		Assert::IsTrue(
			ex_Rook("rnbqkbnr/pppppppp/8/8/B7/NQ6/PPPPPPPP/3R1RK1 w - -", Turn::WHITE()) >
			ex_Rook("rnbqkbnr/pppppppp/8/8/B7/NQ6/PPPPPPPP/R4RK1 w - -", Turn::WHITE()));
	}

	TEST_METHOD(Rook_Connected_Open_File) {
		Assert::IsTrue(
			ex_Rook("rnbqk1nr/pppppbpp/8/8/B7/NQ6/PPPPP1PP/R4RK1 w - -", Turn::WHITE()) >
			ex_Rook("rnbqkbnr/pppppppp/8/8/B7/NQ6/PPPPP1PP/R4RK1 w - -", Turn::WHITE()) + 5);
	}

	TEST_METHOD(Bad_Bishop) {
		Assert::IsTrue(ex_Bishop("rnbqkbnr/pppppppp/8/8/3P4/2B1P3/PPP2PPP/RNBQK1NR w - -", Turn::WHITE()) >
					   ex_Bishop("rnbqkbnr/ppp1pppp/8/3p4/3P4/2B1P3/PPP2PPP/RNBQK1NR w - -", Turn::WHITE()));

		Assert::IsTrue(ex_Bishop("rnb1kbnr/pppppppp/8/3q4/3P4/2B1P3/PPP2PPP/RNBQK1NR w - -", Turn::WHITE()) >
					   ex_Bishop("rnbqkbnr/ppp1pppp/8/3p4/3P4/2B1P3/PPP2PPP/RNBQK1NR w - -", Turn::WHITE()));


		Assert::AreEqual(ex_Bishop("rnbqkbnr/pppppppp/8/3P4/3P4/2B1P3/PPP2PP1/RNBQK1NR w - -", Turn::WHITE()),
					     ex_Bishop("rnbqkbnr/ppp1pppp/8/3p4/3P4/2B1P3/PPP2PPP/RNBQK1NR w - -", Turn::WHITE()));
	}

	TEST_METHOD(Bad_Bishop_Only_Forward_Pawns) {
		Assert::AreEqual(ex_Bishop("rnbqkbnr/pppppppp/8/8/3P1B2/4P3/PPP2PPP/RNBQK1NR w - -", Turn::WHITE()),
						 ex_Bishop("rnb1kbnr/pppppppp/8/8/3PqB2/4P3/PPP2PPP/RNBQK1NR w - -", Turn::WHITE()));
	}

	TEST_METHOD(Bishop_pin) {
		Assert::IsTrue(ex_Bishop("6k1/3q1pp1/7p/4N3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()) <
					   ex_Bishop("6k1/5pp1/3q3p/4N3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()));
		Assert::IsTrue(ex_Bishop("6k1/3r1pp1/7p/4N3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()) <
					   ex_Bishop("6k1/5pp1/3r3p/4N3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()));
		Assert::IsTrue(ex_Bishop("6q1/4kpp1/7p/4N3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()) <
					   ex_Bishop("6q1/5pp1/3k3p/4N3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()));

		Assert::IsTrue(ex_Bishop("6k1/3q1pp1/7p/4n3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()) <
					   ex_Bishop("6k1/5pp1/3q3p/4n3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()));
		Assert::IsTrue(ex_Bishop("6k1/3r1pp1/7p/4n3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()) <
					   ex_Bishop("6k1/5pp1/3r3p/4n3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()));
		Assert::IsTrue(ex_Bishop("6q1/3k1pp1/7p/4n3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()) <
					   ex_Bishop("6q1/5pp1/3k3p/4n3/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()));

		Assert::IsTrue(ex_Bishop("8/2k2pp1/3r3p/8/8/P5B1/1PP5/1K6 w - -", Turn::WHITE()) >= 100);
	}

	TEST_METHOD(Rook_pinn) {
		Assert::IsTrue(ex_Rook("4k3/5pp1/3n3p/8/8/P2R4/1PP5/1K6 w - -", Turn::WHITE()) <
					   ex_Rook("3k4/5pp1/3n3p/8/8/P2R4/1PP5/1K6 w - -", Turn::WHITE()));

		Assert::IsTrue(ex_Rook("4q2k/5pp1/3n3p/8/8/P2R4/1PP5/1K6 w - -", Turn::WHITE()) <
					   ex_Rook("3q3k/5pp1/3n3p/8/8/P2R4/1PP5/1K6 w - -", Turn::WHITE()));

		Assert::IsTrue(ex_Rook("3k4/3q1pp1/7p/8/8/P2R4/1PP5/1K6 w - -", Turn::WHITE()) >= 100);
	}

	};
}

