/*
*	Project 2 by Michael Steiger
* 
*	This program asks the user questions and the user has to provide an answer.
*	If the user enter the correct answer the score will increase by 1, if not 
*	decrease by 1.
* 
* 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>        
#include <cstdlib> 
#include "Quiz.h"
#include "printResult.h"

using namespace std;

int main(int argc,  char* argv[]) {


	ifstream readFile;
	string question;
	string answer;
	string printFinal;
	string readQandA[100];
	vector <Quiz> quizVector;
	int count = 0;
	int questions;
	int numCorrect = 0;
	int numWrong = 0;
	

	readFile.open(argv[1]); // change to argv[1] when submitting "database.txt"

	if (readFile.is_open()) {

		getline(readFile, question);  //get the first line of the file and parse the first 3 slots; 
		question = question.substr(3, question.size());
		getline(readFile, answer);
		answer = answer.substr(3, answer.size());
		readQandA[count] = question;
		readQandA[count + 1] = answer;
		count += 2;
		while (!readFile.eof()) {
			getline(readFile, question); 
			question = question.substr(3, question.size());
			getline(readFile, answer);
			answer = answer.substr(3, answer.size());
			readQandA[count] = question;
			readQandA[count + 1] = answer;
			count += 2;
		}
	}
	readFile.close();

	// adding all q and a's and pushing them into vectors 
	for (int i = 0; i < count; i += 2) {
		Quiz q(readQandA[i], readQandA[i+1]);
		quizVector.push_back(q);
	}

	// time for shuffeling
	srand(unsigned(time(0)));
	random_shuffle(quizVector.begin(), quizVector.end());
	// shuffeling works

	//calculate how many questions there are by getting the size of the vector
	questions = quizVector.size();

	// ask user the quiz questions
	
	for (auto & quizVector : quizVector) {

		cout << quizVector.getQuestion() << endl;
		// ask questions
		cout << "Type in your answer: ";
		getline(cin, answer);
		if (answer == quizVector.getAnswer()) {
			numCorrect++;
			quizVector.updateScore(1);
			cout << "Correct!" << endl;
			cout << "Current Score: " << quizVector.getScore() << endl;
		}
		else {
			numWrong++;
			quizVector.updateScore(-1);
			cout << "Wrong! Correct answer: " << quizVector.getAnswer() << endl;
			cout << "Current Score: " << quizVector.getScore() << endl;
		}
		cout << endl;
	}

	printFinal = printResult(questions, numCorrect, numWrong);

	cout << printFinal << endl;
	
	return 0;
}
