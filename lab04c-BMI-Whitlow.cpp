//Jacob Whitlow
//2-13-19
//Prompts user for weight and height, validates user's weight and height are valid, non-negative doubles,
//and returns BMI to the user.

#include<iostream>
#include<string>
#include<cctype>

using namespace std;


//function prototypes
string userInput();
double calcBMI(double, double, double), validInput(bool);
void result(double);


int main() {

	double weight, feet, inches, BMI;

	cout << "BMI CALCULATOR\n";
	cout << "==============\n\n";
	
	cout << "How much do you weigh?\nPounds(lbs): ";
	weight = validInput(true);

	cout << endl;
	cout << "How tall are you?\nFeet(ft): ";
	feet = validInput(false);

	cout << "Inches(in): ";
	inches = validInput(false);

	BMI = calcBMI(weight, feet, inches);

	cout << endl;
	cout << "Your BMI is " << BMI << ". This means you are\n"; 
	result(BMI);
	cout << " according to a BMI chart.\n\n";

	system("PAUSE");
	return 0;
}



////////////////////////////userInput()
//--------------------Stores input gotten from user and returns it
string userInput() {

	string input;

	getline(cin, input);

	return input;

}



////////////////////////////validInput()
//--------------------Validates user input is a non-negative double
double validInput(bool isWeight) {
	
	string input;
	bool valid, existDot;


	do {

		valid = true;
		existDot = false;

		input = userInput();


		if (input == "" || input == ".") {									//Prevents blank inputs and a dot from being accepted

			valid = false;

		}


		for (int i = 0; i < input.length(); i++) {

			if (existDot && !isdigit(input[i])) {							//If existDot is true, and the current char is not a digit,
																			//the input is not valid (this prevents two dots from being input)
				valid = false;

			}
			else if (!existDot && !isdigit(input[i]) && input[i] != '.') {	//If existDot is false, and current char is not a digit, and
																			//input is not a dot, the input is not valid
				valid = false;

			}

			if (input[i] == '.') {											//Sets existDot to true if current char is a dot

				existDot = true;

				if (!isWeight) {											//Sets valid to false if the current char is a dot
																			//and the user is not inputting weight
					valid = false;

				}

			}

		}


		if (!valid && isWeight) {											//Prints out error message if the user input an
																			//invalid weight
			cout << "ERROR..Please enter a valid weight: ";

		}
		else if (!valid) {													//Prints out error message if the user input an
																			//invalid height
			cout << "ERROR..Please enter a valid measurement: ";

		}

	} while (!valid);


	return stod(input);

}



////////////////////////////calcBMI()
//--------------------Does math to calculate BMI and returns BMI
double calcBMI(double weight, double feet, double inches) {

	double height = (feet * 12) + inches;

	return (weight * 703) / (height*height);

}



//////////////////////////////result()
//--------------------Outputs result of BMI table according to user's BMI
void result(double BMI) {

	if (BMI < 18.5) {

		cout << "UNDERWEIGHT";

	}
	else if (BMI < 25) {

		cout << "NORMAL WEIGHT";

	}
	else if (BMI < 30) {

		cout << "OVERWEIGHT";

	}
	else {

		cout << "OBESE";

	}

}