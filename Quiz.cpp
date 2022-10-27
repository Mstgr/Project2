#include "Quiz.h"
#include <string>

Quiz::Quiz(std::string q, std::string a) {

	question = q;
	answer = a;
}

std::string Quiz::getQuestion() {
	return question;
}

std::string Quiz::getAnswer() {
	return answer;
}

int Quiz::getScore() {
	return score;
}

int Quiz::score = 0;

void Quiz::updateScore(int v) {

	if (v == -1) {

		if (score == 0) {
			// do nothing because we are already at 0 
		}
		else {
			score--;
		}
	}
	else {
		score++;
	}

}
