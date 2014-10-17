#include "stdafx.h"
#include "CppUnitTest.h"
#include "BitBoard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests
{
	TEST_CLASS(BitBoard_Position)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			BitBoard x(8);
			BitBoard y(4);
			BitBoard z(12);
			Assert::AreEqual(z, x | y);
		}

	};
}