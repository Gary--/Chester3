#include "EvaluationScore.h"
#include "Evaluation.h"
#include "SimpleEvaluation.h"
#include "Game.h"

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
whiteMisc(0),
blackMisc(0),
relativeMate(0),
_isValid(false)
{}

EvaluationScore::EvaluationScore(bool _) : EvaluationScore()
{
	_isValid = true;
	check = Game::getCheck();
	whiteSimple = SimpleEvaluation::all(Turn::WHITE());
	blackSimple = SimpleEvaluation::all(Turn::BLACK());

	relativeMate = Evaluation::mating(Turn::WHITE());
	lateness = Evaluation::lateness();

	if (relativeMate == 0) {
		relativeMobility = Evaluation::mobility();
		relativeMaterial = Evaluation::materialBalance();
		whiteKingDanger = Evaluation::kingDanger(Turn::WHITE());
		blackKingDanger = Evaluation::kingDanger(Turn::BLACK());
		relativeCenter = Evaluation::center();
		whitePawns = Evaluation::pawns(Turn::WHITE());
		blackPawns = Evaluation::pawns(Turn::BLACK());
		whiteMisc = Evaluation::misc(Turn::WHITE());
		blackMisc = Evaluation::misc(Turn::BLACK());
	}

}

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
		getRelativeMate(perspective) +
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

int EvaluationScore::getRelativeSimple(Turn turn) const {
	return turn.isWhite() ? (whiteSimple - blackSimple) : (blackSimple - whiteSimple);
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

bool EvaluationScore::getCheck() const {
	return check;
}

int EvaluationScore::getRelativeMate(Turn perspective) const {
	return perspective.isWhite() ? relativeMate : -relativeMobility;
}

