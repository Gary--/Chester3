#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Game_move_counters) {
public:

	void checkedMakeMove(std::string moveStr) {
		Move move = Game::getMove(moveStr);
		Assert::AreNotEqual(Move::INVALID(), move);
		Game::makeMove(move);
	}

	TEST_METHOD(Full_Move_Counter_Increments_After_Black_Moves) {
		Game::configure(GameConfiguration::INITIAL);
		Assert::AreEqual(1, Game::getMoveNumber());

		checkedMakeMove("e2e4");
		Assert::AreEqual(1, Game::getMoveNumber());

		checkedMakeMove("e7e5");
		Assert::AreEqual(2, Game::getMoveNumber());

		Game::undoMove();
		Assert::AreEqual(1, Game::getMoveNumber());

		Game::undoMove();
		Assert::AreEqual(1, Game::getMoveNumber());
	}

	TEST_METHOD(Half_Move_Clock) {
		Game::configure(GameConfiguration::INITIAL);
		Assert::AreEqual(0, Game::getHalfMoveClock());

		checkedMakeMove("b1c3");
		Assert::AreEqual(1, Game::getHalfMoveClock());

		checkedMakeMove("g8f6");
		Assert::AreEqual(2, Game::getHalfMoveClock());

		checkedMakeMove("e2e4");
		Assert::AreEqual(0, Game::getHalfMoveClock());

		checkedMakeMove("f6e4");
		Assert::AreEqual(0, Game::getHalfMoveClock());

		checkedMakeMove("c3e4");
		Assert::AreEqual(0, Game::getHalfMoveClock());

		Game::undoMove();
		Assert::AreEqual(0, Game::getHalfMoveClock());
		
		Game::undoMove();
		Assert::AreEqual(0, Game::getHalfMoveClock());

		Game::undoMove();
		Assert::AreEqual(2, Game::getHalfMoveClock());

		Game::undoMove();
		Assert::AreEqual(1, Game::getHalfMoveClock());

		Game::undoMove();
		Assert::AreEqual(0, Game::getHalfMoveClock());
	}

	TEST_METHOD(Repeat_Count) {
		Game::configure(GameConfiguration::INITIAL);
		Assert::AreEqual(1, Game::getRepeatCount());

		checkedMakeMove("b1c3");
		Assert::AreEqual(1, Game::getRepeatCount());

		checkedMakeMove("g8f6");
		Assert::AreEqual(1, Game::getRepeatCount());

		checkedMakeMove("c3b1");
		Assert::AreEqual(1, Game::getRepeatCount());

		checkedMakeMove("f6g8");
		Assert::AreEqual(2, Game::getRepeatCount());

		checkedMakeMove("b1c3");
		Assert::AreEqual(2, Game::getRepeatCount());

		checkedMakeMove("g8f6");
		Assert::AreEqual(2, Game::getRepeatCount());

		checkedMakeMove("e2e4");
		Assert::AreEqual(1, Game::getRepeatCount());


	}

	};


}