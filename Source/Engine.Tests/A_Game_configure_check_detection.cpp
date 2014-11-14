#include "stdafx.h"
#include "CppUnitTest.h"
#include "Move.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace EngineTests {
	TEST_CLASS(A_Game_configure_check_detection) {
public:
	TEST_CLASS_INITIALIZE(Call_Game_Init) {
		Game::init();
	}

	TEST_METHOD(Initial_Board) {
		Game::configure(GameConfiguration("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -"));
		Assert::IsFalse(Game::getCheck());
	}

	TEST_METHOD(Knight_Check) {
		Game::configure(GameConfiguration("rnbqkbnr/pppp1ppp/5N2/4p3/8/8/PPPPPPPP/RNBQKB1R b - -"));
		Assert::IsTrue(Game::getCheck());
	}

	TEST_METHOD(Pawn_Check) {
		Game::configure(GameConfiguration("rnbqkbnr/pppppPpp/8/6p1/8/8/PPPPP1PP/RNBQKBNR b - -"));
		Assert::IsTrue(Game::getCheck());
		Game::makeMove(Move(MoveType::REGULAR, Position("e8"), Position("f7"), Piece::KING(), Piece::PAWN()));
		Assert::IsFalse(Game::getCheck());
		Game::undoMove();
		Assert::IsTrue(Game::getCheck());
	}

	TEST_METHOD(Bishop_Check) {
		Game::configure(GameConfiguration("rnbqk1nr/ppppp2p/6p1/6p1/3P3b/8/PPPPP1PP/RNBQKBNR w - -"));
		Assert::IsTrue(Game::getCheck());

		Game::makeMove(Move(MoveType::REGULAR, Position("g2"), Position("g3"), Piece::PAWN(), Piece::EMPTY()));
		Assert::IsFalse(Game::getCheck());
		Game::undoMove();
		Assert::IsTrue(Game::getCheck());
	}

	TEST_METHOD(Rook_Check) {
		Game::configure(GameConfiguration("rnbqkbnr/pppp1ppp/8/1p6/6PN/4R3/PPPPPP1P/RNBQKB2 b - -"));
		Assert::IsTrue(Game::getCheck());

		Game::makeMove(Move(MoveType::REGULAR, Position("g8"), Position("e7"), Piece::KNIGHT(), Piece::EMPTY()));
		Assert::IsFalse(Game::getCheck());
		Game::undoMove();
		Assert::IsTrue(Game::getCheck());
	}

	TEST_METHOD(Queen_Check1) {
		Game::configure(GameConfiguration("rnbqk1nr/ppppp2p/6p1/6p1/3P3q/8/PPPPP1PP/RNBQKBNR w - -"));
		Assert::IsTrue(Game::getCheck());

		Game::makeMove(Move(MoveType::REGULAR, Position("g2"), Position("g3"), Piece::PAWN(), Piece::EMPTY()));
		Assert::IsFalse(Game::getCheck());
		Game::undoMove();
		Assert::IsTrue(Game::getCheck());
	}

	TEST_METHOD(Queen_Check2) {
		Game::configure(GameConfiguration("rnbqkbnr/pppp1ppp/8/1p6/6PN/4Q3/PPPPPP1P/RNBQKB2 b - -"));
		Assert::IsTrue(Game::getCheck());

		Game::makeMove(Move(MoveType::REGULAR,Position("f8"),Position( "e7"),Piece::BISHOP(),Piece::EMPTY()));
		Assert::IsFalse(Game::getCheck());

		Game::undoMove();
		Assert::IsTrue(Game::getCheck());



	}


	
	};


}