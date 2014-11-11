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
	};



}