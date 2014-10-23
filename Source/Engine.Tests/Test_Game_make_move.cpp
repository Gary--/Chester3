#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_Game_make_move) {
public:
	TEST_CLASS_INITIALIZE(Call_Game_Init) {
		Game::init();
	}

	TEST_METHOD(Resigning) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		Game::configure(conf);
		Game::makeMove(Move::RESIGN());

		Assert::AreEqual(conf.str(), GameConfiguration::extractFromGame().str());
		Assert::AreEqual(GameResult::BLACK_WIN, Game::getState());

		conf.setTurn(Turn::BLACK);
		Game::configure(conf);
		Game::makeMove(Move::RESIGN());

		Assert::AreEqual(conf.str(), GameConfiguration::extractFromGame().str());
		Assert::AreEqual(GameResult::WHITE_WIN, Game::getState());
	}


	};


}