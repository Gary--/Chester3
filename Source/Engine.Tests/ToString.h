#pragma once

#include "stdafx.h"
#include "CppUnitTest.h"
#include "BitBoard.h"


#define RETURN_WSTRING(x) std::wstring _s; std::string s(x.str()); _s.assign(s.begin(),s.end());  return _s;
#define define_specialization(type) template<>static std::wstring ToString<type>(const type& x) {RETURN_WSTRING(x);}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			define_specialization(BitBoard);
			define_specialization(Position);
			
		}
	}
}