//Jacob Whitlow
//1-29-19
//Gets a temperature in degrees F from the user and turns it into degrees C

#include<iostream>
#include<cctype>
#include<string>
using namespace std;

//function prototypes
float getTempF(), convertToC(float);

int main() {
	float tempF;

	cout << "FARENHEIT TO CELCIUS CALCULATOR\n";
	cout << "===============================\n\n";

	cout << "Please enter the temperature in degrees farenheit: ";
	tempF = getTempF();

	cout << "\nIn metric, the temperature is " << convertToC(tempF) << " degrees celcius." << endl << endl;


	system("PAUSE");
	return 0;
}



//--------------------------Gets temperature from user and validates input--------------------------
float getTempF() {
	string tempF;					//string used to store user input and run input validation
	bool existDot, valid;			//does a dot exist in the number?, is the input valid?

	do {
		valid = true;
		existDot = false;

		getline(cin, tempF);													//Gets temperature from the user

		if (tempF[0] == '.') {													//if the first character is a dot
			existDot = true;
		}


		if (tempF[0] != '-' && tempF[0] != '.' && !isdigit(tempF[0])) {			//if the first char is not a - and not a dot 
			valid = false;														//and not a digit
		}

		else if (tempF == "-" || tempF == "." || tempF == "") {					//if the entire string is only a - or . or NULL
			valid = false;
		}

		else {

			for (int i = 1; i < tempF.length(); i++) {							//checks each char to make sure it is valid

				if (existDot && !isdigit(tempF[i])) {							//if a dot exists and the char is not a digit
					valid = false;
				}

				else if (!existDot && !isdigit(tempF[i]) && tempF[i] != '.') {	//if a dot doesnt exist and the char isnt a digit
					valid = false;												//and the char isnt a dot
				}

				if (tempF[i] == '.') {											//if the current char is a dot
					existDot = true;
				}

			}

		}

		if (!valid) {															//prints out error message if the input is not valid
			cout << "ERROR...Please enter a valid temperature: ";
		}

	} while (!valid);															//repeats if the input is not valid

	return stof(tempF);

}



//--------------------------Converts user input to celcius--------------------------
float convertToC(float initTemp) {

	return ((initTemp - 32.0)*(5.0 / 9.0));										//numbers must have a decimal place to prevent integer truncation

}