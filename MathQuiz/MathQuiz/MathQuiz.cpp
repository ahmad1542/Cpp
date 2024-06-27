#include <iostream>
#include <Windows.h>
using namespace std;

enum enQuestionLevel { easy = 1, medium = 2, hard = 3 };
enum enOperationType { add = 1, subtract = 2, multiply = 3, divide = 4, mix = 5 };
enum enRoundResult { correct = 1, incorrect = 2 };

int fnRandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int fnReadNumber(string message) {
    int number;
    cout << message;
    cin >> number;
    return number;
}

int fnReadQuesNumber() {
    return fnReadNumber("How many questions do you want to answer? ");
}

int fnReadQuestionLevel() {
    return fnReadNumber("Enter questions level [1] Easy, [2] Medium, [3] Hard, [4] Mix? ");
}

int fnReadOperatorType() {
    return fnReadNumber("Enter operation type [1] Add, [2] Subtract, [3] Multiply, [4] Divide, [5] Mix? ");
}

enQuestionLevel fnMixQuestions() {
    int mixedOp = fnRandomNumber(1, 3);
    switch (mixedOp) {
    case 1:
        return enQuestionLevel::easy;
    case 2:
        return enQuestionLevel::medium;
    default:
        return enQuestionLevel::hard;
    }
}

enQuestionLevel fnQuestionLevel() {
    int quesNumber = fnReadQuestionLevel();
    switch (quesNumber) {
    case 1:
        return enQuestionLevel::easy;
    case 2:
        return enQuestionLevel::medium;
    case 3:
        return enQuestionLevel::hard;
    default:
        return fnMixQuestions();
    }
}

enOperationType fnMixOperators() {
    int mixedOp = fnRandomNumber(1, 4);
    switch (mixedOp) {
    case 1:
        return enOperationType::add;
    case 2:
        return enOperationType::subtract;
    case 3:
        return enOperationType::multiply;
    default:
        return enOperationType::divide;
    }
}

enOperationType fnOperationType(int opNumber) {
    switch (opNumber) {
    case 1:
        return enOperationType::add;
    case 2:
        return enOperationType::subtract;
    case 3:
        return enOperationType::multiply;
    case 4:
        return enOperationType::divide;
    default:
        return fnMixOperators();
    }
}

int fnEasyLevel() {
    return fnRandomNumber(1, 10);
}

int fnMediumLevel() {
    return fnRandomNumber(10, 50);
}

int fnHardLevel() {
    return fnRandomNumber(50, 150);
}

int fnChoosedLevel(int choosedLevel) {
    switch (choosedLevel) {
    case 1:
        return fnEasyLevel();
    case 2:
        return fnMediumLevel();
    default:
        return fnHardLevel();
    }
}

int fnCalculation(int num1, int num2, enOperationType choosedOperator) {
    switch (choosedOperator) {
    case enOperationType::add:
        return num1 + num2;
    case enOperationType::subtract:
        return num1 - num2;
    case enOperationType::multiply:
        return num1 * num2;
    default:
        return num1 / num2;
    }
}

string fnChoosedOperator(enOperationType choosedOperator) {
    switch (choosedOperator) {
    case add:
        return " + ";
    case subtract:
        return " - ";
    case multiply:
        return " * ";
    default:
        return " / ";
    }
}

enRoundResult fnCalcCheck(int userAnswer, int answer, enOperationType choosedOp) {
    return (userAnswer == answer) ? enRoundResult::correct : enRoundResult::incorrect;
}

string fnQuizResult(int wins, int loses) {
    if (wins > loses) {
        system("color 20");
        return "Pass :-)";
    }
    else {
        system("color 40");
        return "Fail :-(";
    }
}

string fnQuestionsLevelConvert(int choosedLevel) {
    switch (choosedLevel) {
    case 1:
        return "Easy";
    case 2:
        return "Medium";
    case 3:
        return "Hard";
    default:
        return "Mix";
    }
}

string fnOperationTypeConvert(int choosedOp) {
    switch (choosedOp) {
    case 1:
        return "Addition";
    case 2:
        return "Subtraction";
    case 3:
        return "Multiplication";
    case 4:
        return "Division";
    default:
        return "Mix";
    }
}

void fnFinalResult(int wins, int loses, string finalResult, int quesNum, string choosedLevel, string opType) {
    cout << "__________________________________" << endl << "Final Result Is " << finalResult << endl << "__________________________________" << endl << endl;
    cout << "Number of questions: " << quesNum << endl;
    cout << "Questions level: " << choosedLevel << endl;
    cout << "Operation type: " << opType << endl;
    cout << "Number of right answers: " << wins << endl;
    cout << "Number of wrong answers: " << loses << endl << endl;
    cout << "__________________________________" << endl << endl;
}

void fnQuestionPrint(int quesNumber, int quesLength) {
    cout << "Question [" << quesNumber << "/" << quesLength << "]" << endl << endl;
}

void fnQuestion() {
    int num1, num2, userAnswer, winsCounter = 0, loseCounter = 0;
    int length = fnReadQuesNumber();
    int iChoosedLevel = fnReadQuestionLevel();
    int opNumber = fnReadOperatorType();
    enOperationType choosedOp;

    for (int i = 0; i < length; i++) {
        choosedOp = (opNumber == enOperationType::mix) ? fnMixOperators() : fnOperationType(opNumber);

        num1 = fnChoosedLevel(iChoosedLevel);
        num2 = fnChoosedLevel(iChoosedLevel);
        int answer = fnCalculation(num1, num2, choosedOp);
        fnQuestionPrint(i + 1, length);
        cout << num1 << fnChoosedOperator(choosedOp) << num2 << endl;
        cout << "__________" << endl;
        userAnswer = fnReadNumber("");
        if (fnCalcCheck(userAnswer, answer, choosedOp) == enRoundResult::correct) {
            system("color 20");
            cout << "Right Answer :-)" << endl << endl;
            winsCounter++;
        }
        else {
            system("color 40");
            cout << "\a";
            cout << "Wrong Answer :-(" << endl << "The right answer is : " << answer << endl << endl;
            loseCounter++;
        }
    }

    string finalResult = fnQuizResult(winsCounter, loseCounter);
    string sChoosedLevel = fnQuestionsLevelConvert(iChoosedLevel);
    string opType = fnOperationTypeConvert(opNumber);
    fnFinalResult(winsCounter, loseCounter, finalResult, length, sChoosedLevel, opType);
}

void fnRestartGame(string& playAgain) {
    cout << "Do you want to play again? Y/N: ";
    cin >> playAgain;
}

void fnGameStart() {
    string playAgain;
    do
    {
        system("color 07");//change color to black
        system("CLS");
        fnQuestion();
        fnRestartGame(playAgain);
    } while (playAgain == "Y" || playAgain == "y");
}

int main() {
    srand((unsigned)time(NULL));
    fnGameStart();
}