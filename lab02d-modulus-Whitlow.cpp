//Jacob Whitlow
//1-20-19
//Prints out each integer from 10 to 1 dividing 10 with the % operator and explains so to the user

#include<iostream>
using namespace std;

//declaring functions
void remainder();



int main() {

	cout << "This is a program which explains to modulus operator.\n";
	cout << "======================================================\n";
	cout << "This program uses the modulus operator (%), and integers from 1-10 starting at 10 on the integer 10.\n\n";

	remainder();

	cout << endl;

	system("PAUSE");
	return 0;

}



//-------------------------Prints out each step of the remainder-------------------------
void remainder() {
	
	for (int i = 10; i >= 1; i--) {

		if (i == 9) {
			
			cout << "\nThe modulus operator returns the remainder of a number X, divided by number Y. (X%Y)\n";
			cout << "Above 10 % 10 leaves no remainder and  returns 0. 10 % 9 reutrns 1 as shown below.\n\n";
		}

		if (i == 7) {
			cout << "\nAs we use the modulus operator with each integer starting at 10 down to 1, we see the remainder fluctuate.\n";
			cout << "You can double checks this is what is happening by doing the modulus operation in your head.\n\n";
		}

		if (i == 5) {
			cout << "\n5 will divide nicely and return 0 as shown below. Any numbers which return 0 are factors of the first number.\n";
			cout << "The other two numbers which return 0 are '2' and '1' since they also leave no remainder\n\n";
		}

		//Spaces to center numbers on = signs
		cout << "                          " << "10 % " << i << " = " << 10%i << endl;
			   
	}

}
