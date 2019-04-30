//Jacob Whitlow
//02-28-19
//Generates a random array of integers and then finds the minimum and maximum value of integers found in the array

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;


//function prototypes
bool runAgain();
void randomizeArray(int a[], int size);
int maxInteger(int a[], int size), minInteger(int a[], int size);


int main() {

	bool again;
	int randomNumbers[100];
	srand(time(NULL));

	cout << "This program generates a random array and finds the maximum and minimum values of the array.\n\n";

	do {

		randomizeArray(randomNumbers, 100);
		cout << "Max number in the array is: " << maxInteger(randomNumbers, 100) << endl;
		cout << "Min number in the array is: " << minInteger(randomNumbers, 100) << endl;

		again = runAgain();

		cout << endl;

	} while (again);

	return 0;

}



//////////////////////randomizeArray()
//----------generates a random array and populates the array a[]
void randomizeArray(int a[], int size) {

	for (int i = 0; i < size; i++) {

		a[i] = rand() % 1000 + 1;

	}

}



//////////////////////maxInteger()
//----------finds the maximum integer of the random array
int maxInteger(int a[], int size) {

	int max;

	for (int i = 1; i < size; i++) {

		max = a[0];

		if (max < a[i]) {

			max = a[i];

		}

	}

	return max;

}



//////////////////////minInteger()
//----------finds the minimum integer of the random array
int minInteger(int a[], int size) {

	int min;

	for (int i = 1; i < size; i++) {

		min = a[0];

		if (min > a[i]) {

			min = a[i];

		}

	}

	return min;

}



//
//
bool runAgain() {

	string input;
	bool valid;

	cout << "Run again? (yes/no): ";

	do {

		valid = true;
		getline(cin, input);

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

		}

		if (valid == false) {

			cout << "Please enter yes or no: ";

		}

	} while (!valid);


}