//Jacob Whitlow
//03-28-19
//Prints out many different strings entered by the user with * and - as spaces

#include<iostream>
#include<string>

using namespace std;


//function prototypes
string getString();
void printStringDash(string), printStringAsterisk(string);


int main() {

	const int n = 5;
	string input, userStrings[n];

	cout << "Please enter a string: ";
	input = getString();

	printStringDash(input);

	cout << endl << endl << "Please enter 5 strings: ";

	for (int i = 0; i < n; i++) {

		getline(cin, userStrings[i]);

	}

	cout << endl;

	for (int i = 0; i < n; i++) {
	
		printStringAsterisk(userStrings[i]);
		cout << endl;
	
	}

	cout << endl;
	system("PAUSE");
	return 0;

}



//////////////////////getString()
//----------prompts the user for a string and stores the entered string
string getString() {

	string input;

	getline(cin, input);

	return input;

}



//////////////////////printStringDash()
//----------prints out a string with a dash inbetween each char
void printStringDash(string str) {

	for (int i = 0; i < str.size(); i++) {

		cout << str[i];

		if (i < str.size() - 1) {

			cout << "-";

		}

	}

	cout << endl;

	for (int i = str.size() - 1; i > -1; i--) {

		cout << str[i];
		
		if (i > 0) {
			
			cout << "-";
		
		}
	}


} 



//////////////////////printStringAsterisk()
//----------prints out a string with an asterisk between each char
void printStringAsterisk(string str) {

	for (int i = 0; i < str.size(); i++) {

		cout << str[i];

		if (i < str.size() - 1) {

			cout << "*";

		}

	}

}