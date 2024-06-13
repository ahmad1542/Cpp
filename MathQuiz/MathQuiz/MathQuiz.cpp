#include <iostream>
#include <Windows.h>
using namespace std;

enum enQuestionLevel { easy = 1, medium = 2, hard = 3 };

enum enOperationType { add = 1, sub = 2, multi = 3, div = 4, mix = 5 };

enum enRoundResult {correct = 1, unCorrect = 2};

struct stQuiz {

};

int randomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int readNumber(string message) {
	int number;
	cout << message;
	cin >> number;

	return number;
}

int readQuesNumber() {
	return readNumber("How many questions do you want to answer ? ");
}

int readQuestionLevel() {
	return readNumber("Enter questions level [1] Easy, [2] Medium, [3] Hard, [4] Mix ? ");
}

int readOperatorType() {
	return readNumber("Enter operation type [1] Add, [2] Sub, [3] Multiply, [4] Divison, [5] Mix ? ");
}

enQuestionLevel mixQuestions() {
	int mixedOp = randomNumber(1, 4);
	switch (mixedOp) {
	case 1:
		return enQuestionLevel::easy;
	case 2:
		return enQuestionLevel::medium;
	default:
		return enQuestionLevel::hard;
	}
}

enQuestionLevel questionLevel() {
	int quesNumber = readQuestionLevel();
	if (quesNumber == 1) {
		return enQuestionLevel::easy;
	}
	else if (quesNumber == 2) {
		return enQuestionLevel::medium;
	}
	else if (quesNumber == 3) {
		return enQuestionLevel::hard;
	}
	else
		return mixQuestions();

}

enOperationType mixOperators() {
	int mixedOp = randomNumber(1, 4);
	switch (mixedOp) {
	case 1:
		return enOperationType::add;
	case 2:
		return enOperationType::sub;
	case 3:
		return enOperationType::multi;
	default:
		return enOperationType::div;
	}
}

enOperationType operationType(int opNumber) {
	if (opNumber == 1) {
		return enOperationType::add;
	}
	else if (opNumber == 2) {
		return enOperationType::sub;
	}
	else if (opNumber == 3) {
		return enOperationType::multi;
	}
	else if (opNumber == 4) {
		return enOperationType::div;
	}
	else
		return mixOperators();
	
}

int easyLevel() {
	return randomNumber(1, 10);
}

int mediumLevel() {
	return randomNumber(10, 50);
}

int hardLevel() {
	return randomNumber(50, 150);
}

int choosedLevel() {
	int choosedLevel = readQuestionLevel();
	switch (choosedLevel) {
	case 1:
		return easyLevel();
	case 2:
		return mediumLevel();
	default:
		return hardLevel();
	}
}

int calculation(int num1, int num2, enOperationType choosedOperator) {
	switch (choosedOperator) {
	case enOperationType::add:
		return num1 + num2;
	case enOperationType::sub:
		return num1 - num2;
	case enOperationType::multi:
		return num1 * num2;
	default:
		return num1 / num2;;
	}
}

string choosedOperator(enOperationType choosedOperator) {
	switch (choosedOperator) {
	case add:
		return " + ";
	case sub:
		return " - ";
	case multi:
		return " * ";
	default:
		return " / ";
	}
}

enRoundResult calcCheck(int userAnswer, int answer) {
	if (userAnswer == answer)
		return enRoundResult::correct;
	else
		return enRoundResult::unCorrect;
}

void question() {
	int num1, num2, userAnswer;
	int opNumber = readOperatorType();
	enOperationType choosedOp;
	int length = readQuesNumber();
	for (int i = 0; i < length; i++) {
		if (choosedOp == enOperationType::mix)
			choosedOp = operationType(opNumber);
		num1 = choosedLevel();
		num2 = choosedLevel();
		int answer = calculation(num1, num2, choosedOp);
		questionPrint(i + 1, length);
		cout << num1 << choosedOperator(choosedOp) << num2 <<  endl;
		cout << "__________" << endl;
		userAnswer = readNumber("");
		if (calcCheck(userAnswer, answer) == enRoundResult::correct) {
			system("color 20");
			cout << "Right Answer :-)" << endl << endl;
		}
		else {
			system("color 40");
			cout << "\a";
			cout << "Wrong Answer :-(" << endl << "The right answer is : " << answer << endl << endl;
		}
	}
}


void questionPrint(int quesNumber, int quesLength) {
	cout << "Question [" << quesNumber << "/" << quesLength << "]" << endl << endl;
}

int main() {
	srand((unsigned)time(NULL));
}