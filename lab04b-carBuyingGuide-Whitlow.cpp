//Jacob Whitlow
//2-10-19
//Gives recommendation on car to buy for the average male based on their age which is gotten from the user.

#include<iostream>

using namespace std;


//function prototypes
int userInput();
void recommendCar(int);


int main() {

	cout << "CAR BUYING GUIDE FOR THE AVERAGE MALE\n";
	cout << "=====================================\n\n";

	cout << "Enter your age: ";
	int age = userInput();

	cout << endl;
	recommendCar(age);

	system("PAUSE");
	return 0;

}



////////////////////////////////////////////userInput()
//--------------------Stores user's input for validation
int userInput() {
	
	int input;

	cin >> input;

	return input;

}



////////////////////////////////////////////recommendCar()
//--------------------Recommends car based on age input by the user
void recommendCar(int age) {

	if (age < 40) {

		cout << "Life stage 1\n";

		if (age < 25) {

			cout << "Buy a Ford Focus\n\n";								//Recommends a Ford Focus if user is 24 years old or younger

		}

		else {															//Recommends a minivan if user is 25-39 years old

			cout << "Buy a minivan\n\n";								

		}

	}

	else {

		cout << "Life stage 2\n";

		if (age < 55) {													//Recommends a Corvette if user is 40-54 years old

			cout << "Buy a Corvette\n\n";

		}

		else {															//Recommends a Lincoln Town car if user is 55 or older

			cout << "Buy a Lincoln Town car\n\n";

		}

	}

}
