#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Evaluation.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation_Mobility) {
public:
	void confSync(GameConfiguration conf) {
		Game::configure(conf);
		Evaluation::synchronize();
	}
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
			ex_Knight("rnbqkbnr/pppp3p/5N2/4ppp1/8/8/PPPPPPPP/RNBQKB1R w - -", Turn::WHITE()) >
			ex_Knight("rnbqkbnr/pppp2pp/5N2/4pp2/8/8/PPPPPPPP/RNBQKB1R w - -", Turn::WHITE())
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
	};
}

