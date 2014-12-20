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

	};



}