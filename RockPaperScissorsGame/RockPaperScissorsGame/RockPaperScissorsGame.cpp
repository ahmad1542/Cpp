#include <iostream>
#include <string>
#include <stdlib.h>
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

void gameOver(int playerCounter, int computerCounter, int drawCounter) {

    cout << endl << endl << "________________________________________________________________________\n\t\t\t\tGameOver\n________________________________________________________________________" << endl << endl;
    cout << "\t\t\t    Player Wins = " << playerCounter << endl << "\t\t\t    Computer Wins = " << computerCounter << endl << "\t\t\t    Draws = "  << drawCounter << endl << endl << "________________________________________________________________________";
}

void roundsPrint(int roundsNumber) {
    int playerChoice, computerChoice;
    int playerCounter = 0, computerCounter = 0, drawCounter = 0;

    for (int i = 0; i < roundsNumber; i++) {
        
        cout << "Round [" << i + 1 << "] begins: " << endl;
        playerChoice = readNumber("Your Choice: [1]:Rock, [2]:Paper, [3]:Scissors ? ");
        computerChoice = randNum(1, 3);
        cout << "___________Round [" << i + 1 << "]___________" << endl;
        cout << "Player1 Choice: " << playerChoice << endl;
        cout << "Computer Choice: " << computerChoice << endl;
        cout << "Round Winner  : " << roundResult(playerChoice, computerChoice) << endl;
        cout << "_______________________________" << endl;
        if (roundResult(playerChoice, computerChoice) == "[Player1]")
            playerCounter++;
        else if (roundResult(playerChoice, computerChoice) == "[Computer]")
            computerCounter++;
        else
            drawCounter++;
    }
    gameOver(playerCounter, computerCounter, drawCounter);
}

void gameStart() {
    int roundsNum = rounds();
    roundsPrint(roundsNum);
}

void gameRestart() {
    char replay;
    cout << "\n\n\nDo you want to replay? [Yes]: Y/y, [No]: N/n :  ";
    cin >> replay;

    if (replay == 'Y' || replay == 'y') {
        system("CLS");
        gameStart();
    }
}



int main() {
    srand((unsigned)time(NULL));
    gameStart();
    gameRestart();

    return 0;
}