#include "attack_fields.h"
#include <cstdint>
#include <vector>
#include "BitBoard.h"
#include "Attack_Fields_init.h"

using namespace std;
namespace {
#pragma region magic
	BitBoard lookup_table[97264];

	struct Magic {
		uint64_t factor;
		BitBoard occupancy;
		uint32_t position;
		
	};

	Magic bishop_magics[64] =
	{
		{ 0x007bfeffbfeffbffull, BitBoard(), 16530 },
		{ 0x003effbfeffbfe08ull, BitBoard(), 9162 },
		{ 0x0000401020200000ull, BitBoard(), 9674 },
		{ 0x0000200810000000ull, BitBoard(), 18532 },
		{ 0x0000110080000000ull, BitBoard(), 19172 },
		{ 0x0000080100800000ull, BitBoard(), 17700 },
		{ 0x0007efe0bfff8000ull, BitBoard(), 5730 },
		{ 0x00000fb0203fff80ull, BitBoard(), 19661 },
		{ 0x00007dff7fdff7fdull, BitBoard(), 17065 },
		{ 0x0000011fdff7efffull, BitBoard(), 12921 },
		{ 0x0000004010202000ull, BitBoard(), 15683 },
		{ 0x0000002008100000ull, BitBoard(), 17764 },
		{ 0x0000001100800000ull, BitBoard(), 19684 },
		{ 0x0000000801008000ull, BitBoard(), 18724 },
		{ 0x000007efe0bfff80ull, BitBoard(), 4108 },
		{ 0x000000080f9fffc0ull, BitBoard(), 12936 },
		{ 0x0000400080808080ull, BitBoard(), 15747 },
		{ 0x0000200040404040ull, BitBoard(), 4066 },
		{ 0x0000400080808080ull, BitBoard(), 14359 },
		{ 0x0000200200801000ull, BitBoard(), 36039 },
		{ 0x0000240080840000ull, BitBoard(), 20457 },
		{ 0x0000080080840080ull, BitBoard(), 43291 },
		{ 0x0000040010410040ull, BitBoard(), 5606 },
		{ 0x0000020008208020ull, BitBoard(), 9497 },
		{ 0x0000804000810100ull, BitBoard(), 15715 },
		{ 0x0000402000408080ull, BitBoard(), 13388 },
		{ 0x0000804000810100ull, BitBoard(), 5986 },
		{ 0x0000404004010200ull, BitBoard(), 11814 },
		{ 0x0000404004010040ull, BitBoard(), 92656 },
		{ 0x0000101000804400ull, BitBoard(), 9529 },
		{ 0x0000080800104100ull, BitBoard(), 18118 },
		{ 0x0000040400082080ull, BitBoard(), 5826 },
		{ 0x0000410040008200ull, BitBoard(), 4620 },
		{ 0x0000208020004100ull, BitBoard(), 12958 },
		{ 0x0000110080040008ull, BitBoard(), 55229 },
		{ 0x0000020080080080ull, BitBoard(), 9892 },
		{ 0x0000404040040100ull, BitBoard(), 33767 },
		{ 0x0000202040008040ull, BitBoard(), 20023 },
		{ 0x0000101010002080ull, BitBoard(), 6515 },
		{ 0x0000080808001040ull, BitBoard(), 6483 },
		{ 0x0000208200400080ull, BitBoard(), 19622 },
		{ 0x0000104100200040ull, BitBoard(), 6274 },
		{ 0x0000208200400080ull, BitBoard(), 18404 },
		{ 0x0000008840200040ull, BitBoard(), 14226 },
		{ 0x0000020040100100ull, BitBoard(), 17990 },
		{ 0x007fff80c0280050ull, BitBoard(), 18920 },
		{ 0x0000202020200040ull, BitBoard(), 13862 },
		{ 0x0000101010100020ull, BitBoard(), 19590 },
		{ 0x0007ffdfc17f8000ull, BitBoard(), 5884 },
		{ 0x0003ffefe0bfc000ull, BitBoard(), 12946 },
		{ 0x0000000820806000ull, BitBoard(), 5570 },
		{ 0x00000003ff004000ull, BitBoard(), 18740 },
		{ 0x0000000100202000ull, BitBoard(), 6242 },
		{ 0x0000004040802000ull, BitBoard(), 12326 },
		{ 0x007ffeffbfeff820ull, BitBoard(), 4156 },
		{ 0x003fff7fdff7fc10ull, BitBoard(), 12876 },
		{ 0x0003ffdfdfc27f80ull, BitBoard(), 17047 },
		{ 0x000003ffefe0bfc0ull, BitBoard(), 17780 },
		{ 0x0000000008208060ull, BitBoard(), 2494 },
		{ 0x0000000003ff0040ull, BitBoard(), 17716 },
		{ 0x0000000001002020ull, BitBoard(), 17067 },
		{ 0x0000000040408020ull, BitBoard(), 9465 },
		{ 0x00007ffeffbfeff9ull, BitBoard(), 16196 },
		{ 0x007ffdff7fdff7fdull, BitBoard(), 6166 }
	};

	Magic rook_magics[64] =
		{
			{ 0x00a801f7fbfeffffull, BitBoard(), 85487 },
			{ 0x00180012000bffffull, BitBoard(), 43101 },
			{ 0x0040080010004004ull, BitBoard(), 0 },
			{ 0x0040040008004002ull, BitBoard(), 49085 },
			{ 0x0040020004004001ull, BitBoard(), 93168 },
			{ 0x0020008020010202ull, BitBoard(), 78956 },
			{ 0x0040004000800100ull, BitBoard(), 60703 },
			{ 0x0810020990202010ull, BitBoard(), 64799 },
			{ 0x000028020a13fffeull, BitBoard(), 30640 },
			{ 0x003fec008104ffffull, BitBoard(), 9256 },
			{ 0x00001800043fffe8ull, BitBoard(), 28647 },
			{ 0x00001800217fffe8ull, BitBoard(), 10404 },
			{ 0x0000200100020020ull, BitBoard(), 63775 },
			{ 0x0000200080010020ull, BitBoard(), 14500 },
			{ 0x0000300043ffff40ull, BitBoard(), 52819 },
			{ 0x000038010843fffdull, BitBoard(), 2048 },
			{ 0x00d00018010bfff8ull, BitBoard(), 52037 },
			{ 0x0009000c000efffcull, BitBoard(), 16435 },
			{ 0x0004000801020008ull, BitBoard(), 29104 },
			{ 0x0002002004002002ull, BitBoard(), 83439 },
			{ 0x0001002002002001ull, BitBoard(), 86842 },
			{ 0x0001001000801040ull, BitBoard(), 27623 },
			{ 0x0000004040008001ull, BitBoard(), 26599 },
			{ 0x0000802000200040ull, BitBoard(), 89583 },
			{ 0x0040200010080010ull, BitBoard(), 7042 },
			{ 0x0000080010040010ull, BitBoard(), 84463 },
			{ 0x0004010008020008ull, BitBoard(), 82415 },
			{ 0x0000020020040020ull, BitBoard(), 95216 },
			{ 0x0000010020020020ull, BitBoard(), 35015 },
			{ 0x0000008020010020ull, BitBoard(), 10790 },
			{ 0x0000008020200040ull, BitBoard(), 53279 },
			{ 0x0000200020004081ull, BitBoard(), 70684 },
			{ 0x0040001000200020ull, BitBoard(), 38640 },
			{ 0x0000080400100010ull, BitBoard(), 32743 },
			{ 0x0004010200080008ull, BitBoard(), 68894 },
			{ 0x0000200200200400ull, BitBoard(), 62751 },
			{ 0x0000200100200200ull, BitBoard(), 41670 },
			{ 0x0000200080200100ull, BitBoard(), 25575 },
			{ 0x0000008000404001ull, BitBoard(), 3042 },
			{ 0x0000802000200040ull, BitBoard(), 36591 },
			{ 0x00ffffb50c001800ull, BitBoard(), 69918 },
			{ 0x007fff98ff7fec00ull, BitBoard(), 9092 },
			{ 0x003ffff919400800ull, BitBoard(), 17401 },
			{ 0x001ffff01fc03000ull, BitBoard(), 40688 },
			{ 0x0000010002002020ull, BitBoard(), 96240 },
			{ 0x0000008001002020ull, BitBoard(), 91632 },
			{ 0x0003fff673ffa802ull, BitBoard(), 32495 },
			{ 0x0001fffe6fff9001ull, BitBoard(), 51133 },
			{ 0x00ffffd800140028ull, BitBoard(), 78319 },
			{ 0x007fffe87ff7ffecull, BitBoard(), 12595 },
			{ 0x003fffd800408028ull, BitBoard(), 5152 },
			{ 0x001ffff111018010ull, BitBoard(), 32110 },
			{ 0x000ffff810280028ull, BitBoard(), 13894 },
			{ 0x0007fffeb7ff7fd8ull, BitBoard(), 2546 },
			{ 0x0003fffc0c480048ull, BitBoard(), 41052 },
			{ 0x0001ffffa2280028ull, BitBoard(), 77676 },
			{ 0x00ffffe4ffdfa3baull, BitBoard(), 73580 },
			{ 0x007ffb7fbfdfeff6ull, BitBoard(), 44947 },
			{ 0x003fffbfdfeff7faull, BitBoard(), 73565 },
			{ 0x001fffeff7fbfc22ull, BitBoard(), 17682 },
			{ 0x000ffffbf7fc2ffeull, BitBoard(), 56607 },
			{ 0x0007fffdfa03ffffull, BitBoard(), 56135 },
			{ 0x0003ffdeff7fbdecull, BitBoard(), 44989 },
			{ 0x0001ffff99ffab2full, BitBoard(), 21479 }
		};
#pragma endregion

		bool coordIsOnGrid(int r, int c) {
			return 0 <= r && r < 8 && 0 <= c && c < 8;
		}
		const int ROOK_SHIFT = 64 - 12;
		const int BISHOP_SHIFT = 64 - 9;
		BitBoard attackableSquares(BitBoard board, int r, int c, Piece piece, bool ignoreLast) {
			BitBoard res = BitBoard::EMPTY();
			for (int dr = -1; dr <= 1; ++dr) {
				for (int dc = -1; dc <= 1; ++dc) {
					bool right = (dr || dc) && !(dr*dc);
					bool diag = dr&&dc;
					if (!((diag&&piece == Piece::BISHOP()) || (right&&piece == Piece::ROOK()))) {
						continue;
					}
					int r2 = r + dr, c2 = c + dc;
					while (coordIsOnGrid(r2, c2)) {
						if (!ignoreLast || coordIsOnGrid(r2 + dr, c2 + dc)) {
							res |= BitBoard(r2, c2);
						}

						if ((BitBoard(r2, c2) & board) != BitBoard::EMPTY()) {
							break;
						}
						r2 += dr;
						c2 += dc;
					}
				}
			}
			return res;
		}


		void initializeBishopRookOccupancy() {
			for (int r = 0; r < 8; ++r) {
				for (int c = 0; c < 8; ++c) {
					int index = Position(r, c).index();
					rook_magics[index].occupancy = attackableSquares(BitBoard::EMPTY(), r, c, Piece::ROOK(), true);
					bishop_magics[index].occupancy = attackableSquares(BitBoard::EMPTY(), r, c, Piece::BISHOP(), true);
				}
			}
		}


		std::vector<BitBoard> allFieldsUsingTheseBits(BitBoard bits) {
			std::vector<BitBoard> res;
			res.push_back(BitBoard::EMPTY());

			FOR_BIT(bit, bits) {

				size_t cursize = res.size();
				for (size_t i = 0; i<cursize; ++i) {
					res.push_back(res[i] | bit);
				}
			}
			return res;
		}

		void initializeBishopRookAttackFields(Piece piece) {
			/*const uint64_t*  magics = (piece == Piece::ROOK()) ? rookMagic : bishopMagic;
			BitBoard** indexes = (piece == Piece::ROOK()) ? rookIndexes : bishopIndexes;
			*/
			for (int loc = 0; loc < 64; ++loc) {
				BitBoard occupancy = (piece == Piece::ROOK() ? rook_magics : bishop_magics)[loc].occupancy;
				std::vector<BitBoard> occPats = allFieldsUsingTheseBits(occupancy);


				for (unsigned i = 0; i < occPats.size(); ++i) {

					BitBoard res = attackableSquares(occPats[i], loc / 8, loc % 8, piece, false);


					uint64_t magic = ((piece == Piece::ROOK()) ? rook_magics : bishop_magics)[loc].factor;
					int position = ((piece == Piece::ROOK()) ? rook_magics : bishop_magics)[loc].position;
					int SHIFT = (piece == Piece::ROOK()) ? ROOK_SHIFT : BISHOP_SHIFT;
					uint64_t ind = position + ((magic*occPats[i].asInt64()) >> SHIFT);

					lookup_table[ind] = res;

				}
			}
		}


}

BitBoard AttackFields::rookTargs(Position position, BitBoard blockers) {
	
	Magic magic = rook_magics[position.index()];
	return lookup_table[magic.position +
		(((magic.occupancy&blockers).asInt64() * magic.factor) >> ROOK_SHIFT)];

}

BitBoard AttackFields::bishopTargs(Position position, BitBoard blockers) {
	Magic magic = bishop_magics[position.index()];
	return lookup_table[magic.position +
		(((magic.occupancy&blockers).asInt64() * magic.factor) >> BISHOP_SHIFT)];
}

BitBoard AttackFields::queenTargs(Position position, BitBoard blockers) {
	return rookTargs(position, blockers) | bishopTargs(position, blockers);
}

void AttackFieldInit::BishopRook() {
	initializeBishopRookOccupancy();
	initializeBishopRookAttackFields(Piece::BISHOP());
	initializeBishopRookAttackFields(Piece::ROOK());
}