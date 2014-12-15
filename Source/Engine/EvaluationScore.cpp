#include "EvaluationScore.h"
#include "Evaluation.h"
#include "SimpleEvaluation.h"


EvaluationScore::EvaluationScore() :
lateness(INVALID_SCORE),
whiteSimple(INVALID_SCORE),
blackSimple(INVALID_SCORE),
relativeMobility(INVALID_SCORE),
relativeMaterial(INVALID_SCORE),
whiteKingDanger(INVALID_SCORE),
blackKingDanger(INVALID_SCORE),
relativeCenter(INVALID_SCORE),
whitePawns(INVALID_SCORE),
blackPawns(INVALID_SCORE),
whiteMisc(0),
blackMisc(0),
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
	whiteMisc(Evaluation::misc(Turn::WHITE())),
	blackMisc(Evaluation::misc(Turn::BLACK())),
	_isValid(true)
{}

EvaluationScore EvaluationScore::GetFromGameState() {
	return EvaluationScore(true);
}

EvaluationScore EvaluationScore::GetInvalid() {
	return EvaluationScore();
}

bool EvaluationScore::isValid() const {
	return _isValid;
}

int EvaluationScore::getOverall(Turn perspective) const {
	return
		getRelativeMaterial(perspective) +
		-getKingDanger(perspective) + getKingDanger(!perspective) +
		getRelativeCenter(perspective) +
		getRelativeMobility(perspective) +
		getPawns(perspective) - getPawns(!perspective) +
		getMisc(perspective) - getMisc(!perspective);
}

double EvaluationScore::getLateness() const {
	return lateness;
}

int EvaluationScore::getSimple(Turn turn) const {
	return turn.isWhite() ? whiteSimple : blackSimple;
}

int EvaluationScore::getRelativeMaterial(Turn perspective) const {
	return perspective.isWhite() ? relativeMaterial : -relativeMaterial;
}

int EvaluationScore::getKingDanger(Turn turn) const {
	return turn.isWhite() ? whiteKingDanger : blackKingDanger;
}

int EvaluationScore::getRelativeCenter(Turn perspective) const {
	return perspective.isWhite() ? relativeCenter : -relativeCenter;
}

int EvaluationScore::getRelativeMobility(Turn perspective) const {
	return perspective.isWhite() ? relativeMobility : -relativeMobility;
}

int EvaluationScore::getPawns(Turn turn) const {
	return turn.isWhite() ? whitePawns : blackPawns;
}

int EvaluationScore::getMisc(Turn turn) const {
	return turn.isWhite() ? whiteMisc : blackMisc;
}

