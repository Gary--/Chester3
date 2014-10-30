#include "stdafx.h"
#include "CppUnitTest.h"
#include "perft.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_Basic_Perft) {
public:
	
	int mirrorLazyPerft(const char* FEN,int depth) {
		int res = Perft::perftLazy(FEN, depth);
		int res2 = Perft::perftLazy(GameConfiguration(FEN).mirror().str().c_str(), depth);
		Assert::IsTrue(res == res2);
		return res;
	}

	TEST_METHOD(King_Move_No_Threats) {
		Assert::AreEqual(8, Perft::perftFull("8/6K1/8/8/8/8/1k6/8 w - - ", 1));
		Assert::AreEqual(64, Perft::perftFull("8/6K1/8/8/8/8/1k6/8 w - - ", 2));
	}

	TEST_METHOD(Knights) {
		Assert::AreEqual(129286, mirrorLazyPerft("8/8/5N2/4n3/3kNK2/5nn1/5N2/8 w - - ", 4));
		//Assert::AreEqual(64, Perft::perftFull("8/6K1/8/8/8/8/1k6/8 w - - ", 2));
	}

	TEST_METHOD(Rooks_Knights) {
		Assert::AreEqual(1285292, mirrorLazyPerft("3R4/3N4/2r3r1/8/4N3/rn2RK1R/7R/3k4 w - - ", 4));
	}

	TEST_METHOD(Rook_Knight_Bishop_0) {
		Assert::AreEqual(53, mirrorLazyPerft("3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -", 1));
		Assert::AreEqual(1265, mirrorLazyPerft("3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -", 2));
		Assert::AreEqual(56902, mirrorLazyPerft("3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -", 3));
		Assert::AreEqual(1537094, mirrorLazyPerft("3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -", 4));
		Assert::AreEqual(70484047, mirrorLazyPerft("3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -", 5));
	}

	TEST_METHOD(Rook_Knight_Bishop_1) {
		Assert::AreEqual(52, mirrorLazyPerft("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 1));
		Assert::AreEqual(2160, mirrorLazyPerft("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 2));
		Assert::AreEqual(91714, mirrorLazyPerft("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 3));
		Assert::AreEqual(3732768, mirrorLazyPerft("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 4));
	}
	TEST_METHOD(TEMP) {
		Assert::AreEqual(3732768, mirrorLazyPerft("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 5));
	}


	TEST_METHOD(Rook_Knight_Bishop_2) {
		Assert::AreEqual(49, mirrorLazyPerft("3k2B1/3r4/R4b2/5N2/3B4/3R4/3K2nr/8 w - -", 1));
		Assert::AreEqual(1354, mirrorLazyPerft("3k2B1/3r4/R4b2/5N2/3B4/3R4/3K2nr/8 w - -", 2));
		Assert::AreEqual(52112, mirrorLazyPerft("3k2B1/3r4/R4b2/5N2/3B4/3R4/3K2nr/8 w - -", 3));
		
	}

	//TEST_METHOD(Rook_Knight_Bishop_3) {
	//	Assert::AreEqual(62, mirrorLazyPerft("3k2B1/3r4/R4b2/5N2/3B4/3R4/3K2nr/8 w - -", 1));
	//	Assert::AreEqual(1120, Perft::perftFull("3k2B1/3r4/R4b2/5N2/3B4/3R4/3K2nr/8 w - -", 2));
	//	//Assert::AreEqual(90279, mirrorLazyPerft("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 3));
	//}

	};


}