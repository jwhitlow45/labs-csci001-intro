//Jacob Whitlow
//1-20-19
//Gets the radius of a circle and computes the area and circumference

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//Constant for pi
float pi = 3.14159;

//declaring functions
float area(float r), circumf(float r), getRadius();
char getUnits();
void solution(float r, char unit);



int main() {
	//radius of a circle variable
	float r;
	char unit;

	//user interface formatting
	cout << "CIRCUMFERENCE OF A CIRCLE CALCULATOR" << endl;
	cout << "====================================" << endl << endl;

	//Asks user for metric or imperial system
	cout << "CENTIMETERS OR INCHES? (m/i): ";
	unit = getUnits();

	//Stores userInput as r if it is a valid value
	cout << endl << "RADIUS OF YOUR CIRCLE: ";
	r = getRadius();

	//Prints out area and circumference with user preffered units
	solution(r, unit);


	system("PAUSE");
	return 0;
}



//----------------------------------------Calculates area of circle----------------------------------------
float area(float r) {
	return r * r*pi;
}


//----------------------------------------Calculatres circumference of circle----------------------------------------
float circumf(float r) {
	return 2 * r * pi;
}



//----------------------------------------Gets unit preference from the user----------------------------------------
char getUnits() {
	bool valid = true;
	char unit = cin.get();

	do {
		//Checks to see if input is the characters m or i
		if ((unit == 'm' || unit == 'i') && cin.get() == '\n'){
			return unit;

		//If input is invalid print error and do loop again
		} 
		
		else {
			valid = false;
			cout << "ERROR...CENTIMETERS OR INCHES? (m/i): ";
			
			//Discards any remaining values in the istream. This prevents program from printing multiple errors when
			//more than one character is entered at once.
			cin.ignore(256, '\n');
			cin >> unit;

		}
	} while (!valid);

}



//----------------------------------------Prompts user for radius and validates input----------------------------------------
float getRadius() {
	string userInput;
	bool valid, existDot;
	float r;
	

	do {
		valid = true;
		existDot = false;

		//gets input from user
		getline(cin, userInput);

		//checks if there is a digit or +/. in first place
		if (userInput[0] == '+' || userInput[0] == '.' || isdigit(userInput[0])) {

			//checks for first char being a dot
			if (userInput[0] == '.')
				existDot = true;

			//runs through each character seeing if it is a number
			for (int i = 1; i < userInput.length(); i++) {
			
				//if a dot has been found before it will not accept it as a valid input
				if (existDot && !isdigit(userInput[i])) {

					valid = false;
				}

				//if a dot hasn't been found before it will accept it as a valid input
				else if (!isdigit(userInput[i]) && userInput[i] != '.') {

					valid = false;
				}

				//checks for a dot at current char
				if (userInput[i] == '.')
					existDot = true;

			}

			//prints error if valid is false
			if (!valid)
				cout << "ERROR..PLEASE ENTER A VALID NUMBER: ";

		} 
		
		else {
			
			valid = false;
			cout << "ERROR..PLEASE ENTER A VALID NUMBER: ";
		}
			
		
	} while (!valid);

	r = stof(userInput);

	return r;
}



//----------------------------------------Outputs radius and circumference based on user unit preference----------------------------------------
void solution(float r, char unit) {
	//Checks if user selected metric and if so prints with metric units
	if (unit == 'm') {
		cout << endl << "AREA = " << area(r) << " cm^2" << endl;
		cout << "CIRCUMFERENCE = " << circumf(r) << " cm" << endl << endl;

	} 
	
	else { //If user selection was not metric prints out standard units
		cout << endl << "AREA = " << area(r) << " in^2" << endl;
		cout << "CIRCUMFERENCE = " << circumf(r) << " in" << endl << endl;
	}
}
