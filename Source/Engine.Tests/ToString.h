#pragma once

#include "stdafx.h"
#include "CppUnitTest.h"
#include "BitBoard.h"
#include "GameConfiguration.h"
#include "Game.h"
#include "AttackPattern.h"
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
			define_specialization(GameConfiguration);
			define_specialization(Piece);
			define_specialization(Turn);
			define_specialization(AttackPattern);
			
			

			template<>static std::wstring ToString<Side>(const Side& side) {
				std::wstring res;
				std::string value;

				value = side == Side::LEFT ? "Left" : "Right";
				res.assign(value.begin(), value.end());
				return res;
			}

	
		}
	}
}