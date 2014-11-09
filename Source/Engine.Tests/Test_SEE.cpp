#include "stdafx.h"
#include "CppUnitTest.h"
#include "static_exchange.h"
#include <algorithm>
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

	TEST_METHOD(Defended_Pawn) {
		FOR_PIECE_ALL(piece) {
			AtkPat attackers, defenders;
			attackers.add(piece);
			defenders.add(piece);

			attackers.add(Piece::PAWN);
			if (SEE::attackCost(Piece::PAWN, attackers, defenders)) {
				Assert::AreEqual(0, SEE::attackCost(Piece::PAWN, attackers, defenders));
			}

			Assert::AreEqual(0, SEE::attackCost(Piece::PAWN, attackers, defenders));
		}
	}

	// attacker will be added to the pattern
	int exchangeValue(char attacker0, std::string pat) {
		Piece attacker = ChessUtils::pieceFromChar(attacker0);

		AtkPat attackers, defenders;
		attackers.add(attacker);

		for (char c : pat) {
			Piece piece = ChessUtils::pieceFromChar(c);
			Turn turn = Turn::fromChar(c);
			(turn == Turn::WHITE()? attackers : defenders).add(piece);
		}
		return SEE::attackCost(attacker, attackers, defenders);
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
			AtkPat attackers, defenders;
			int nAtk = 1+ rand() % 6, nDef = rand() % 7;
			Piece smallestPiece = Piece::UNKNOWN;
			for (int i = 0; i < nAtk; i++) {
				Piece piece = randPiece();
				smallestPiece = std::min(smallestPiece, piece);
				attackers.add(piece);
			}
			for (int i = 0; i < nDef; i++) {
				defenders.add(randPiece());
			}

			Assert::AreEqual(SEE::attackCost(smallestPiece, attackers, defenders),
							 SEE::attackCostMin(attackers, defenders));
		}
	}

	};
}