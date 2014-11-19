#include "stdafx.h"
#include "CppUnitTest.h"
#include "AttackPattern.h"
#include "AttackMap.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_AttackMap) {
public:

	TEST_METHOD(Initial_Rooks_Not_Hit) {
		Game::configure(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
		AttackMap::synchronize();

		FOR_TURN(turn) {
			Assert::AreEqual(AttackPattern(), AttackMap::getAttackPattern(turn, Position("a1")));
			Assert::AreEqual(AttackPattern(), AttackMap::getAttackPattern(turn, Position("a8")));
			Assert::AreEqual(AttackPattern(), AttackMap::getAttackPattern(turn, Position("h1")));
			Assert::AreEqual(AttackPattern(), AttackMap::getAttackPattern(turn, Position("h8")));

		}
	}

	void patCheck(std::string expect,Turn turn, const char* posStr) {
		Assert::AreEqual(expect, AttackMap::getAttackPattern(turn, Position(posStr)).str());
	}

	TEST_METHOD(Initial_Position) {
		Game::configure(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
		AttackMap::synchronize();

		patCheck("1:q", Turn::WHITE(), "e1");
		patCheck("4:nqk", Turn::WHITE(), "d2");
		patCheck("1:r", Turn::WHITE(), "a2");
		patCheck("3:pn", Turn::WHITE(), "f3");


		patCheck("1:q", Turn::BLACK(), "e8");
		patCheck("4:nqk", Turn::BLACK(), "d7");
		patCheck("1:r", Turn::BLACK(), "a7");
		patCheck("3:pn", Turn::BLACK(), "f6");

		FOR_POSITION_64(pos) {
			if (pos.row() > 2) {
				patCheck("0:", Turn::BLACK(), pos.str().c_str());
			}
			if (pos.row() < 5) {
				patCheck("0:", Turn::WHITE(), pos.str().c_str());
			}
		}
	}

	TEST_METHOD(Hard_0) {
		Game::configure(GameConfiguration("8/3r4/1p2K3/4p1p1/3N1R2/2k2n2/3RQNP1/5q2 w - -"));
		AttackMap::synchronize();

		patCheck("3:nrq", Turn::WHITE(), "d1");
		patCheck("1:q", Turn::BLACK(), "d1");
		patCheck("4:pnrk", Turn::BLACK(), "d4");
		patCheck("1:k", Turn::BLACK(), "c4");
		patCheck("1:q", Turn::WHITE(), "c4");
		patCheck("0:", Turn::WHITE(), "a1");
	}

	TEST_METHOD(Hard_1) {
		Game::configure(GameConfiguration("8/4n3/3bp3/3BP3/K7/8/1k6/8 w - -"));
		AttackMap::synchronize();

		patCheck("1:k", Turn::WHITE(), "a3");
		patCheck("1:n", Turn::WHITE(), "a2");

		patCheck("0:", Turn::BLACK(), "f8");
		patCheck("0:", Turn::WHITE(), "f7");
		patCheck("2:nk", Turn::BLACK(), "a3");
		patCheck("1:p", Turn::WHITE(), "d6");
	}

	void assert_onTheFly_and_precompute_matchImpl(int depth) {
		AttackPattern pats[2][128];

		FOR_TURN(turn) {
			FOR_POSITION_64(pos) {
				pats[turn.asIndex()][pos.index()] = AttackMap::getAttackPattern(turn, pos);
			}
		}
		AttackMap::precompute();
		FOR_TURN(turn) {
			FOR_POSITION_64(pos) {
				Assert::AreEqual(pats[turn.asIndex()][pos.index()],
								 AttackMap::getAttackPattern(turn, pos));
			}
		}

		if (depth == 0) {
			return;
		}

		for (Move move : Game::getAllMoves()) {
			Game::makeMove(move);
			AttackMap::notifyMove(move, !Game::getTurn());
			assert_onTheFly_and_precompute_matchImpl(depth - 1);
			Game::undoMove();
			AttackMap::notifyUndoMove(move, Game::getTurn());
		}
	}
	void assertMatch(const char* FEN, int depth) {
		Game::configure(GameConfiguration(FEN));
		AttackMap::synchronize();
		assert_onTheFly_and_precompute_matchImpl(depth);
	}

	TEST_METHOD(onTheFly_and_precompute) {
		assertMatch("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -", 2);
		assertMatch("8/4n3/3bp3/3BP3/K7/8/1k6/8 w - -", 2);
		assertMatch("8/3r4/1p2K3/4p1p1/3N1R2/2k2n2/3RQNP1/5q2 b - -", 2);
		assertMatch("1b2B3/8/1k6/8/4pN2/1KP5/8/7q w - -", 2);
		assertMatch("1b5q/3B4/1k6/8/2P1pN2/1K6/8/8 b - -", 2);

	}
	};
}