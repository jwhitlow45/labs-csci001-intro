//Jacob Whitlow
//03-31-19
//Dice game where rolling seven or eleven three times is a win. Snake-eyes twice is an automatic loss.
//Bets can be placed and a score is kept. Winning gets you double your bet back.

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>

using namespace std;


struct rollConditions {

	int sevens, elevens, snakeEyes;

};


//function prototypes
int dieRoll(), getBet(), calculateScore(bool ,int);
bool isWin(rollConditions), playAgain();
void printResults(bool, rollConditions);
rollConditions checkResults(int results[]);


int main() {
	
	//seeds random number generation
	srand(time(NULL));

	//array of die rolls
	int rolls[10];

	bool win, again;
	int bet, score = 0;

	cout << "DICE ROLL GAME\n";
	cout << "==============\n";

	cout << "Win twice your bet if you roll three sevens or three elevens!\n";
	cout << "Rolling snake-eyes is an automatic loss.\n\n";

	do {

		cout << endl << "Enter your bet!: $";

		bet = getBet();


		for (int i = 0; i < 10; i++) {

			rolls[i] = dieRoll();

		}

		rollConditions conditions = checkResults(rolls);						//determines how many times each condition was rolled

		win = isWin(conditions);												//determines whether or not the user has won or lost

		printResults(win, conditions);											//tells the user whether they have won or lost

		score = score + calculateScore(win, bet);								//calculates score based on win/loss

		cout << "\n\nYou have $" << score << endl;

		cout << "Would you like to play again? (y/n): ";

		again = playAgain();

	} while (again);
			
	return 0;

}



////////////////////getBet()
//----------stores bet obtained from user
int getBet() {

	string bet;
	bool valid;


	do {

		valid = true;
		getline(cin, bet);

		if (bet == "") {

			valid = false;

		}

		for (int i = 0; i < bet.size(); i++) {

			if (!isdigit(bet[i])) {

				valid = false;

			}

		}

		if (!valid) {

			cout << "Please enter an amount in dollars: $";

		}

	} while (!valid);

	return stoi(bet);

}



////////////////////dieRoll()
//----------rolls a theoretical pair of dice
int dieRoll() {

	return (rand() % 6 + 1) + (rand() % 6 + 1);

}



////////////////////checkResults()
//----------checks result
rollConditions checkResults(int results[]) {

	rollConditions conditions = { 0,0,0 };

	for (int i = 0; i < 10; i++) {

		if (results[i] == 7) {

			conditions.sevens++;

		}
		else if (results[i] == 11) {

			conditions.elevens++;

		}
		else if (results[i] == 2) {

			conditions.snakeEyes++;

		}

	}

	return conditions;

}



////////////////////isWin()
//----------checks if the user has won the game
bool isWin(rollConditions conditions) {

	if (conditions.snakeEyes >= 2) {

		return false;

	}
	else if (conditions.sevens >= 3) {

		return true;

	}
	else if (conditions.elevens >= 3) {

		return true;

	}
	else {

		return false;

	}

}



////////////////////printResults()
//----------prints the results of the game to the user
void printResults(bool win, rollConditions conditions) {

	if (win) {

		cout << "You won!\n";

	}
	else {

		cout << "You lost!\n";

	}

	cout << "Times 7 was rolled: " << conditions.sevens;
	cout << "\nTimes 11 was rolled: " << conditions.elevens;
	cout << "\nTimes Snake-Eyes were rolled: " << conditions.snakeEyes;

}



////////////////////calculateScore()
//----------calculates score based on win/loss and user's bet
int calculateScore(bool win, int bet) {

	if (win) {

		return bet*2;

	}
	else {

		return -1 * bet;

	}
	
}



////////////////////playAgain()
//----------prompts the user to play again
bool playAgain() {

	bool valid;
	string input;

	do {

		valid = true;
		getline(cin, input);

		if (input == "") {

			valid = false;

		}


		for (int i = 0; i < input.size(); i++) {

			input[i] = tolower(input[i]);

		}


		if (input == "yes" || input == "y") {

			return true;

		}
		else if (input == "no" || input == "n") {

			return false;

		}
		else {

			valid = false;
			cout << "Please enter yes or no: ";

		}

	} while (!valid);

}