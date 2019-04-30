//Jacob Whitlow
//2-14-19
//Prompts the user for their role and the price of the car they sold.
//Based on those two parameters the user is told the amount of comission they earned on a sale.

#include<iostream>
#include<cctype>
#include<string>
#include<iomanip>

using namespace std;


//function prototypes
double validSalePrice();
double calcCommission(double, double), commissionPercent(double);


int main() {

	double salePrice, commission;


	cout << "COMMISSION FROM SALE CALCULATOR\n";
	cout << "===============================\n\n";

	cout << "Please enter the amount of the car you sold: $";
	salePrice = validSalePrice();

	cout << endl << "Are you a salesperson or a loan officer?(s/l): ";
	commission = commissionPercent(salePrice);
	cout << endl;

	cout << "You made $" << fixed << setprecision(2) << calcCommission(salePrice, commission) << " in commission!\n\n";

	system("PAUSE");
	return 0;
}



////////////////////////userInput()
//------------------Returns input from user as a string for input validation
string userInput() {

	string input;

	getline(cin, input);

	return input;

}



////////////////////////validSalePrice()
//------------------Validates that the user input a valid monetary value 
double validSalePrice() {

	bool existDot, valid;													//Flags for a dot in the string(existDot) and valid inputs (valid)
	string input;															//Used to store user input for validation


	do {

		input = userInput();												//Stores user's input as input

		valid = true;
		existDot = false;

		if (input == "" || input == ".") {									//Prevents blank and only dots as inputs

			valid = false;

		}

		for (int i = 0; i < input.length(); i++) {

			if (existDot && !isdigit(input[i])) {							//Doesn't accept dots if one was found because it would not be valid

				valid = false;

			}
			else if (!existDot && !isdigit(input[i]) && input[i] != '.') {	//Accepts dots as inputs if there wasn't one found previously

				valid = false;

			}

			if (input[i] == '.') {											//Flags existDot as true if a dot is found

				existDot = true;

				if (i + 3 != input.length()) {								//Requires there to be two numbers after the dot if there is one
																			//This is required because 12.2 and 12.222 are not valid
					valid = false;											//monetary values.

				}

			}

		}

		if (!valid) {														//Prints error message if input is flagged as invalid

			cout << "ERROR...Please enter a monetary value: ";

		}


	} while (!valid);														//Continues the loop as long as the user input is not valid

	return stod(input);

}



////////////////////////commissionPercent()
//------------------Determines percentage of sale to be used for commisssion based on price of car and user's role
double commissionPercent(double price) {

	bool valid;
	char role;

	do {

		valid = true;

		cin >> role;

		if (role == 's') {													//If the user's role is a salesperson, use these values for
																			//commission percentage
			if (price <= 12000) {

				return 0.02;

			}
			else if (price <= 22000) {

				return 0.03;

			}
			else {

				return 0.04;

			}

		}
		else if (role == 'l') {												//If the user's role is a loan officer, use these values for
																			//commission percentage
			if (price <= 12000) {

				return 0.005;

			}
			else if (price <= 22000) {

				return 0.007;

			}
			else {

				return 0.008;

			}

		}
		else {

			valid = false;
			cout << "ERROR...Please enter a valid role(s/l): ";

		}

	} while (!valid);

}



////////////////////////calcComission()
//------------------Calculates amount of commission to be earned from a sale
double calcCommission(double price, double commission) {

	return price * commission;

}