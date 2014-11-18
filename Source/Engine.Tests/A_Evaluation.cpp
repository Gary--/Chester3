#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Evaluation.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation) {
public:


	TEST_METHOD(Non_zero_symetrical) {
		GameConfiguration conf("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		Game::configure(conf);

		Evaluation::synchronize();
		FOR_TURN(turn) {
			Assert::AreNotEqual(0, Evaluation::material(turn));
		}
	}
	void confSync(GameConfiguration conf) {
		Game::configure(conf);
		Evaluation::synchronize();
	}
	int eval(GameConfiguration conf, Turn turn) {
		confSync(conf);
		return Evaluation::material(turn);
	}

	TEST_METHOD(Losing_A_Piece_Is_Bad) {
		GameConfiguration conf("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -");//Kiwipete

		int initials[2] = { eval(conf, Turn::BLACK()), eval(conf, Turn::WHITE()) };

		FOR_POSITION_64(pos) {
			Turn owner = conf.getOwnerAt(pos);
			Piece piece = conf.getPieceAt(pos);
			if (piece == Piece::KING() || piece == Piece::EMPTY()) {
				continue;
			}

			conf.clearPieceAt(pos);
			confSync(conf);
			Assert::IsTrue(eval(conf, owner) < initials[owner.asIndex()]);

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

	void assertSymmetry(const char* FEN) {
		FOR_TURN(turn) {
			const Turn other = !turn;
			GameConfiguration conf(FEN);

			confSync(conf);
			int material = Evaluation::material(turn);
			int materialBalence = Evaluation::materialBalance();
			int mobility = Evaluation::mobility();
			int kingDanger = Evaluation::kingDanger(turn);
			int misc = Evaluation::misc(turn);

			confSync(conf.mirror());
			Assert::AreEqual(material, Evaluation::material(other));
			Assert::AreEqual(-materialBalence, Evaluation::materialBalance());
			Assert::AreEqual(-mobility, Evaluation::mobility());
			Assert::AreEqual(kingDanger, Evaluation::kingDanger(other));
			Assert::AreEqual(misc, Evaluation::misc(other));
		}
	}


	TEST_METHOD(Symmetry) {
		assertSymmetry("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -");
		assertSymmetry("rnbqkbnr/pppp3p/5N2/4ppp1/8/8/PPPPPPPP/RNBQKB1R w - -");
		assertSymmetry("rnbqkbnr/pppppppp/8/8/8/2N2N2/PPPPPPPP/R1BQKB1R w - -");
		assertSymmetry("rnbqkbnr/p2pp3/2p2p1p/1p4p1/8/2N2N2/PPPPPPPP/R1BQKB1R w - -");
		assertSymmetry("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQ1RK1 w - -");
		assertSymmetry("rnbqk1nr/pppppbpp/8/8/8/8/PPPPP1PP/RNBQ1RK1 w - -");
		assertSymmetry("rnbqkbnr/pppppppp/8/8/B7/NQ6/PPPPPPPP/R4RK1 w - -");
	}

	};
}

