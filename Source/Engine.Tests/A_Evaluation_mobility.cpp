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
	int evalRel(const char* FEN,Turn turn) {
		confSync(GameConfiguration(FEN));
		return Evaluation::relativeMobility(turn);
	}
	int evalEx(const char* FEN, Turn turn) {
		confSync(GameConfiguration(FEN));
		return Evaluation::exactMobility(turn);
	}

	TEST_METHOD(Initial_Position_Bad_Mobility) {
		Assert::IsTrue(evalEx("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -", Turn::WHITE()) < 0);
	}

	TEST_METHOD(Advancing_Knights_Is_Good) {
		Assert::IsTrue(evalRel("rnbqkbnr/pppppppp/8/8/8/2N2N2/PPPPPPPP/R1BQKB1R w - -",Turn::WHITE()) > 
					   evalRel("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -", Turn::WHITE()));
		Assert::IsTrue(evalEx("rnbqkbnr/pppppppp/8/8/8/2N2N2/PPPPPPPP/R1BQKB1R w - -", Turn::WHITE()) > 
					   evalEx("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -", Turn::WHITE()));
	}

	TEST_METHOD(Knights_Hindered_By_Pawn_Threats) {
		Assert::IsTrue(
			evalRel("rnbqkbnr/pppppppp/8/8/8/2N2N2/PPPPPPPP/R1BQKB1R w - -",Turn::WHITE()) >
			evalRel("rnbqkbnr/p2pp3/2p2p1p/1p4p1/8/2N2N2/PPPPPPPP/R1BQKB1R w - -",Turn::WHITE()));
	}

	TEST_METHOD(Knight_Outpost) {
		Assert::IsTrue(
			evalEx("rnbqkbnr/pppp3p/5N2/4ppp1/8/8/PPPPPPPP/RNBQKB1R w - -", Turn::WHITE()) >
			evalEx("rnbqkbnr/pppp2pp/5N2/4pp2/8/8/PPPPPPPP/RNBQKB1R w - -", Turn::WHITE())
			);
	}

	TEST_METHOD(Rook_Half_Open_File) {
		Assert::IsTrue(
			evalRel("rnbqkbnr/pppppppp/8/8/8/8/PPPPP1PP/RNBQ1RK1 w - -", Turn::WHITE()) >
			evalRel("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQ1RK1 w - -", Turn::WHITE()));
	}

	TEST_METHOD(Rook_Full_Open_File) {
		Assert::IsTrue(
			evalRel("rnbqk1nr/pppppbpp/8/8/8/8/PPPPP1PP/RNBQ1RK1 w - -", Turn::WHITE()) >
			evalRel("rnbqkbnr/pppppppp/8/8/8/8/PPPPP1PP/RNBQ1RK1 w - -", Turn::WHITE()));
	}

	TEST_METHOD(Rook_Connected) {
		Assert::IsTrue(
			evalEx("rnbqkbnr/pppppppp/8/8/B7/NQ6/PPPPPPPP/3R1RK1 w - -", Turn::WHITE()) >
			evalEx("rnbqkbnr/pppppppp/8/8/B7/NQ6/PPPPPPPP/R4RK1 w - -", Turn::WHITE()));
	}

	TEST_METHOD(Rook_Connected_Open_File) {
		Assert::IsTrue(
			evalEx("rnbqk1nr/pppppbpp/8/8/B7/NQ6/PPPPP1PP/R4RK1 w - -", Turn::WHITE()) >
			evalEx("rnbqkbnr/pppppppp/8/8/B7/NQ6/PPPPP1PP/R4RK1 w - -", Turn::WHITE()) + 5);
	}
	};
}

