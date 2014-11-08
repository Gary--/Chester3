#include "stdafx.h"
#include "CppUnitTest.h"
#include "static_exchange.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_SEE) {
public:
	TEST_CLASS_INITIALIZE(Call_SEE_init) {
		SEE::init();
	}

	TEST_METHOD(No_Defenders) {
		FOR_PIECE_ALL(piece) {
			AtkPat attackers;
			attackers.add(piece);

			Assert::AreEqual(0, SEE::attackCost(piece, attackers, AtkPat()));
		}
	}

	TEST_METHOD(One_Attacker_One_Defender) {
		FOR_PIECE_ALL(defender) {
			AtkPat defenders;
			defenders.add(defender);

			FOR_PIECE_ALL(attacker) {
				AtkPat attackers;
				attackers.add(attacker);
				Assert::IsTrue(SEE::attackCost(attacker, attackers, defenders) > 0);
			}
		}
	}

	};
}