//Jacob Whitlow
//02-20-19
//Randomly rolls two dice and outputs them to the user. Can be ran again from within the program or ended.

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;


//function prototypes
int dieRoll(void);
bool rollAgain();
void checkDoubles(int, int);


int main() {

	cout << "DICE ROLLER\n";
	cout << "===========";

	int roll1, roll2;														//Integers for storing die rolls
	bool repeat;															//Bool for determining if dice should be rolled again

	srand(time(NULL));														//Seed for dice roll

	do {

		roll1 = dieRoll();													//Generates first die roll
		roll2 = dieRoll();													//Generates second die roll
		
		cout << "\nThe dice rolled " << roll1 << " and " << roll2 << ".\n";	//Outputs dice roll to user

		checkDoubles(roll1, roll2);											//Checks if doubles were rolled

		cout << "Roll again? (yes/no): ";									//Prompts user for another roll
		
		repeat = rollAgain();												//Accepts user input and returns true, false, or prompts
																			//again based on user input.
	} while (repeat);														//Repeats loop if rollAgain() returned true

	return 0;

}



//////////////////////dieRoll()
//----------Generates seed for random number, applies modulus operator to random number giving 
//number from 0-5 and adds 1, giving 1-6
int dieRoll(void) {

	int die;

	die = rand() % 6 + 1;

	return die;

}



//////////////////////checkDoubles()
//----------Compares the two randomly generated dice rolls to see if they are doubles,
//has a special case for snake eyes
void checkDoubles(int roll1, int roll2) {

	if (roll1 + roll2 == 2) {

		cout << "Snake eyes!\n";

	}
	else if (roll1 == roll2) {

		cout << "Doubles!\n";

	}

}



//////////////////////rollAgain()
//----------Asks the user if they would like to roll again. Returns true if they answer "yes"
//and false if they answer "no". If they input neither it asks them again for "yes" or "no"
bool rollAgain() {

	bool repeat, valid;
	string input;

	do {

		getline(cin, input);
		valid = true;

		for (int i = 0; i < input.length(); i++) {

			input[i] = tolower(input[i]);

		}

		if (input == "yes" || input == "y") {

			repeat = true;

		}
		else if (input == "no" || input == "n") {

			repeat = false;

		}
		else {

			valid = false;
			cout << "Please answer yes or no: ";

		}

	} while (!valid);

	return repeat;

}