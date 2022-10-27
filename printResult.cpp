#include <string>
#include <sstream>
#include "Quiz.h"



std::string printResult(int questions, int correct, int wrong) {

	std::stringstream ss;

	ss << "Number of questions: " << questions << std::endl;
	ss << "Number correct answers: " << correct << std::endl;
	ss << "Number wrong answers: " << wrong << std::endl;
	ss << "Final score: " << Quiz::score;

	return ss.str();
}
