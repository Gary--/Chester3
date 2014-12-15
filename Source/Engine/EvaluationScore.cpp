#include "EvaluationScore.h"
#include "Evaluation.h"
#include "SimpleEvaluation.h"
EvaluationScore::EvaluationScore() :
lateness(0),
whiteSimple(0),
blackSimple(0),
relativeMobility(0),
relativeMaterial(0),
whiteKingDanger(0),
blackKingDanger(0),
relativeCenter(0),
whitePawns(0),
blackPawns(0),
_isValid(false)
{}

EvaluationScore::EvaluationScore(bool _) :
	lateness(Evaluation::lateness()),
	whiteSimple(SimpleEvaluation::all(Turn::WHITE())),
	blackSimple(SimpleEvaluation::all(Turn::BLACK())),
	relativeMobility(Evaluation::mobility()),
	relativeMaterial(Evaluation::materialBalance()),
	whiteKingDanger(Evaluation::kingDanger(Turn::WHITE())),
	blackKingDanger(Evaluation::kingDanger(Turn::BLACK())),
	relativeCenter(Evaluation::center()),
	whitePawns(Evaluation::pawns(Turn::WHITE())),
	blackPawns(Evaluation::pawns(Turn::BLACK())),
	_isValid(true)
{}

