#include "stdafx.h"
#include "CppUnitTest.h"
#include "Move.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Game_move_generation) {
public:
	int numTacticalMoves(const char* FEN) {
		Game::configure(GameConfiguration(FEN));

		int i = 0;
		for (Move move : Game::getTacticalMoves()) {
			i++;
		}
		return i;
	}


	TEST_METHOD(Captures_are_Tactical) {
		Assert::AreEqual(4, numTacticalMoves("7k/8/5b2/8/2n2R2/3P4/1N6/7K w - - "));
	}

	TEST_METHOD(Enpeasent_is_Tactical) {
		Assert::AreEqual(1, numTacticalMoves("8/8/8/3pP3/8/8/8/5k1K w - d6"));
	}

	TEST_METHOD(Promotion_is_Tactical) {
		Assert::AreEqual(4, numTacticalMoves("8/2P5/8/8/8/8/5k2/7K w - -"));
	}
	
	TEST_METHOD(Castling_is_not_Tactical) {
		Assert::AreEqual(0, numTacticalMoves("8/4k3/8/8/8/8/8/R3K2R w KQ -"));
	}


	TEST_METHOD(Generate_All_After_Tactical_Only) {
		const char* FEN = "8/2P5/8/8/8/8/8/5k1K w - -";
		Game::configure(GameConfiguration(FEN));

		int numTactical = 0;
		for (Move move : Game::getTacticalMoves()) {
			numTactical++;
		}
		Assert::AreEqual(4, numTactical);

		int numTotal = 0;
		for (Move move : Game::getAllMoves()) {
			numTotal++;
		}
		Assert::AreEqual(5, numTotal);
	}

	TEST_METHOD(Generate_Tactical_Only_After_All) {
		const char* FEN = "8/2P5/8/8/8/8/8/5k1K w - -";
		Game::configure(GameConfiguration(FEN));

		int numTotal = 0;
		for (Move move : Game::getAllMoves()) {
			numTotal++;
		}
		Assert::AreEqual(5, numTotal);

		int numTactical = 0;
		for (Move move : Game::getTacticalMoves()) {
			numTactical++;
		}
		Assert::AreEqual(4, numTactical);
	}

	TEST_METHOD(Generate_Tactical_MakeUnMake_Generate_All) {
		const char* FEN = "8/2P5/8/8/8/8/8/5k1K w - -";
		Game::configure(GameConfiguration(FEN));

		int numTactical = 0;
		for (Move move : Game::getTacticalMoves()) {
			numTactical++;

			if (move.isPromotion() && move.promotionPiece()==Piece::QUEEN()) {
				Game::makeMove(move);
				Game::getAllMoves();
				Game::undoMove();
			}
		}
		Assert::AreEqual(4, numTactical);

		int numTotal = 0;
		for (Move move : Game::getAllMoves()) {
			numTotal++;
		}
		Assert::AreEqual(5, numTotal);
	}

	TEST_METHOD(Generate_All_MakeUnMake_Generate_Tactical) {
		const char* FEN = "8/2P5/8/8/8/8/8/5k1K w - -";
		Game::configure(GameConfiguration(FEN));

		int numTotal = 0;
		for (Move move : Game::getAllMoves()) {
			numTotal++;
			if (move.getPiece() == Piece::KING()) {
				Game::makeMove(move);
				Game::getAllMoves();
				Game::undoMove();
			}
		}
		Assert::AreEqual(5, numTotal);

		int numTactical = 0;
		for (Move move : Game::getTacticalMoves()) {
			numTactical++;
		}
		Assert::AreEqual(4, numTactical);
	}

	};
}