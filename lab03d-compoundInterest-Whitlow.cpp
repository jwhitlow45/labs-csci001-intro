//Jacob Whitlow
//02-01-19
//Calculates and returns the amount an investment has grown to based on a initial principal, interest, and time gotten from the user.

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;


//function prototypes
string getInput();
double calcTotal(double, double, double), validDouble(bool);
int validInt();


int main() {
	double principal, interest;
	int time;


	cout << "COMPOUND INTEREST CALCULATOR (COMPOUNDED MONTHLY)\n";
	cout << "=================================================\n";
	cout << "Enter the principal of your investment: $";
	principal = validDouble(true);								//true prevents non-monetary values (21.1, 22.002, 0.2045, etc.)

	cout << "\nEnter the interest rate of your investment: %";
	interest = validDouble(false);								//false allows non-monetary values

	cout << "\nEnter the time in years of your investment: ";
	time = validInt();

	cout << "\nAfter " << time << " year(s) at " << interest << "% interest your investment\n";
	cout << "will have grown to $" << fixed << setprecision(2) << calcTotal(principal, interest, time) << ".\n\n";


	system("PAUSE");
	return 0;

}



//---------------------------getInput()---------------------------
//++++++++ Stores and returns user input
string getInput() {
	
	string input;

	getline(cin, input);

	return input;

}



//---------------------------validDouble()---------------------------
//++++++++ Validates user's input. Prevents non-doubles from being inserted. If restrictDecimal is true then decimals are
//limited to the hundredths place (in the case of money).
double validDouble(bool restrictDecimal) {

	bool valid, existDot;													//keeps track of if variable is valid
	string userDouble;

	do {																	//loops while input is not valid

		valid = true;
		existDot = false;

		userDouble = getInput();											//stores user input as userDouble

		if (userDouble == "" || userDouble == ".") {						//prevents program from throwing error because of blank input or
																			//string which is only a dot
			valid = false;

		}

		else {

			for (int i = 0; i < userDouble.length(); i++) {					//goes through each char of userDouble

				if (existDot && !isdigit(userDouble[i])) {					//if a dot has been found and the current char is not a digit
																			//then store valid as false
					valid = false;

				}

				else if (!existDot && userDouble[i] != '.' && !isdigit(userDouble[i])) {	//if a dot has not been found and the cuurent char is
																							//not a dot and is not a digit then store valid as false
					valid = false;
				}

				if (userDouble[i] == '.') {									//if the current char is a decimal then flag that a dot exists (user
																			//to prevent two decimals from being input in the same number)
					existDot = true;

					if (restrictDecimal && i + 3 != userDouble.length()) {	//if restrictDecimal is true (meaning money is what is being input by the
																			//user) and there are not two chars after the decimal then the input
						valid = false;										//is not a valid amount of money (12.4, 12.444, etc.)

					}

				}



			}

		}

		if (!valid && restrictDecimal) {									//prints error message if input was not valid (type of error message
																			//depends on restrictDecimal being true($) or false(%))
			cout << "ERROR..Please enter a valid principal (int/double): $";

		}

		else if (!valid && !restrictDecimal) {

			cout << "ERROR..Please enter a valid interest rate (int/double): %";

		}

	} while (!valid);

	return stod(userDouble);												//returns the user input sa a double after it has been validated

}



//---------------------------validInt()---------------------------
////++++++++ Validates user's input. Prevents non-integers from being inserted
int validInt() {

	bool valid;																//keeps track of if variable is valid
	string userInt;

	do {																	//loops as while input is not valid

		valid = true;

		userInt = getInput();												//stores user input as userInt

		if (userInt == "") {												//prevents program from throwing error because of a blank input

			valid = false;

		}

		else {

			for (int i = 0; i < userInt.length(); i++) {					//checks if each char is a digit, if it is not a digit valid is
																			//stored as false
				if (!isdigit(userInt[i])) {

					valid = false;

				}

			}

		}

		if (!valid) {														//prints error message if input was not valid

			cout << "ERROR..Please enter a amount of years (int): ";

		}

	} while (!valid);

	return stoi(userInt);

}




//---------------------------calcTotal()---------------------------
//++++++++ Calculates total amount of money after interest period
double calcTotal(double p, double r, double t) {

	return (p * pow((1.0 + (r / 100.0) / 12.0), 12.0 * t));					//equation for monthly compound interest

}