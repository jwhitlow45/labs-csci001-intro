//Jacob Whitlow
//2-28-19
//Manipulates the array in various ways, printing out each variation of the array after it is finished being manipulated.

#include<iostream>
#include<ctime>

using namespace std;



int main() {

	int myArray[10];

	cout << "Zero Array: ";
	for (int i = 0; i < 10; i++) {			//sets every element in the array equal to zero

		myArray[i] = 0;
		cout << myArray[i] << " ";

	}


	srand(time(NULL));
	cout << "\nRandom Array: ";
	for (int i = 0; i < 10; i++) {			//sets each value in the array equal to a random number

		myArray[i] = rand() % 100 + 1;
		cout << myArray[i] << "  ";

	}

	
	cout << "\nOdd Array: ";
	for (int i = 1; i < 10; i++) {			//sets each value in the array to sequential odd values starting at 1

		int j = 1;

		myArray[i] = j;

		j = j + 2;

		cout << myArray[i] << "  ";

	}


	cout << "\nElement Index Array: ";
	for (int i = 0; i < 10; i++) {			//sets each odd index to 1 and each even index to 0

		if (i % 2 == 0) {

			myArray[i] = 0;

		}
		else {

			myArray[i] = 1;

		}

		cout << myArray[i] << "  ";

	}


	cout << "\nMultiples of 10 Array: ";
	for (int i = 0; i < 10; i++) {			//sets each value in the array to be a multiple of 10

		if (i == 0) {

			for (int j = 0; j < 10; j++) {
			
				myArray[j] = (j + 1) * 10;

			}

		}

		cout << myArray[9 - i] << "  ";
		
	}

	cout << endl;
	system("PAUSE");
	return 0;

}