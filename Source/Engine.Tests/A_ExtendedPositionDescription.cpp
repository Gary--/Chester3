#include "stdafx.h"
#include "CppUnitTest.h"
#include "ExtendedPositionDescription.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace EngineTests {
	TEST_CLASS(A_ExtendedPositionDescription) {
public:

	TEST_METHOD(FEN_is_preserved) {
		string epdString = "r1bq1r1k/p1pnbpp1/1p2p3/6p1/3PB3/5N2/PPPQ1PPP/2KR3R w - - bm g4;";
		ExtendedPositionDescription epd(epdString);

		Assert::AreEqual(string("r1bq1r1k/p1pnbpp1/1p2p3/6p1/3PB3/5N2/PPPQ1PPP/2KR3R w - -"), epd.getGameConfiguration().str_min());
	}

	TEST_METHOD(Best_Move_Extraction) {
		string epdString = "1k1r4/pp1b1R2/3q2pp/4p3/2B5/4Q3/PPP2B2/2K5 b - - bm Qd1+; id \"BK.01\";";
		ExtendedPositionDescription epd(epdString);

		Assert::AreEqual(1, (int)epd.bestMoves.size());
		Assert::AreEqual(epd.gameConf.getMoveEpdString("Qd1+"), epd.bestMoves[0]);
	}

	};



}