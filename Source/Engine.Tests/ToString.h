#pragma once

#include "stdafx.h"
#include "CppUnitTest.h"
#include "BitBoard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<>
			static std::wstring ToString<BitBoard>(const BitBoard  & coord) {
				return L"Some string representing coordinate.";
			}
		}
	}
}