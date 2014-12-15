#include "stdafx.h"
#include "CppUnitTest.h"
#include "Evaluation_test_helpers.h"
#include "Evaluation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation_pawns_structure) {
public:

	TEST_METHOD(Pushing_pawns_initially_is_good) {
		confSync(GameConfiguration::INITIAL);
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
	int form(GameConfiguration conf) {
		confSync(conf);
		return Evaluation::DEBUG_pawnFormation(Turn::WHITE());
	}
	int form(const char* FEN) {
		return form(GameConfiguration(FEN));
	}
	TEST_METHOD(Lone_Pawn_is_Bad) {
		int initial = form(GameConfiguration::INITIAL);
		GameConfiguration conf(GameConfiguration::INITIAL);

		// Any pawn moving 3 squares forward is bad
		FOR_POSITION_64(pos) {
			if (conf.getPieceAt(pos) == Piece::PAWN() && conf.getOwnerAt(pos).isWhite()) {
				GameConfiguration conf2 = conf;
				conf2.clearPieceAt(pos);
				conf2.setPieceAt(Position(pos.row() - 3, pos.col()),Turn::WHITE(),Piece::PAWN());
				Assert::IsTrue(form(conf2.str_min().c_str()) < initial);
			}
		}
	}

	TEST_METHOD(Lone_Pawn_on_half_open_really_bad) {
		Assert::IsTrue(form("rnb1kbnr/ppp1pppp/8/3P4/8/8/PPP1PPPP/RNBQKBNR w - -") <
					   form("rnb1kbnr/pppppppp/8/3P4/8/8/PPP1PPPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Almost_Protected_Pawn_is_good) {
		int initial = form(GameConfiguration::INITIAL);
		GameConfiguration conf(GameConfiguration::INITIAL);

		// Any pawn moving 2 squares forward is good
		FOR_POSITION_64(pos) {
			if (conf.getPieceAt(pos) == Piece::PAWN() && conf.getOwnerAt(pos).isWhite()) {
				GameConfiguration conf2 = conf;
				conf2.clearPieceAt(pos);
				conf2.setPieceAt(Position(pos.row() - 2, pos.col()), Turn::WHITE(), Piece::PAWN());
				Assert::IsTrue(form(conf2.str_min().c_str()) > initial);
			}
		}
	}

	TEST_METHOD(Side_By_Side_is_good) {
		int initial = form(GameConfiguration::INITIAL);

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
		Assert::IsTrue(form("rnbqkbnr/pppppppp/4P3/4P3/8/8/PPP3PP/RNBQKBNR w - -") + 30 <
					   form("rnbqkbnr/pppppppp/4P3/4P3/8/8/PP3PPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Stacked_on_open_file_extra_bad) {
		Assert::IsTrue(form("rnbqkbnr/pp1ppppp/8/8/8/2P5/PPPP1PPP/RNBQKBNR w - -") <
					   form("rnbqkbnr/pppppppp/8/8/8/2P5/PPPP1PPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Pressure_On_Protected_Pawn_No_Problem) {
		Assert::AreEqual(form("rnbqkbnr/pppppp1p/6p1/8/3P4/2P5/PP2PPPP/RNBQKBNR w - -"),
						 form("r1bqk1nr/ppppppbp/2n3p1/8/3P4/2P5/PP2PPPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Pressure_On_Fighting_Pawn_No_Problem) { //no pressure penalty if we can capture their pawn
		Assert::AreEqual(form("rnbqkbnr/pppppp1p/6p1/8/3P4/8/PPP1PPPP/RNBQKBNR w - -"),
						 form("r1b1kbnr/pppp1p1p/1qn3p1/4p3/3P4/8/PPP1PPPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Pressure_On_Undefended_Pawn_is_Bad) {
		Assert::IsTrue(form("r1bqk1nr/pppppp1p/2n2bp1/8/3P4/5N2/PPP1PPPP/RNBQKB1R w - -") <
					   form("rnbqkbnr/pppppp1p/6p1/8/3P4/5N2/PPP1PPPP/RNBQKB1R w - -"));
	}

	TEST_METHOD(Pawns_Worth_a_lot_late) {
		//slightly subjective. may depend on other factors.
		Assert::IsTrue(form("6k1/2p2npp/2P5/8/8/8/1P3PPP/2R4K w - -") >
					   form("6k1/2p2npp/2P5/8/8/8/6PP/2R4K w - -") + 140);
	}
	};


}