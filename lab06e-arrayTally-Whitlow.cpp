//Jacob Whitlow
//3-7-19
//Rolls a dice 50,000 times. Keeps a tally of the results in an array and prints the array after all the dice have been rolled.


#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;


//function prototypes
bool rollAgain();
int rollDie();
void storeResults(int die, int results[], int total[]), printResults(int results[], int total[]);



int main() {

	//seeds random number
	srand(time(NULL));

	//arrays for storing results and total
	int results[] = { 0,0,0,0,0,0 };
	int total[] = { 0,0,0,0,0,0 };

	bool again;

	do {

		int results[] = { 0,0,0,0,0,0 };

		for (int i = 0; i < 50000; i++) {

			storeResults(rollDie(), results, total);

		}

		printResults(results, total);

		cout << "Roll again? (yes/no): ";

		again = rollAgain();

		cout << endl << endl;

	} while (again);

	return 0;

}



//////////////////////rollDie()
//----------randomly generates number from 1 to 6
int rollDie() {

	int die = rand() % 6 + 1;

	return die;

}



//////////////////////storeResults()
//----------stores results in results[] array by adding 1 to the index corresponding to the roll result
void storeResults(int die, int results[], int total[]) {

	results[die - 1] = results[die - 1]++;
	total[die - 1] = total[die - 1]++;

}



//////////////////////printResults()
//----------prints results of the 50,000 rolls to the user
void printResults(int results[], int total[]) {

	cout << "RESULTS OF 50,000 DICE ROLLS\n";
	cout << "============================\n";
	
	cout << "SIDE OF DICE\t";

	for (int i = 0; i < 6; i++) {

		cout << i + 1 << "\t";

	}

	cout << endl << "THIS ROLL\t";

	for (int i = 0; i < 6; i++) {

		cout << results[i] << "\t";

	}

	cout << endl << "TOTAL OF ROLLS\t";

	for (int i = 0; i < 6; i++) {

		cout << total[i] << "\t";

	}

	cout << endl << endl;

}



////////////////////rollAgain()
//----------Rolls die again depending on user input
bool rollAgain() {

	bool valid;
	string input;

	do {

		getline(cin, input);

		valid = true;

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
