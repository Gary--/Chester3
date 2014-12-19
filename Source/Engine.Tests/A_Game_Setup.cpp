#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Game_setup) {
public:

	void testConvert(std::string FEN) {
		GameConfiguration conf(FEN);
		Game::configure(conf);
		Assert::AreEqual(conf.str(), Game::getGameConfiguration().str());
	}

	TEST_METHOD(Game_Configure_and_Extract_Configuration) {
		testConvert("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		testConvert("rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2");
		testConvert("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1");
		testConvert("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 31 1");
		testConvert("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 13 1");
		testConvert("r2q1rk1/pP1p2pp/Q4n2/bbp1p3/Np6/1B3NBn/pPPP1PPP/R3K2R b KQ - 3 1");
	}

	TEST_METHOD(Voids_Enpeasent_when_not_possible) {
		Game::configure(GameConfiguration("rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"));
		Assert::AreEqual(GameConfiguration::NO_ENPEASENT_COLUMN, Game::getEnpeasentColumn());
	}
	};


}