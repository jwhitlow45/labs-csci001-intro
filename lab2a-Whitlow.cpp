//Jacob Whitlow
//1-19-19
//Gets the sum product and average of 3 integers provided by the user


#include<iostream>
#include<cctype>
#include<string>
using namespace std;


//declaring functions
int getNumber(), sum(int x, int y,int z), avg(int x, int y, int z), prod(int x, int y, int z);


int main() {

	//variables to be put into the calculator
	int num1, num2, num3;

	cout << "SUM, PRODUCT, AND AVERAGE CALCULATOR" << endl
		<< "=====================================" << endl << endl
		<< "PLEASE ENTER 3 INTEGERS" << endl;

	//gets 3 integers from user
	cout << "First integer: ";
	num1 = getNumber();

	cout << endl << "Second integer: ";
	num2 = getNumber();

	cout << endl << "Third integer: ";
	num3 = getNumber();

	//prints out sum prod and average of numbers
	cout << endl << "SUM: " << sum(num1, num2, num3);
	cout << endl << "PRODUCT: " << prod(num1, num2, num3);
	cout << endl << "AVERAGE: " << avg(num1, num2, num3);
	cout << endl << endl;

	system("PAUSE");
	return 0;

}



//Gets input from user and checks to make sure it is an integer
int getNumber() { 
	string userInput;
	int num;
	bool valid;

	//verifies user input a valid integer
	do {
		valid = true;

		getline(cin, userInput);

		//checks if userinput is a number or +/- sign
		if (userInput[0] == '-' || userInput[0] == '+' || isdigit(userInput[0])) {

			//checks if user input is a number starting from [1] of array
			for (int i = 1; i < userInput.length(); i++) {
				
				if (!isdigit(userInput[i]))
					valid = false;
			} 
		} else
			valid = false;

		//if userInput is valid convert it to an integer
		if (valid) {
			num = stoi(userInput);

		} else //if userInput is not valid then print an error
			cout << "ERROR...Please enter an integer: ";

	} while (!valid); 

	return num;
}



//finds sum of 3 inputs
int sum(int x, int y, int z) {
	return x+y+z;
}



//finds product of 3 inputs
int prod(int x, int y, int z) {
	return x*y*z;
}



//finds average of 3 inputs
int avg(int x, int y, int z) {
	return (x+y+z)/3;
}