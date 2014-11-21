#include "stdafx.h"
#include "CppUnitTest.h"
#include "Evaluation_test_helpers.h"
#include "Evaluation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation_pawns) {
public:
	TEST_METHOD(Pushing_pawns_initially_is_good) {
		confSync("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		int initial = Evaluation::DEBUG_pawnFormation(Turn::WHITE());
		for (Move move : Game::getAllMoves()) {
			if (move.getPiece() != Piece::PAWN()) {
				continue;
			}

			Game::makeMove(move);
			Evaluation::notifyMove(move, Turn::WHITE());

			int newScore = Evaluation::DEBUG_pawnFormation(Turn::WHITE());
			Assert::IsTrue(newScore > initial);

			Game::undoMove();
			Evaluation::notifyUndoMove(move, Turn::WHITE());

		}
	}

	};


}