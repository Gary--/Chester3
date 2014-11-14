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

	TEST_METHOD(Initial_King_Hit_By_Queen) {
		Game::configure(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
		AttackMap::synchronize();

		Assert::AreEqual("1:Q", AttackMap::getAttackPattern(Turn::WHITE(), Position("e1")).str().c_str());
	}


	};
}