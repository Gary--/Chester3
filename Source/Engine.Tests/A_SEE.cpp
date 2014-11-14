#include "stdafx.h"
#include "CppUnitTest.h"
#include "StaticExchange.h"
#include <algorithm>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_StaticExchange) {
public:
	TEST_CLASS_INITIALIZE(Call_StaticExchange_init) {
		StaticExchange::init();
	}

	TEST_METHOD(No_Defenders) {
		FOR_PIECE_ALL(piece) {
			AttackPattern attackers;
			attackers.add(piece);

			Assert::AreEqual(0, StaticExchange::attackCost(piece, attackers, AttackPattern()));
		}
	}

	TEST_METHOD(One_Attacker_One_Defender) {
		FOR_PIECE_ALL(defender) {
			AttackPattern defenders;
			defenders.add(defender);

			FOR_PIECE_ALL(attacker) {
				AttackPattern attackers;
				attackers.add(attacker);

				Assert::IsTrue(StaticExchange::attackCost(attacker, attackers, defenders) > 0);
			}
		}
	}

	TEST_METHOD(Defended_Pawn) {
		FOR_PIECE_ALL(piece) {
			AttackPattern attackers, defenders;
			attackers.add(piece);
			defenders.add(piece);

			attackers.add(Piece::PAWN());
			if (StaticExchange::attackCost(Piece::PAWN(), attackers, defenders)) {
				Assert::AreEqual(0, StaticExchange::attackCost(Piece::PAWN(), attackers, defenders));
			}

			Assert::AreEqual(0, StaticExchange::attackCost(Piece::PAWN(), attackers, defenders));
		}
	}

	// attacker will be added to the pattern
	int exchangeValue(char attacker0, std::string pat) {
		Piece attacker = Piece::fromChar(attacker0);

		AttackPattern attackers, defenders;
		attackers.add(attacker);

		for (char c : pat) {
			Piece piece = Piece::fromChar(c);
			Turn turn = Turn::fromChar(c);
			(turn == Turn::WHITE()? attackers : defenders).add(piece);
		}
		return StaticExchange::attackCost(attacker, attackers, defenders);
	}

	TEST_METHOD(SEE_Q_Pr) {
		Assert::AreEqual(4, exchangeValue('Q', "Pr"));
	}

	TEST_METHOD(SEE_P_PQpr) {
		Assert::AreEqual(0, exchangeValue('P', "PQpr"));
	}

	TEST_METHOD(SEE_R_RQnr) {
		Assert::AreEqual(2, exchangeValue('R', "RQnr"));
	}

	TEST_METHOD(SEE_R_Qbp) {
		Assert::AreEqual(5, exchangeValue('R', "Qbp"));
	}

	TEST_METHOD(SEE_P_RQbp) {
		Assert::AreEqual(1, exchangeValue('P', "RQbp"));
	}

	TEST_METHOD(SEE_R_Rqq) {
		Assert::AreEqual(1, exchangeValue('R', "Rqk"));
	}

	TEST_METHOD(SEE_B_Brk) {
		Assert::AreEqual(1, exchangeValue('B', "Brk"));
	}

	TEST_METHOD(SEE_Even_Fight_Over_Pawn) {
		Assert::AreEqual(0, exchangeValue('P', "NRQKnrqk"));
	}

	TEST_METHOD(SEE_Winning_Fight_Over_Pawn) {
		Assert::AreEqual(0, exchangeValue('P', "NRQKnqk"));
	}

	TEST_METHOD(SEE_Losing_Fight_Over_Pawn) {
		Assert::AreEqual(1, exchangeValue('P', "NRKnrqk"));
	}

	TEST_METHOD(SEE_AttackCostMin_Matches_AttackCost) {
		for (int trials = 0; trials < 1000; ++trials) {
			AttackPattern attackers, defenders;
			int nAtk = 1+ rand() % 6, nDef = rand() % 7;
			Piece smallestPiece = Piece::UNKNOWN();
			for (int i = 0; i < nAtk; i++) {
				Piece piece = Piece::random();
				smallestPiece = std::min(smallestPiece, piece);
				attackers.add(piece);
			}
			for (int i = 0; i < nDef; i++) {
				defenders.add(Piece::random());
			}

			Assert::AreEqual(StaticExchange::attackCost(smallestPiece, attackers, defenders),
							 StaticExchange::attackCostMin(attackers, defenders));
		}
	}

	};
}