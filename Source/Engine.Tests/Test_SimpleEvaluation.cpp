#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Evaluate_simple.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_SimpleEvaluation) {
public:

#pragma region Logic checks
	TEST_METHOD(Non_zero_symetrical) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		Game::configure(conf);

		SimpleEvaluation::synchronize();
		FOR_TURN(turn) {
			Assert::AreNotEqual(0, SimpleEvaluation::evaluateMaterial(turn));
			Assert::AreNotEqual(0, SimpleEvaluation::evaluatePosition(turn));
		}

		Assert::AreEqual(SimpleEvaluation::evaluateMaterial(Turn::WHITE()),
						 SimpleEvaluation::evaluateMaterial(Turn::BLACK()));
		Assert::AreEqual(SimpleEvaluation::evaluatePosition(Turn::WHITE()),
						 SimpleEvaluation::evaluatePosition(Turn::BLACK()));
	}

	TEST_METHOD(Full_Evaluation_Is_Sum) {
		GameConfiguration conf("8/6b1/7r/Pk2p3/1n4Np/K1P1P3/1B6/1b6 b - -");
		Game::configure(conf);

		FOR_TURN(turn) {
			Assert::AreEqual(SimpleEvaluation::evaluateFull(turn),
							 SimpleEvaluation::evaluateMaterial(turn) +
							 SimpleEvaluation::evaluatePosition(turn));
		}
	}

	// For every move available, check that the incremental update matches the full update.
	void testIncremental(const char* FEN) {
		GameConfiguration confs[2] = { GameConfiguration(FEN), GameConfiguration(FEN).mirror() };

		for (auto conf : confs) {
			Game::configure(conf);
			SimpleEvaluation::synchronize();

			int initals[2];// Score at the original configuration
			FOR_TURN(turn) {
				initals[turn.asIndex()] = SimpleEvaluation::evaluateFull(turn);
			}

			std::vector<int> scores[2];//for each side using incremental
			for (Move move : Game::getAllMoves()) {
				Game::makeMove(move);
				SimpleEvaluation::notifyMove(move, !Game::getTurn());

				FOR_TURN(turn) {// Save the score this move
					scores[turn.asIndex()].push_back(SimpleEvaluation::evaluateFull(turn));
				}

				Game::undoMove();
				SimpleEvaluation::notifyUndoMove(move, Game::getTurn());

				FOR_TURN(turn) {// Make sure original score is preserved.
					Assert::AreEqual(initals[turn.asIndex()], SimpleEvaluation::evaluateFull(turn));
				}
			}

			// Check results agains those using full synchronize.
			int i = 0;
			for (Move move : Game::getAllMoves()) {
				Game::makeMove(move);
				SimpleEvaluation::synchronize();
				FOR_TURN(turn) {
					Assert::AreEqual(scores[turn.asIndex()][i],
									 SimpleEvaluation::evaluateFull(turn));
				}
				Game::undoMove();

				i++;
			}

		}
	}

	TEST_METHOD(Normal_Capturing_Incremental) {
		testIncremental("6k1/8/2N3qQ/7P/1r3bR1/2Kp4/3n4/1B6 w - -");
	}

	TEST_METHOD(Promotion_Incremental) {
		testIncremental("8/2P5/8/8/8/8/1K4k1/8 w - -");
	}

	TEST_METHOD(Enpeasent_Incremental) {
		testIncremental("8/8/8/1PpP4/8/8/K7/2k5 w - c6");
	}

	TEST_METHOD(Castling_Incremental){
		testIncremental("6k1/8/8/8/8/8/8/R3K2R w KQ -");
	}

#pragma endregion
	};
}