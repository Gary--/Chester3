#include "stdafx.h"
#include "CppUnitTest.h"
#include "Move.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(Test_Move) {
public:
	TEST_CLASS_INITIALIZE(Call_Game_Init) {
		Game::init();
	}


	};


}