#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cin; using std::cout; using std::endl; using std::string;

string currentPlayer(int currentTurn, string pl1, string pl2);

string upOrDown(int changeInSpace);

int main() {
	srand(time(nullptr));
	int spaceOne = 1;
	int spaceTwo = 1;
	bool gameover = false;
	int turn = 1;
	string response = "";
	int move;
	int changeSpace = 0;
	int tempSpace = 0;
	int unmodifiedTempSpace = 0;
	string playerOneName;
	string playerTwoName;
	cout << "SNAKES AND LADDERS\n";
	cout << "      by Joel     \n\n";
	cout << "Two players will take turns rolling the\n";
	cout << "dice to get to space 100. You may encounter\n";
	cout << "ladders which take you up to a higher position\n";
	cout << "if you land on them or snakes that drop you\n";
	cout << "down to a lower position.\n\n";
	cout << "Enter name for player 1: ";
	cin >> playerOneName;
	cout << "Enter name for player 2: ";
	cin >> playerTwoName;
	cout << endl;
	system("cls");
	do {

		cout << currentPlayer(turn, playerOneName, playerTwoName) << "'s turn. Press enter to roll dice. ";
		//cin >> response;
		cin.ignore();
		move = (rand() % 11) + 2;

		cout << "You rolled " << move << "." << endl;
		//put moved space into tempspace variable so it can be modified
		if (turn == 1) {
			spaceOne += move;
			tempSpace = spaceOne;
			//keeps a variable that can be compared later
			unmodifiedTempSpace = tempSpace;
		}
		else if (turn == 2) {
			spaceTwo += move;
			tempSpace = spaceTwo;
			//keeps a variable that can be compared later
			unmodifiedTempSpace = tempSpace;
		}
		if (tempSpace == 100) {
			cout << currentPlayer(turn, playerOneName, playerTwoName) << " wins!!!" << endl << endl;
			gameover = true;
			break;
		}

		//does not allow player to move above space 100
		if (tempSpace > 100) {

			cout << "You rolled too high. You will stay on your current space." << endl;


			//put value back into tempspace
			if (turn == 1) {
				tempSpace = spaceOne;
				spaceOne -= move;
			}
			else if (turn == 2) {
				tempSpace = spaceTwo;
				spaceTwo -= move;
			}

			//subtract the most recent move that brought value over 100
			tempSpace -= move;

			cout << currentPlayer(turn, playerOneName, playerTwoName) << " is on space " << tempSpace << "." << endl << endl;


			//switch player and skip rest of loop if rolled over 100
			if (turn == 1)
				turn = 2;
			else if (turn == 2)
				turn = 1;
			//ignore rest of block and start next iteration
			continue;
		}

		//move either up or down if landed on a snake or ladder
		switch (tempSpace) {
			//ladders move up to a higher space
		case 8:
			tempSpace = 26;
			break;
		case 21:
			tempSpace = 82;
			break;
		case 50:
			tempSpace = 91;
			break;
		case 43:
			tempSpace = 77;
			break;
		case 62:
			tempSpace = 96;
			break;
		case 66:
			tempSpace = 87;
			break;
		case 54:
			tempSpace = 93;
			break;
			//snakes, moves down to a lower space

		case 98:
			tempSpace = 28;
			break;
		case 95:
			tempSpace = 24;
			break;
		case 92:
			tempSpace = 51;
			break;
		case 83:
			tempSpace = 19;
			break;
		case 73:
			tempSpace = 1;
			break;
		case 69:
			tempSpace = 9;
			break;
		case 64:
			tempSpace = 36;
			break;
		case 59:
			tempSpace = 17;
			break;
		case 44:
			tempSpace = 22;
			break;
		case 46:
			tempSpace = 5;
			break;
		case 48:
			tempSpace = 9;
			break;
		case 55:
			tempSpace = 7;
			break;
		case 52:
			tempSpace = 11;
			break;
		case 99:
			tempSpace = 78;
			break;
		case 33:
			tempSpace = 12;
			break;
		case 86:
			tempSpace = 56;
			break;
		}


		//displays message based on how player was moved
		if (unmodifiedTempSpace > tempSpace) {
			cout << "Oops! " << currentPlayer(turn, playerOneName, playerTwoName) << " landed on a snake! " << endl;
			changeSpace = -1;
			//changespace determines which message will be shown on new space
		}
		else if (unmodifiedTempSpace < tempSpace) {
			cout << "Way to go! " << currentPlayer(turn, playerOneName, playerTwoName) << " landed on a ladder! " << endl;
			changeSpace = 1;
			//changespace determines which message will be shown on new space
		}
		else
			changeSpace = 0;

		//switches to other player's turn
		if (turn == 1) {
			
			spaceOne = tempSpace;
			cout << currentPlayer(turn, playerOneName, playerTwoName) << " " << upOrDown(changeSpace) << " space " << spaceOne << "." << endl;
			cout << "You have " << 100 - spaceOne << " spaces to go." << endl << endl;
			turn = 2;
		}
		else if (turn == 2) {
			
			spaceTwo = tempSpace;
			cout << currentPlayer(turn, playerOneName, playerTwoName) << " " << upOrDown(changeSpace) << " space " << spaceTwo <<  "." << endl;
			cout << "You have " << 100 - spaceTwo << " spaces to go." << endl <<endl;
			turn = 1;
		}
		
		
	} while (gameover == false);
	system("pause");
}
//converts the number of current player to a string
string currentPlayer(int currentTurn, string pl1, string pl2) {
	if (currentTurn == 1) {
		return pl1;
	}
	else if (currentTurn == 2) {
		return pl2;
	}
} 

//creates text based on space change
string upOrDown(int changeInSpace) {
	switch (changeInSpace) {
	case 0:
		return "is now on";
		break;
	case 1:
		return "moved up to";
		break;
	case -1:
		return "slid down to";
		break;
	}
}
