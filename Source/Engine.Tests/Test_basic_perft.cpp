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
		const char* FEN = "8/6K1/8/8/8/8/1k6/8 w - - ";
		Assert::AreEqual(8, Perft::perftFull(FEN, 1));
		Assert::AreEqual(64, Perft::perftFull(FEN, 2));
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
		const char* FEN = "3k2B1/8/R4b2/R6b/3B3r/3R4/3K1b1r/5R2 w - -";
		Assert::AreEqual(53, mirrorLazyPerft(FEN, 1));
		Assert::AreEqual(1265, mirrorLazyPerft(FEN, 2));
		Assert::AreEqual(56902, mirrorLazyPerft(FEN, 3));

#ifdef NDEBUG
		Assert::AreEqual(1537094, mirrorLazyPerft(FEN, 4));
		Assert::AreEqual(70484047, mirrorLazyPerft(FEN, 5));
#endif
	}

	TEST_METHOD(Rook_Knight_Bishop_1) {
		const char* FEN = "3kN1B1/3r4/R1n2b2/4N3/3B3r/n2R4/3K1b1r/5R2 w - -";
		Assert::AreEqual(52, mirrorLazyPerft(FEN, 1));
		Assert::AreEqual(2160, mirrorLazyPerft(FEN, 2));
		Assert::AreEqual(91714, mirrorLazyPerft(FEN, 3));

#ifdef NDEBUG
		Assert::AreEqual(3732768, mirrorLazyPerft(FEN, 4));
#endif
	}


	TEST_METHOD(Rook_Knight_Bishop_2) {
		const char* FEN = "3k2B1/3r4/R4b2/5N2/3B4/3R4/3K2nr/8 w - -";
		Assert::AreEqual(49, mirrorLazyPerft(FEN, 1));
		Assert::AreEqual(1354, mirrorLazyPerft(FEN, 2));
		Assert::AreEqual(52112, mirrorLazyPerft(FEN, 3));
		
	}

	TEST_METHOD(All_Normal_Pieces_0) {
		const char* FEN = "8/8/3k1N2/3r3n/r7/4BK2/Q6R/5bq1 w - -";

		Assert::AreEqual(42, mirrorLazyPerft(FEN, 1));
		Assert::AreEqual(1759, mirrorLazyPerft(FEN, 2));
		Assert::AreEqual(56875, mirrorLazyPerft(FEN, 3));
#ifdef NDEBUG
		Assert::AreEqual(2276681, mirrorLazyPerft(FEN, 4));
#endif
	}


	TEST_METHOD(All_Normal_Pieces_1) {
		const char* FEN = "8/2N1k3/K3N1Q1/BR5n/rq2r3/6N1/2n5/5b2 w - -";

		Assert::AreEqual(31, mirrorLazyPerft(FEN, 1));
		Assert::AreEqual(1001, mirrorLazyPerft(FEN, 2));
		Assert::AreEqual(31678, mirrorLazyPerft(FEN, 3));
#ifdef NDEBUG
		Assert::AreEqual(1077778, mirrorLazyPerft(FEN, 4));
#endif
	}

	TEST_METHOD(Castling_0) {
		const char* FEN = "r3k2r/8/8/3nq3/4QN2/8/8/R3K2R w KQkq -";

		Assert::AreEqual(37, mirrorLazyPerft(FEN, 1));
		Assert::AreEqual(1214, mirrorLazyPerft(FEN, 2));
		Assert::AreEqual(43544, mirrorLazyPerft(FEN, 3));

#ifdef NDEBUG
		Assert::AreEqual(1552652, mirrorLazyPerft(FEN, 4));
#endif
	}

	TEST_METHOD(Castling_1) {
		const char* FEN = "2k5/2q5/8/8/8/2n1n3/8/R3K2R w KQ -";
		Assert::AreEqual(21, mirrorLazyPerft(FEN, 1));
		Assert::AreEqual(741, mirrorLazyPerft(FEN, 2));
		Assert::AreEqual(15743, mirrorLazyPerft(FEN, 3));

#ifdef NDEBUG
		Assert::AreEqual(542414, mirrorLazyPerft(FEN, 4));
#endif
	}

	
	TEST_METHOD(Pawns_1) {
		const char* FEN = "4k1q1/3b4/2P1P3/3K4/8/8/8/8 w - -";
		Assert::AreEqual(8, mirrorLazyPerft(FEN, 1));
		Assert::AreEqual(129, mirrorLazyPerft(FEN, 2));
		Assert::AreEqual(1048, mirrorLazyPerft(FEN, 3));
	}


	TEST_METHOD(Massive_Promotions) {
		const char* FEN = "n1n5/PPPk4/8/8/8/8/4Kppp/5N1N w - -";
		Assert::AreEqual(24, mirrorLazyPerft(FEN, 1));
		Assert::AreEqual(496, mirrorLazyPerft(FEN, 2));
		Assert::AreEqual(9483, mirrorLazyPerft(FEN, 3));
#ifdef NDEBUG
		Assert::AreEqual(182838, mirrorLazyPerft(FEN, 4));
		Assert::AreEqual(3605103, mirrorLazyPerft(FEN, 5));
#endif
	}

	TEST_METHOD(Big_0) {
		const char* FEN = "n3q3/P3P3/2q2nk1/1P2p2q/1K1pPBN1/4r1QP/3N3p/r7 w - -";
		Assert::AreEqual(1418, mirrorLazyPerft(FEN, 2));
		Assert::AreEqual(35005, mirrorLazyPerft(FEN, 3));
#ifdef NDEBUG
		Assert::AreEqual(2020530, mirrorLazyPerft(FEN, 4));
		Assert::AreEqual(53162401, mirrorLazyPerft(FEN, 5));
#endif 
	}

	TEST_METHOD(Big_1) {
		const char* FEN = "2q2q2/2P2P2/p1K2RBB/1P1n2bb/b2kN3/7p/5r1p/8 w - -";
		Assert::AreEqual(21968, mirrorLazyPerft(FEN, 3));
#ifdef NDEBUG
		Assert::AreEqual(1185806, mirrorLazyPerft(FEN, 4));
		Assert::AreEqual(24482460, mirrorLazyPerft(FEN, 5));
#endif 
	}

	
	};


}