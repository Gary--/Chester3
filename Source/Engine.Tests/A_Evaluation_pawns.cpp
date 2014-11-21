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

	int form(const char* FEN) {
		confSync(FEN);
		return Evaluation::DEBUG_pawnFormation(Turn::WHITE());
	}
	TEST_METHOD(Lone_Pawn_is_Bad) {
		int initial = form("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");

		// Any pawn moving 3 squares forward is bad
		FOR_POSITION_64(pos) {
			if (conf.getPieceAt(pos) == Piece::PAWN() && conf.getOwnerAt(pos) == Turn::WHITE()) {
				GameConfiguration conf2 = conf;
				conf2.clearPieceAt(pos);
				conf2.setPieceAt(Position(pos.row() - 3, pos.col()),Turn::WHITE(),Piece::PAWN());
				Assert::IsTrue(form(conf2.str_min().c_str()) < initial);
			}
		}
	}

	TEST_METHOD(Almost_Protected_Pawn_is_good) {
		int initial = form("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");

		// Any pawn moving 2 squares forward is good
		FOR_POSITION_64(pos) {
			if (conf.getPieceAt(pos) == Piece::PAWN() && conf.getOwnerAt(pos) == Turn::WHITE()) {
				GameConfiguration conf2 = conf;
				conf2.clearPieceAt(pos);
				conf2.setPieceAt(Position(pos.row() - 2, pos.col()), Turn::WHITE(), Piece::PAWN());
				Assert::IsTrue(form(conf2.str_min().c_str()) > initial);
			}
		}
	}

	TEST_METHOD(Side_By_Side_is_good) {
		int initial = form("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");

		for (int c = 0; c < 7; ++c) {
			Position pos(6, c);
			GameConfiguration conf2 = GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
			conf2.clearPieceAt(pos);
			conf2.clearPieceAt(Position(6, c + 1));
			conf2.setPieceAt(Position(3, c), Turn::WHITE(), Piece::PAWN());
			conf2.setPieceAt(Position(3, c+1), Turn::WHITE(), Piece::PAWN());
			Assert::IsTrue(form(conf2.str_min().c_str()) > initial);
		}
	}

	TEST_METHOD(Doubled_Pawns_are_Bad) {
		int initial = form("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		for (int c = 0; c < 7; ++c) {
			Position pos(6, c);
			GameConfiguration conf2 = GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
			conf2.clearPieceAt(pos);
			conf2.setPieceAt(Position(5, c+1), Turn::WHITE(), Piece::PAWN());
			Assert::IsTrue(form(conf2.str_min().c_str()) < initial);
		}
	}

	TEST_METHOD(Tripled_Pawn_really_bad) {
		Assert::IsTrue(form("rnbqkbnr/pppppppp/8/3P4/3P4/3P4/PPP3PP/RNBQKBNR w - -") <= -100);
	}

	TEST_METHOD(Stacked_isolated_extra_bad) {
		Assert::IsTrue(form("rnbqkbnr/pppppppp/3P4/3P4/8/8/PP3PPP/RNBQKBNR w - -") <
					   form("rnbqkbnr/pppppppp/3P4/3P4/8/8/PPP2PPP/RNBQKBNR w - -") + 30);
	}

	TEST_METHOD(Stacked_on_open_file_extra_bad) {

	}

	};


}