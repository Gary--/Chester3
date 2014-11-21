#include "stdafx.h"
#include "CppUnitTest.h"
#include "Evaluation.h"
#include "Evaluation_test_helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation) {
public:


	TEST_METHOD(Non_zero_symetrical) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		confSync(conf);


		FOR_TURN(turn) {
			Assert::AreNotEqual(0, Evaluation::material(turn));
		}
	}

	int eval(GameConfiguration conf, Turn turn) {
		confSync(conf);
		return Evaluation::material(turn);
	}

	TEST_METHOD(Losing_A_Piece_Is_Bad) {
		GameConfiguration conf("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -");//Kiwipete

		int initials[2] = { eval(conf, Turn::BLACK()), eval(conf, Turn::WHITE()) };
		double initialLateness = Evaluation::lateness();
		FOR_POSITION_64(pos) {
			Turn owner = conf.getOwnerAt(pos);
			Piece piece = conf.getPieceAt(pos);
			if (piece == Piece::KING() || piece == Piece::EMPTY()) {
				continue;
			}

			conf.clearPieceAt(pos);
			confSync(conf);
			Assert::IsTrue(eval(conf, owner) < initials[owner.asIndex()]);
			Assert::IsTrue(initialLateness < Evaluation::lateness());

			conf.setPieceAt(pos, owner, piece);
		}
	}

	TEST_METHOD(Material_Balance) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");

		confSync(conf);
		Assert::AreEqual(0, Evaluation::materialBalance());

		conf.clearPieceAt(Position("a8"));
		confSync(conf);
		int b1 = Evaluation::materialBalance();
		Assert::IsTrue(b1 > 0);

		conf.clearPieceAt(Position("a1"));
		conf.clearPieceAt(Position("h8"));
		confSync(conf);
		Assert::IsTrue(Evaluation::materialBalance() > b1);

		// black equivalent
		conf = GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		conf.clearPieceAt(Position("a1"));

		confSync(conf);
		int b2 = Evaluation::materialBalance();
		Assert::IsTrue(b2 < 0);

		conf.clearPieceAt(Position("a8"));
		conf.clearPieceAt(Position("h1"));
		confSync(conf);
		Assert::IsTrue(Evaluation::materialBalance() < b2);
	}

	};
}

