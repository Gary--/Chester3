#include "EvaluationManager.h"
#include "Evaluation.h"
#include <vector>
#include "SimpleEvaluation.h"
using namespace std;
namespace {
	vector<EvaluationScore> scores(1, EvaluationScore::GetInvalid());
}

void EvaluationManager::synchronize() {
	Evaluation::synchronize();
	scores = vector<EvaluationScore>(1, EvaluationScore::GetInvalid());
}

void EvaluationManager::notifyMove(Move move, Turn turn) {
	Evaluation::notifyMove(move, turn);
	SimpleEvaluation::notifyMove(move, turn);
	scores.push_back(EvaluationScore::GetInvalid());
}

void EvaluationManager::notifyUndoMove(Move move, Turn turn) {
	Evaluation::notifyUndoMove(move, turn);
	SimpleEvaluation::notifyUndoMove(move, turn);
	scores.pop_back();
}

EvaluationScore EvaluationManager::getScore(int n) {
	if (n == 0) {
		calcScoreCurrent();
	}
	_ASSERTE(n < scores.size());
	return scores.at(scores.size() - 1 - n);
}

EvaluationScore EvaluationManager::getScore() {
	return getScore(0);
}

void EvaluationManager::calcScoreCurrent() {
	if (!scores.back().isValid()) {
		scores.back() = EvaluationScore::GetFromGameState();
	}
}

int EvaluationManager::getRelativeSimpleScore(Turn turn) {
	return SimpleEvaluation::all(turn) - SimpleEvaluation::all(!turn);
}
