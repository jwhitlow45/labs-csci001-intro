//Jacob Whitlow
//03-28-19
//Formats first, middle, and last name entered by the user.

#include<iostream>
#include<string>

using namespace std;


//function prototypes
string lastNameFirst(string name[]);
void properCaps(string name[], int arraySize);


int main() {

	string userName[3];

	cout << "Enter your first name: ";
	getline(cin, userName[0]);

	cout << "Enter your middle name: ";
	getline(cin, userName[1]);

	cout << "Enter your last name: ";
	getline(cin, userName[2]);

	properCaps(userName, 3);

	cout << endl << "Your name is: ";
	cout << lastNameFirst(userName);

	cout << endl << endl;
	system("PAUSE");
	return 0;

}



//////////////////////properCaps()
//----------properly capitalizes strings
void properCaps(string name[], int arraySize) {

	for (int i = 0; i < arraySize; i++) {

		name[i][0] = toupper(name[i][0]);

		for (int j = 1; j < name[i].size(); j++) {

			if (name[i][j - 1] == ' ') {

				name[i][j] = toupper(name[i][j]);

			}
			else {

				name[i][j] = tolower(name[i][j]);

			}

		}

	}

}



////////////////////lastNameFirst()
//----------rearragnes the a name to have the last name first
string lastNameFirst(string name[]) {

	string nameFormat;

	nameFormat = name[2] + ", " + name[0] + " " + name[1][0] + ".";

	return nameFormat;

}