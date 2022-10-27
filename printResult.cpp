#include <string>
#include <sstream>
#include "Quiz.h"



std::string printResult(int questions, int correct, int wrong) {

	std::stringstream ss;

	ss << "Number of questions: " << questions << std::endl;
	ss << "Number of correct answers: " << correct << std::endl;
	ss << "Number wrong answers: " << wrong << std::endl;
	ss << "Final score: " << Quiz::score << std::endl;

	return ss.str();
}