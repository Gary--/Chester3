#include "MoveResolver.h"
#include "Game.h"

using namespace std;

Move MoveResolver::resolveUCI(string uciString) {
	for (Move move : Game::getAllMoves()) {
		if (move.str() == uciString) {
			return move;
		}
	}
	return Move::INVALID();
}


//<sanMove>        :: = <PieceCode>[<Disambiguation>] <targetSquare>[<promotion>]['+' | '#']
//| <castles>
//<castles>        :: = 'O-O' | 'O-O-O' (upper case O, not zero)
//< PieceCode >    :: = '' | 'N' | 'B' | 'R' | 'Q' | 'K'
//<Disambiguation> :: = <fileLetter> | <digit18>
//<targetSquare>   :: = <fileLetter> <digit18>
//<fileLetter>     :: = 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h'
//<promotion>      :: = '=' <PiecePromotion>
//<PiecePromotion> :: = 'N' | 'B' | 'R' | 'Q'

//<digit18>        :: = '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8'
//<digit19>        :: = '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
//<digit>          :: = '0' | <digit19>

Move MoveResolver::resolveEPD(string s) {
	{
		string ns;
		for (char c : s) {
			if (string("x+#").find(c) == string::npos) {
				ns += c;
			}
		}
		s = ns;
	}


	if (s.size() < 2) {
		return Move::INVALID();
	}

	Piece promo = Piece::fromChar(s.back());
	if (promo != Piece::INVALID()) {
		s = s.substr(0, s.size() - 2);
	}

	if (s.size() < 2) {
		return Move::INVALID();
	}
	 
	Piece piece = Piece::fromChar(s[0]);
	if (piece == Piece::INVALID()) {
		piece = Piece::PAWN();
	} else {
		s = s.substr(1);
	}



	if (s.size() < 2) {
		return Move::INVALID();
	}

	Position to(s.substr(s.size() - 2));
	s = s.substr(0, s.size() - 2);

	int row = -1, col = -1;
	for (char c : s) {
		if ('a' <= c && c <= 'h') {
			col = c - 'a';
		}

		if ('1' <= c && c<= '8') {
			row = '8' - c;
		}
	}

	int numMatching = 0;
	Move result = Move::INVALID();
	for (Move move : Game::getAllMoves()) {
		if (move.getPiece()==piece &&
			move.getTo()==to &&
			(!move.isPromotion() || move.promotionPiece()==promo) &&
			(row == -1 || move.getFrom().row() == row) &&
			(col == -1 || move.getFrom().col() == col) ){
			result = move;
			numMatching++;
		}
	}
	if (numMatching > 1) {
		return Move::INVALID();
	}

	return result;
}
