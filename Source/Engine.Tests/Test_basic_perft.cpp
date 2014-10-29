#include "stdafx.h"
#include "CppUnitTest.h"
#include "perft.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_Basic_Perft) {
public:
	
	TEST_METHOD(King_Move_No_Threats) {
		Assert::AreEqual(8, Perft::perftFull("8/6K1/8/8/8/8/1k6/8 w - - ", 1));
		Assert::AreEqual(64, Perft::perftFull("8/6K1/8/8/8/8/1k6/8 w - - ", 2));
	}

	TEST_METHOD(Knights) {
		Assert::AreEqual(129286, Perft::perftFull("8/8/5N2/4n3/3kNK2/5nn1/5N2/8 w - - ", 4));
		//Assert::AreEqual(64, Perft::perftFull("8/6K1/8/8/8/8/1k6/8 w - - ", 2));
	}

	};


}