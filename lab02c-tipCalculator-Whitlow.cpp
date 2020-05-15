//Jacob Whitlow
//1-21-19
//Stores the name of server and cost of service via user input. Calculates tip and displays tip as well as total cost.

#include<iostream>
#include<cctype>
#include<string>
#include<iomanip>
using namespace std;



//function protoypes
string getName();
float getCost(), getTip();


int main() {
	string name;	
	float cost, tipAmount, tipPercent;

	cout << "TIP CALCULATOR" << endl;
	cout << "==============" << endl << endl;

	name = getName();
	cout << endl;
	cost = getCost();
	cout << endl;

	tipPercent = getTip();
	tipAmount = cost * (tipPercent / (float)100);
	

	cout << endl << endl << "Server's Name: " << name << endl << endl;
	cout << "Cost of service: $" << cost << endl << endl;
	cout << "Cost of tip: $" << fixed << setprecision(2) << tipAmount << endl << endl << endl;
	cout << "Total cost: $" << fixed << setprecision(2) << cost + tipAmount << endl << endl << endl;


	system("PAUSE");
	return 0;

}


//---------------------------Gets name of server from user---------------------------
string getName() {
	string name;

	cout << "Enter the name of your server: ";
	getline(cin, name);

	return name;
}



//---------------------------Gets cost of service from user---------------------------
float getCost() {
	string cost;
	bool valid, existDot;

	cout << "Enter the cost of your meal: $";
	
	do {
		valid = true;
		existDot = false;

		//gets cost from user
		getline(cin, cost);
	


		if (cost == "")			
			valid = false;

		else {

			//runs through each character in the string and checks if it is valid (accepts only numbers)
			for (int i = 0; i < cost.length(); i++) {

				//if dot exists and char is not a digit
				if (existDot && !isdigit(cost[i]))
					valid = false;

				//if dot doesn't exist and char is not a digit and char is not a dot
				else if (!existDot && !isdigit(cost[i]) && cost[i] != '.')
					valid = false;

				//if char is a dot
				if (cost[i] == '.')
					existDot = true;

			}
		}

		//Makes sure string won't be too short and throw an exception by looking for
		//a character at the position -1
		if (existDot && valid) {

			if (cost.length() < 3)
				valid = false;

			//if the third to last character in the string is not a dot
			else if (cost[cost.length() - 3] != '.')
				valid = false;
		}

		//if input is invalid print error message
		if (!valid)
			cout << "ERROR..Enter the cost of your meal: $";

	} while (!valid);
	
	
	return stof(cost);
}



//---------------------------Gets tip from user and validates input---------------------------
float getTip() {
	string tip;
	bool valid, existDot;

	cout << "Enter tip percentage: %";

	do {
		valid = true;
		existDot = false;

		getline(cin, tip);

		if (tip == "")
			valid = false;

		else {
			for (int i = 0; i < tip.length(); i++) {

				//if dot exists and char is not a digit
				if (existDot && !isdigit(tip[i]))
					valid = false;

				//if dot doesn't exist and char is not a digit and char is not a dot
				else if (!existDot && !isdigit(tip[i]) && tip[i] != '.')
					valid = false;
				
				//if char is a dot
				if (tip[i] == '.')
					existDot = true;

			}
		}

		//if input is invalid print error message
		if (!valid)
			cout << "ERROR..Enter tip percentage: %";

	} while (!valid);

	return stof(tip);
}
