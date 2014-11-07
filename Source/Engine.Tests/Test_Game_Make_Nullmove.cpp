#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_Game_Make_Nullmove) {
public:

	TEST_METHOD(Nullmove_Flips_Turn) {
		Game::configure(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - "));
		Game::makeMove(Move::NULL_MOVE());
		Assert::AreEqual(Turn::BLACK, Game::getTurn());
		Game::makeMove(Move::NULL_MOVE());
		Assert::AreEqual(Turn::WHITE, Game::getTurn());
		Game::undoMove();
		Assert::AreEqual(Turn::BLACK, Game::getTurn());
		Game::undoMove();
		Assert::AreEqual(Turn::WHITE, Game::getTurn());
	}

	TEST_METHOD(Nullmove_Flips_Hash) {
		Game::configure(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - "));
		uint64_t orig = Game::getHash();

		Game::makeMove(Move::NULL_MOVE());
		Assert::AreEqual(~orig, Game::getHash());

		Game::makeMove(Move::NULL_MOVE());
		Assert::AreEqual(orig, Game::getHash());
	}

	TEST_METHOD(NullMove_Voids_Enpeasant) {
		std::string FEN = "8/3k4/8/8/5pP1/8/8/3K4 b - g3";
		Game::configure(GameConfiguration(FEN.c_str()));
		Assert::AreEqual(6, Game::getEnpeasentColumn());

		Game::makeMove(Move::NULL_MOVE());
		Assert::AreEqual(GameConfiguration::NO_ENPEASENT_COLUMN, Game::getEnpeasentColumn());
		
		Game::undoMove();

		Assert::AreEqual(FEN, GameConfiguration::extractFromGame().str_min());
	}

	TEST_METHOD(Move_Generation_Works_After_Nullmove) {
		Game::configure(GameConfiguration("k7/8/8/8/8/8/8/K7 w - -"));
		Game::makeMove(Move::NULL_MOVE());

		Assert::AreEqual(3, Game::getNumValidMoves());
	}

	};
}