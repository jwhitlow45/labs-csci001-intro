//Jacob Whitlow
//01-31-19
//Gets a length and width of a rectangle from the user and prints the area and perimeter of the rectangle.

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//function prototypes
double calcPerim(double, double), calcArea(double, double), validInput();
string getUnits(), getMeasure();



int main() {

	double length, width;
	string units;

	cout << "AREA AND PERIMETER OF A RECTANGLE CALCULATOR\n";
	cout << "============================================\n";
	cout << "Please enter the length of your rectangle: ";
	length = validInput();

	cout << "\nPlease enter the width of your rectangle: ";
	width = validInput();

	cout << "\nPlease enter the units: ";
	units = getUnits();

	cout << "\nThe perimeter of your rectangle is " << calcPerim(length, width) << " " << units << ".";
	cout << "\nThe area of your rectangle is " << calcArea(length, width) << " " << units << "^2.\n\n";


	system("PAUSE");
	return 0;
}



//-------------------------------------------Gets measurements of the rectangle from the user-------------------------------------------
string getMeasure() {
	string input;

	getline(cin, input);

	return input;
}



//-------------------------------------------Validates that the user input was not negative or not valid-------------------------------------------
double validInput() {

	bool valid, existDot;
	string input;


	do {
		valid = true;
		existDot = false;

		input = getMeasure();

		for (int i = 0; i < input.length(); i++) {							//iterates until i is > length of the string

			if (existDot && !isdigit(input[i])) {							//if dot exists and char is not a digit

				valid = false;

			}

			else if (!existDot && !isdigit(input[i]) && input[i] != '.') {	//if dot doesnt exist and char is not a digit and char is not a dot

				valid = false;

			}

			if (input[i] == '.') {											//if input is a dot set exist dot to true

				existDot = true;

			}

		}

		if (input == "." || input == "") {									//if input is only a dot or NULL

			valid = false;

		}

		if (!valid) {														//print out error message if input isn't valid

			cout << "ERROR...Please enter a valid measurement: ";

		}

	} while (!valid);

	return stod(input);

}



//-------------------------------------------Gets units from the user-------------------------------------------
string getUnits() {
	string units;

	getline(cin, units);

	return units;
}



//-------------------------------------------Calculates perimeter of rectangle-------------------------------------------
double calcPerim(double l, double w) {

	return (2.0 * l + 2.0 * w);

}



//-------------------------------------------Calculates area of rectangle-------------------------------------------
double calcArea(double l, double w) {

	return (l * w);

}