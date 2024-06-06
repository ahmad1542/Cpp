#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enRPSGame {rock = 1, paper = 2, scissors = 3};

enum enResult {won, lost, draw};

int readNumber(string message) {
    int number;

    cout << message;
    cin >> number;

    return number;
}

int randNum(int from, int to) {
    return rand() % (to - from + 1) + from;;
}

int rounds() {
    int number = readNumber("How many round 1 to 10? ");
    return number;
}

enResult gameAlgorithm(int playerChoice, int computerChoice) {
    if (playerChoice == paper && computerChoice == rock)
        return won;
    else if (playerChoice == rock && computerChoice == scissors)
        return won;
    else if (playerChoice == paper && computerChoice == scissors)
        return lost;
    else if (playerChoice == scissors && computerChoice == rock)
        return lost;
    else if (computerChoice == paper && playerChoice == rock)
        return lost;
    else if (computerChoice == rock && playerChoice == scissors)
        return lost;
    else if (computerChoice == paper && playerChoice == scissors)
        return won;
    else if (computerChoice == scissors && playerChoice == rock)
        return won;
    else
        return draw;
}

string roundResult(int playerChoice, int computerChoice) {
    enResult result = gameAlgorithm(playerChoice, computerChoice);
    if (result == enResult::won)
        return "[Player1]";
    else if (result == enResult::lost)
        return "[Computer]";
    else
        return "[No Winner]";
}

void roundsPrint(int roundsNumber) {

    for (int i = 0; i < roundsNumber; i++) {
        
        cout << "Round [" << i + 1 << "] begins: " << endl;
        int playerChoice = readNumber("Your Choice: [1]:Rock, [2]:Paper, [3]:Scissors ? ");
        int computerChoice = randNum(1, 3);
        cout << "___________Round [" << i + 1 << "]___________" << endl;
        cout << "Player1 Choice: " << playerChoice << endl;
        cout << "Computer Choice: " << computerChoice << endl;
        cout << "Round Winner  : " << roundResult(playerChoice, computerChoice) << endl;
        cout << "_______________________________" << endl;
    }
}

void gameStart() {
    int roundsNum = rounds();
    roundsPrint(roundsNum);
}

int main() {
    srand((unsigned)time(NULL));
    gameStart();

    return 0;
}