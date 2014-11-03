#pragma once

#include "stdafx.h"
#include "CppUnitTest.h"
#include "BitBoard.h"
#include "GameConfiguration.h"
#include "Game.h"

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

			template<>static std::wstring ToString<Turn>(const Turn& turn) { 
				std::wstring res;
				std::string value;

				value = turn == Turn::WHITE ? "WHITE" : "BLACK";
				res.assign(value.begin(), value.end());
				return res;
			}

			template<>static std::wstring ToString<Piece>(const Piece& piece) {
				std::wstring res;
				std::string value;

				switch (piece) {
				case Piece::EMPTY:
					value = "Empty";
					break;
				case Piece::PAWN:
					value = "Pawn";
					break;
				case Piece::KNIGHT:
					value = "Knight";
					break;
				case Piece::BISHOP:
					value = "Bishop";
					break;
				case Piece::ROOK:
					value = "Rook";
					break;
				case Piece::QUEEN:
					value = "Queen";
					break;
				case Piece::KING:
					value = "King";
					break;
				}
				res.assign(value.begin(), value.end());
				return res;
			}

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