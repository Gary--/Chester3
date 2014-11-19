#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Evaluation.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation_Center) {
public:
	void confSync(GameConfiguration conf) {
		Game::configure(conf);
		Evaluation::synchronize();

	}

	TEST_METHOD(InitialPosition) {
		confSync(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));

		FOR_BIT(bit, BitBoard::rowsLessThan(3)) {
			Assert::AreEqual('b', Evaluation::DEBUG_control(bit.ToPosition()));
		}

		FOR_BIT(bit, BitBoard::rowsGreaterThan(4)) {
			Assert::AreEqual('w', Evaluation::DEBUG_control(bit.ToPosition()));
		}

		FOR_BIT(bit, BitBoard::rowBits(3) | BitBoard::rowBits(4)) {
			Assert::AreEqual('?', Evaluation::DEBUG_control(bit.ToPosition()));
		}

	}

	TEST_METHOD(Hard_0) {
		confSync(GameConfiguration("8/3k3B/1p6/2ppQ3/2q2nb1/3Pr1N1/3KPP2/8 w - -"));

		Assert::AreEqual(0, Evaluation::center());//less than 4 pawns on both sides
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("d6")));
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("h7")));
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("f1")));
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("h1")));
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("f2")));
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("f3")));
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("d6")));
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("c7")));
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("b8")));
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("e2")));
		Assert::AreEqual('w', Evaluation::DEBUG_control(Position("e2")));

		Assert::AreEqual('b', Evaluation::DEBUG_control(Position("d7")));
		Assert::AreEqual('b', Evaluation::DEBUG_control(Position("d8")));
		Assert::AreEqual('b', Evaluation::DEBUG_control(Position("d4")));
		Assert::AreEqual('b', Evaluation::DEBUG_control(Position("h3")));
		Assert::AreEqual('b', Evaluation::DEBUG_control(Position("b6")));
		Assert::AreEqual('b', Evaluation::DEBUG_control(Position("c5")));
		Assert::AreEqual('b', Evaluation::DEBUG_control(Position("d5")));
		Assert::AreEqual('b', Evaluation::DEBUG_control(Position("a2")));
		Assert::AreEqual('b', Evaluation::DEBUG_control(Position("c4")));

		Assert::AreEqual('?', Evaluation::DEBUG_control(Position("e4")));
		Assert::AreEqual('?', Evaluation::DEBUG_control(Position("a8")));
		Assert::AreEqual('?', Evaluation::DEBUG_control(Position("h5")));
		Assert::AreEqual('?', Evaluation::DEBUG_control(Position("a7")));
		Assert::AreEqual('?', Evaluation::DEBUG_control(Position("g1")));
		Assert::AreEqual('?', Evaluation::DEBUG_control(Position("h4")));
	}
	
	TEST_METHOD(Opening_Is_Good) {
		confSync(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/2N2N2/PPPPPPPP/R1BQKB1R w - -"));
		Assert::IsTrue(Evaluation::center() > 0);

		confSync(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/PPPPPPPP/RNBQKBNR/8 w - -"));
		Assert::IsTrue(Evaluation::center() > 0);
	}

	};
}

