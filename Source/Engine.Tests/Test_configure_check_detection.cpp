#include "stdafx.h"
#include "CppUnitTest.h"
#include "Move.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_Configure_Check_Detect) {
public:
	TEST_CLASS_INITIALIZE(Call_Game_Init) {
		Game::init();
	}

	};


}