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
	}

	TEST_METHOD(Rooks_Knights) {
#ifdef NDEBUG
		Assert::AreEqual(1285292, mirrorLazyPerft("3R4/3N4/2r3r1/8/4N3/rn2RK1R/7R/3k4 w - - ", 4));
#endif
	}

	TEST_METHOD(Rook_Knight_Bishop_0) {
		Assert::AreEqual(53, mirrorLazyPerft("3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -", 1));
		Assert::AreEqual(1265, mirrorLazyPerft("3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -", 2));
		Assert::AreEqual(56902, mirrorLazyPerft("3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -", 3));

#ifdef NDEBUG
		Assert::AreEqual(1537094, mirrorLazyPerft("3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -", 4));
		Assert::AreEqual(70484047, mirrorLazyPerft("3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -", 5));
#endif
	}

	TEST_METHOD(Rook_Knight_Bishop_1) {
		Assert::AreEqual(52, mirrorLazyPerft("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 1));
		Assert::AreEqual(2160, mirrorLazyPerft("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 2));
		Assert::AreEqual(91714, mirrorLazyPerft("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 3));

#ifdef NDEBUG
		Assert::AreEqual(3732768, mirrorLazyPerft("3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -", 4));
#endif
	}


	TEST_METHOD(Rook_Knight_Bishop_2) {
		Assert::AreEqual(49, mirrorLazyPerft("3k2B1/3r4/R4b2/5N2/3B4/3R4/3K2nr/8 w - -", 1));
		Assert::AreEqual(1354, mirrorLazyPerft("3k2B1/3r4/R4b2/5N2/3B4/3R4/3K2nr/8 w - -", 2));
		Assert::AreEqual(52112, mirrorLazyPerft("3k2B1/3r4/R4b2/5N2/3B4/3R4/3K2nr/8 w - -", 3));
		
	}

	TEST_METHOD(All_Normal_Pieces_0) {
		Assert::AreEqual(42, mirrorLazyPerft("8/8/3k1N2/3r3n/r7/4BK2/Q6R/5bq1 w - -", 1));
		Assert::AreEqual(1759, mirrorLazyPerft("8/8/3k1N2/3r3n/r7/4BK2/Q6R/5bq1 w - -", 2));
		Assert::AreEqual(56875, mirrorLazyPerft("8/8/3k1N2/3r3n/r7/4BK2/Q6R/5bq1 w - -", 3));
#ifdef NDEBUG
		Assert::AreEqual(2276681, mirrorLazyPerft("8/8/3k1N2/3r3n/r7/4BK2/Q6R/5bq1 w - -", 4));
#endif
	}


	TEST_METHOD(All_Normal_Pieces_1) {
		Assert::AreEqual(31, mirrorLazyPerft("8/2N1k3/K3N1Q1/BR5n/rq2r3/6N1/2n5/5b2 w - -", 1));
		Assert::AreEqual(1001, mirrorLazyPerft("8/2N1k3/K3N1Q1/BR5n/rq2r3/6N1/2n5/5b2 w - -", 2));
		Assert::AreEqual(31678, mirrorLazyPerft("8/2N1k3/K3N1Q1/BR5n/rq2r3/6N1/2n5/5b2 w - -", 3));
#ifdef NDEBUG
		Assert::AreEqual(1077778, mirrorLazyPerft("8/2N1k3/K3N1Q1/BR5n/rq2r3/6N1/2n5/5b2 w - -", 4));
#endif
	}

	};


}