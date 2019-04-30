//Jacob Whitlow
//2-21-19
//The purpose of this program is to calculate the discrimnant of a quadratic equation with coefficients obtained from the user.
//The discriminant tells us how many times the given quadratic equation crosses the x-axis (y = 0). If the solutions are imaginary
//then they are printed as complex numbers.

#include<iostream>
#include<cmath>
#include<cctype>
#include<string>
#include<iomanip>

using namespace std;


//function prototypes
string userInput();
double validInput(bool), calcDiscrim(double, double, double), 
calcSolution(double, double, double, bool), checkSolution(double, double, double);

void printResult(double, double, double);
bool runAgain();



int main() {

	double a, b, c;
	bool again;

	cout << "QUADRATIC EQUATION SOLVER (USING COEFFICIENTS)\n";
	cout << "==============================================\n";
	cout << "***Make sure your equation is in the form 'ax^2 + bx + c = 0'***\n";
	cout << "***The coefficient 'a' must be a non-zero number***\n\n";

	do {

		cout << "Enter the coefficient a: ";
		a = validInput(true);

		cout << "\nEnter the coefficient b: ";
		b = validInput(false);

		cout << "\nEnter the coefficient c: ";
		c = validInput(false);

		cout << endl;

		printResult(a, b, c);

		again = runAgain();

		cout << endl << endl;

	} while (again);

	return 0;

}



////////////////////////////////////////////userInput()
//--------------------Stores input gotten from the user for validation
string userInput() {

	string input;

	getline(cin, input);

	return input;

}



////////////////////////////////////////////validInput()
//--------------------Validates input to prevent any non-double inputs from being input and breaking the program
double validInput(bool isA) {

	bool valid, existDot;
	string input;


	do {

		valid = true;
		existDot = false;

		input = userInput();													//Calls userInput() and stores the user's input into input for to be validated
																				//Input from user is asked for again if input is determined to be not valid


		if (input == "" || input == "." || input == "-") {						//Prevents a blank input, a dot, or a dash from being input by themselves as this throws an error

			valid = false;

		}
		else if (input[0] != '-' && input[0] != '.' && !isdigit(input[0])) {	//Only accepts '-', '.', and digits as valid first chars. This makes it easier to validate negative numbers.
																				//This is needed because the first char is only checked once and doesn't catch these chars
			valid = false;

		}
		else {

			if (input[0] == '.') {												//Sets existDot to true if first char is a dot since the for loop doesnt check the first char for dots

				existDot = true;

			}

			for (int i = 1; i < input.length(); i++) {

				if (existDot && !isdigit(input[i])) {							//If a dot exists and the current char isnt a digit then the input is not valid

					valid = false;

				}
				else if (!existDot && !isdigit(input[i]) && input[i] != '.') {	//If a dot doesn't exist and the current char isnt a digit and isnt a dot then the input is not valid

					valid = false;

				}

				if (input[i] == '.') {											//Sets existDot to true if the current char is a dot

					existDot = true;

				}

			}

		}


		if (isA && valid && stod(input) == 0) {									//If the current input is for coeff 'a' and the input is valid and the input == 0 then valid = false
																				//This prevents coeff 'a' from having a 0 input as the quadratic equation must have a as a non-zero num
			valid = false;

		}

		if (!valid) {															//Prints error message if the input was determined to be not valid

			cout << "Please enter a valid number: ";

		}


	} while (!valid);

	return stod(input);

}



////////////////////////////////////////////calcDiscrim()
//--------------------Calculates the discriminant with coefficients obtained from the user
double calcDiscrim(double a, double b, double c) {

	return pow(b, 2) - 4.0 * a * c;												//Calculates discriminant

}



////////////////////////////////////////////calcSolution()
//--------------------Uses the quadratic equation to calculate the solutions of the quadratic formula with coefficients which were gotten from the user
double calcSolution(double a, double b, double c, bool pos) {

	double discrim;

	discrim = calcDiscrim(a, b, c);													//calculates discriminant


	if (discrim >= 0) {																//if there are real solutions (discriminant >=0)

		if (pos) {

			return (-b + pow(pow(b, 2) - 4.0 * a * c, 0.5)) / (2.0 * a);			//calculates first form of quadratic formula with -b adding to sqrt(b^2 - 4ac)

		}
		else {

			return (-b - pow(pow(b, 2) - 4.0 * a * c, 0.5)) / (2.0 * a);			//calculates second form of quadratic formula with -b subtracting from sqrt(b^2 - 4ac)

		}
	
	}
	else {																			//otherwise run the calculation for complex solutions

		if (pos) {

			return pow(abs(pow(b, 2) - (4.0 * a*c)), 0.5) / (2.0 * a);				//calculates positive solution is bool pos was true

		}
		else {

			return -1 * pow(abs(pow(b, 2) - (4.0 * a*c)), 0.5) / (2.0 * a);			//otherwise calculates negative solution

		}


	}

}



////////////////////////////////////////////checkSolution()
//--------------------Checks which of the two possible solutions is the real solution in the event the disciminant is equal to 0.
double checkSolution(double a, double b, double c) {

	double x = calcSolution(a, b, c, true);										//x is the calculated positive solution

	double check = (a * pow(x, 2)) + (b * x) + c;								//Puts a, b, c, and x into quadratic form which if equal to 0 means that x is the correct solution
																				//If x equals zero then the first form of the qudratic equation gives the correct solution
	if (check == 0) {															//If x does not equal zero then it is not the solution and the calculation with the other form of the 
																				//quadratic equation is the real solution
		return x;

	}
	else {

		return calcSolution(a, b, c, false);									//If the positive solution was not the proper solution then the negative one must be
																				//correct so the program returns the negative solution
	}

}



////////////////////////////////////////////printResult()
//--------------------Outputs results to user depending on what the discriminant is
void printResult(double a, double b, double c) {

	double discrim = calcDiscrim(a, b, c);

	if (discrim > 0) {															//If the discriminant is > 0 then there are two real solutions and there is no need to check
																				//to make sure the solutions are valid, so they can be calculated and printed.
		cout << "There are two real solutions which are x = "; 
		cout << fixed << setprecision(5) << calcSolution(a, b, c, true);
		cout << " and x = " << calcSolution(a, b, c, false) << ".\n\n";

	}
	else if (discrim == 0) {													//If the discriminant is == 0 then there is one real solution and the program checks which solution
																				//is correct and outputs it to the user.
		cout << "There is one real solution which is x = " << fixed << setprecision(5) << checkSolution(a, b, c) << ".\n\n";

	}
	else {																		//If the discriminant is < 0 there are no real solutions and the program doesn't need to calculate
																				//the solutions, and instead just tells the user there are no real solutions.
		
		if (b == 0) {

			cout << "There are two imaginary solutions which are ";
			cout << "x = " << calcSolution(a, b, c, true) << "i";				//calculates positive solution with no first term
			cout << " and ";
			cout << "x = " << calcSolution(a, b, c, false) << "i.\n\n";			//calculates negative solution with no first term

		}
		else {
		
			cout << "There are two imaginary solutions which are ";
			cout << -b / (2.0 * a) << " + " << calcSolution(a, b, c, true) << "i"; //calculates positive solution with first term
			cout << " and ";
			cout << -b / (2.0 * a) << " - " << calcSolution(a, b, c, true) << "i.\n\n";	//calculates positive solution with second term
																						//but the proper sign is printed as a string for
		}																				//formatting purposes so to the user it is negative

	}

}



//////////////////////runAgain()
//----------Gets input from user as to whether they want to run the program again.
//Returns true if "yes" is entered and false if "no" is entered.
bool runAgain() {

	string input;
	bool valid;

	cout << "Would you like to run the program again? (yes/no): ";						//prompts the user to run the program again

	do {																				//runs loop for input from user

		valid = true;

		getline(cin, input);															//stores user input as input

		for (int i = 0; i < input.length(); i++) {

			input[i] = tolower(input[i]);												//makes each char in the string lowercase so Yes, yEs, Y, etc.
																						//can be accepted
		}

		if (input == "yes" || input == "y") {											//if user says yes to running the program again return true
		
			return true;

		}
		else if (input == "no" || input == "n") {										//if user says no to running the program again return false

			return false;

		}
		else {

			valid = false;																//if user didn't enter "yes" or "no" set valid to false
			cout << "Please enter yes or no: ";											//prompts user for another input as they didn't
																						//enter yes or no
		}

	} while (!valid);																	//run loop as long as user is not inputting yes or no

}