//Jacob Whitlow
//01-31-19
//Finds the area of a triangle using Heron's Formula with 3 sides with length gotten from the user

#include<iostream>
#include<string>
#include<cmath>
using namespace std;


string getSide();
double validInput(), areaTriangle(double, double, double);
bool validTriangle(double);


int main() {

	double sideA, sideB, sideC;

	cout << "TRIANGLE AREA CALCULATOR (USING HERON'S FORMULA)\n";
	cout << "================================================\n";
	cout << "Enter the first side of your triangle: ";
	sideA = validInput();

	cout << "\nEnter the second side of your triangle: ";
	sideB = validInput();

	cout << "\nEnter the third side of your tiangle: ";
	sideC = validInput();

	if (validTriangle(areaTriangle(sideA, sideB, sideC))) {
	
		cout << "\nThe area of your triangle is: " << areaTriangle(sideA, sideB, sideC) << " units^2\n\n";
	
	}
	else {

		cout << "\nThat is not a valid triangle\n\n";

	}

	system("PAUSE");
	return 0;

}



//--------------------Gets length of sides from the user--------------------
string getSide() {

	string side;

	getline(cin, side);

	return side;

}



//--------------------Validates input from user--------------------
double validInput() {
	
	string input;
	bool existDot, valid;
	
	do {
		valid = true;
		existDot = false;

		input = getSide();																//calls user getSide() to get user input


		if (input == "" || input == ".") {												//if string input is NULL or a dot

			valid = false;

		}


		for (int i = 0; i < input.length(); i++) {										//runs through each iteration of i for the length of input

			if (existDot && !isdigit(input[i])) {										//if dot exists and char is not a digit

				valid = false;

			}
			else if (!existDot && !isdigit(input[i]) && input[i] != '.') {				//if dot doesnt exist and char is not a digit
																						//and char is not a dot
				valid = false;

			}
			
			if (input[i] == '.') {														//marks if dot is true

				existDot = true;
			
			}

		}


		if (!valid) {																	//prints error message if input is not valid

			cout << "ERROR...Enter a valid number: ";

		}

	} while (!valid);

	return stod(input);

}



//--------------------Calculates the area of the triangle--------------------
double areaTriangle(double a, double b, double c) {

	double s = (a + b + c) / 2.0;														//calculates s for heron's formula (makes math easier)

	return pow((s * (s - a) * (s - b) * (s - c)), 0.5);									//calculates area using heron's formula

}



//--------------------Checks if triangle area is valid--------------------
bool validTriangle(double area) {

	if (area > 0) {																		//if the area is a valid number then the triangle is valid
																						//(triangles which aren't valid give a negative sqroot
		return true;																	//and pow() will return -nan(ind) )

	}
	else {

		return false;																	//the triangle doesn't exist if the area isn't a
																						//positive number
	}

}