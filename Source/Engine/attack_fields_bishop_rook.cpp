#include "Attack_Fields_init.h"
#include "attack_fields.h"
#include <cstdint>
#include <vector>






namespace {
	const uint64_t rookMagic[64] = { 36029347045851136ULL, 4629700485660811264ULL, 36037730559332353ULL, 36037593380553856ULL, 612511539689170560ULL, 72061992755659008ULL, 36030996050608384ULL, 36029076191846528ULL, 140739640033824ULL, 9640521442009088ULL, 576742364735881232ULL, 703721809907712ULL, 563018807386624ULL, 140746078552192ULL, 2306124488485634560ULL, 4611967495555907840ULL, 35734136307712ULL, 9408019896456970944ULL, 36451559508287496ULL, 36284034715648ULL, 142386823043072ULL, 288371663966307328ULL, 4611690418656514053ULL, 9223374235945173057ULL, 9241386995857506336ULL, 9007337768485440ULL, 4755836393023865472ULL, 571748194975872ULL, 10378545377790919680ULL, 2326568751988864ULL, 281547992334340ULL, 2537681426858113ULL, 144185567565841504ULL, 864832140863348752ULL, 4503737074716800ULL, 36609341314308096ULL, 4613379268490037248ULL, 422229653324288ULL, 2305933173529251848ULL, 554084335684ULL, 425236132823040ULL, 85568530363203584ULL, 9223653787246329872ULL, 9439553683798163488ULL, 9224498005615378688ULL, 4398147207296ULL, 3602916054533406728ULL, 18044086405693476ULL, 9223407770986872960ULL, 72235168387105024ULL, 9007474401607744ULL, 17594334052480ULL, 2260596175470848ULL, 7061784961796538496ULL, 72341440641958912ULL, 828995834368ULL, 18693845173537ULL, 281544237253249ULL, 70446062018570ULL, 2533309687271425ULL, 2918895577746114562ULL, 281483709513729ULL, 9223653520421520389ULL, 154891518082ULL };
	const uint64_t bishopMagic[64] = { 9009484194128384ULL, 10385306289822664768ULL, 2252366757757504ULL, 1154051821887553536ULL, 1130435392307200ULL, 82754760381300736ULL, 7319737206833152ULL, 1143775829434406ULL, 334268732015108ULL, 288247972666311172ULL, 2269409183809792ULL, 4415234769408ULL, 3368328103936ULL, 283682858598400ULL, 144040337089024ULL, 288373316967075840ULL, 2252079120843808ULL, 844562503434368ULL, 2254016021266442ULL, 2251817564512264ULL, 14636700980477952ULL, 281475783590916ULL, 1688852144130048ULL, 1407383490330944ULL, 2314859279507538944ULL, 4630265570477998594ULL, 1143492260694032ULL, 563499843485699ULL, 281543713013768ULL, 4616190855022151688ULL, 285874667422720ULL, 325388440350789120ULL, 11529813266294517760ULL, 37299970573076480ULL, 70677991260194ULL, 2201171263616ULL, 5913190714573840ULL, 45037684195886144ULL, 290501970395957248ULL, 1129207302209616ULL, 5067992861786124ULL, 36314674882429952ULL, 18085042676830217ULL, 4611686301904668672ULL, 8800392217600ULL, 4508032168886304ULL, 288810926914666624ULL, 2310347712698008609ULL, 282033595088960ULL, 282608869326848ULL, 1513210576465072193ULL, 594486146474967040ULL, 68753162248ULL, 144185574134153216ULL, 1134799400210432ULL, 1153502085569347584ULL, 36592039103629312ULL, 288444783075270656ULL, 9196148736ULL, 8592066560ULL, 69793382912ULL, 28185854464ULL, 1196303145058368ULL, 1127016732590336ULL };


	BitBoard rookOccupancy[64];
	int rookShift[64] = { 0 };

	const int numRookOccupancyPatterns = 1 << 12;
	BitBoard rookAttackField[64][numRookOccupancyPatterns];

	BitBoard bishopOccupancy[64];
	int bishopShift[64] = { 0 };
	const int numBishopOccupancyPatterns = 1 << 10;
	BitBoard bishopAttackField[64][numBishopOccupancyPatterns];

	bool coordIsOnGrid(int r, int c) {
		return 0 <= r && r < 8 && 0 <= c && c < 8;
	}

	BitBoard attackableSquares(BitBoard board, int r, int c, Piece piece, bool ignoreLast) {
		BitBoard res = BitBoard::EMPTY;
		for (int dr = -1; dr <= 1; ++dr) {
			for (int dc = -1; dc <= 1; ++dc) {
				bool right = (dr || dc) && !(dr*dc);
				bool diag = dr&&dc;
				if (!((diag&&piece == Piece::BISHOP) || (right&&piece == Piece::ROOK))) {
					continue;
				}
				int r2 = r + dr, c2 = c + dc;
				while (coordIsOnGrid(r2, c2)) {
					if (!ignoreLast || coordIsOnGrid(r2 + dr, c2 + dc)) {
						res |= BitBoard(r2, c2);
					}

					if ((BitBoard(r2,c2) & board)!=BitBoard::EMPTY) {
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
				rookOccupancy[index] = attackableSquares(BitBoard::EMPTY, r, c, Piece::ROOK, true);
				rookShift[index] = 64 - rookOccupancy[index].count();

				bishopOccupancy[index] = attackableSquares(BitBoard::EMPTY, r, c, Piece::BISHOP, true);
				bishopShift[index] = 64 - bishopOccupancy[index].count();
			}
		}
	}


	std::vector<BitBoard> allFieldsUsingTheseBits(BitBoard bits) {
		std::vector<BitBoard> res;
		res.push_back(BitBoard::EMPTY);

		FOR_BIT(bit,bits){

			size_t cursize = res.size();
			for (size_t i = 0; i<cursize; ++i) {
				res.push_back(res[i] | bit);
			}
		}
		return res;
	}

	void initializeBishopRookAttackFields(Piece piece) {
		int* shifts = (piece == Piece::ROOK) ? rookShift : bishopShift;
		BitBoard* occupancies = (piece == Piece::ROOK) ? rookOccupancy : bishopOccupancy;
		const uint64_t*  magics = (piece == Piece::ROOK) ? rookMagic : bishopMagic;


		for (int loc = 0; loc < 64; ++loc) {
			std::vector<BitBoard> occPats = allFieldsUsingTheseBits(occupancies[loc]);

			for (unsigned i = 0; i < occPats.size(); ++i) {
				BitBoard res = attackableSquares(occPats[i], loc / 8, loc % 8, piece, false);
				uint64_t ind = (magics[loc] * occPats[i].AsInt64()) >> shifts[loc];
				if (piece == Piece::ROOK) {
					rookAttackField[loc][ind] = res;
				} else {
					bishopAttackField[loc][ind] = res;
				}
			}
		}
	}
}

BitBoard AttackFields::bishopTargs(Position position, BitBoard blockers) {
	int index = position.index();
	return bishopAttackField[index]
		[((bishopOccupancy[index] & blockers).AsInt64()*bishopMagic[index])
		>> bishopShift[index]];
}

BitBoard AttackFields::rookTargs(Position position, BitBoard blockers) {
	int index = position.index();
	return rookAttackField[index]
		[((rookOccupancy[index] & blockers).AsInt64()*rookMagic[index])
		>> rookShift[index]];
}

BitBoard AttackFields::queenTargs(Position position, BitBoard blockers) {
	return bishopTargs(position, blockers) | rookTargs(position, blockers);
}



void AttackFieldInit::BishopRook() {
		initializeBishopRookOccupancy();
	
		initializeBishopRookAttackFields(Piece::BISHOP);
		initializeBishopRookAttackFields(Piece::ROOK);
}


