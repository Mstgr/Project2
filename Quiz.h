
#include <string>

class Quiz {

private: 
	std::string question = { "" };
	std::string answer = { "" };
	static int score;

public:

	// constructors
	Quiz() = default;
	Quiz(std::string, std::string);

	// methods
	std::string getQuestion();
	std::string getAnswer();
	static int getScore();
	void static updateScore(int);

	friend std::string printResult(int, int, int);
};