//Jacob Whitlow
//2-21-19
//This lab calculates pi at 

#include<iostream>
#include<iomanip>
#include<cctype>
#include<string>

using namespace std;


//function prototypes
double calcPi(int);
int validInt();


int main() {

	int numTerms;

	cout << "CALCULATING PI\n";
	cout << "==============\n";

	cout << "How many terms would you like to\nuse to calculate Pi?: ";

	numTerms = validInt();

	for (int i = 1; i <= numTerms; i++) {

		if (i % 10 == 0) {												//prints out the current pi calculation every 10 iterations
			
			cout << " Number of terms: " << i << " \t\tPi estimate: ";
			cout << calcPi(i) << endl;
		
		}

	}

	if (numTerms % 10 != 0) {											//prevents second printing of the same calculation if the users input
																		//is evenly divisble by 10
		cout << " Number of terms: " << numTerms << " \t\tPi estimate: ";
		cout << calcPi(numTerms) << endl;

	}

	system("PAUSE");
	return 0;

}



//////////////////////validInt()
//----------Makes sure the user has input an integer
int validInt() {

	bool valid;
	string input;

	do {

		getline(cin, input);
		valid = true;

		if (input == "") {

			valid = false;

		}


		for (int i = 0; i < input.size(); i++) {

			if (!isdigit(input[i])) {

				valid = false;

			}

		}

		if (valid && stoi(input) < 1) {

			valid = false;

		}

		if (!valid) {

			cout << "Please enter a positive integer: ";

		}

	} while (!valid);

	return stoi(input);

}



//////////////////////calcPi()
//----------Calculates the approximate value of pi based on the number of terms in the series
double calcPi(int numTerms) {

	double pi = 0;

	for (int i = 0; i < numTerms; i++) {					//Calculates pi at a specific set of terms in the
																	//infinite series
		if (i % 2 == 0) {

			pi = pi + 4.0 / (2.0 * (double)i + 1.0);

		}
		else {

			pi = pi - 4.0 / (2.0 * (double)i + 1.0);

		}

	}

	return pi;

}