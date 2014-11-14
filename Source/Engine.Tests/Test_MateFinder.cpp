#include "stdafx.h"
#include "CppUnitTest.h"
#include "MateFinder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_MateFinder) {
public:

	TEST_METHOD(Mate_0) {
		Move move = MateFinder::findMatingMove(GameConfiguration("3q1k1r/4pppp/5P2/5N1N/8/8/8/4RK2 w - -"), 2);
		Assert::AreEqual(Position("f6"), move.getFrom());
		Assert::AreEqual(Position("g7"), move.getTo());
	}

	TEST_METHOD(Mate_1) {
		Move move = MateFinder::findMatingMove(GameConfiguration("1k1r4/pp1b1R2/3q2pp/4p3/2B5/4Q3/PPP2B2/2K5 b - -"), 3);
		Assert::AreEqual(Position("d6"), move.getFrom());
		Assert::AreEqual(Position("d1"), move.getTo());
	}

	

	};



}