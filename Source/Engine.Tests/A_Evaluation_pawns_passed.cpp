#include "stdafx.h"
#include "CppUnitTest.h"
#include "Evaluation_test_helpers.h"
#include "Evaluation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Evaluation_pawns_passed) {
public:
	BitBoard getPassedPawns(GameConfiguration conf) {
		confSync(conf);
		return Evaluation::DEBUG_passedPawns(Turn::WHITE());
	}
	BitBoard getPassedPawns(const char* FEN) {
		return getPassedPawns(GameConfiguration(FEN));
	}


	TEST_METHOD(No_passed_pawns_initially) {
		Assert::AreEqual(BitBoard::EMPTY(), getPassedPawns(GameConfiguration::INITIAL));
	}

	TEST_METHOD(All_pawns_passed) {
		Assert::AreEqual(BitBoard::rowBits(6), getPassedPawns("rnbqkbnr/8/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -"));
	}

	TEST_METHOD(Single_passed_0) {
		Assert::AreEqual(Position("a2").asSingletonBitboard(), getPassedPawns("rnbqkbnr/2pppppp/2p5/2p5/8/8/PPPPPPPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Single_passed_1) {
		Assert::AreEqual(Position("d5").asSingletonBitboard(), getPassedPawns("rnbqkbnr/pp3ppp/6p1/2pPp3/8/8/PPP1PPPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(Single_passed_2) {
		Assert::AreEqual(Position("d5").asSingletonBitboard(), getPassedPawns("rnbqkbnr/pp4pp/6p1/2pPp3/2PpP3/8/PP3PPP/RNBQKBNR w - -"));
	}

	TEST_METHOD(No_passed_0) {
		Assert::AreEqual(BitBoard::EMPTY(), getPassedPawns("rnbqkbnr/p2p2p1/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
		Assert::AreEqual(BitBoard::EMPTY(), getPassedPawns("rnbqkbnr/1p2p2p/8/8/8/8/PPPPPPPP/RNBQKBNR w - -"));
	}

	

	};


}