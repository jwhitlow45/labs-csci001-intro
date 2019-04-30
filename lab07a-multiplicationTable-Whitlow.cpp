//Jacob Whitlow
//03-12-19
//Prints out a multiplication table using two dimensional arrays

#include<iostream>

using namespace std;

void popArray(int x, int y, int table[10][10]), printArray(int x, int y, int table[10][10]);

int main() {

	int table[10][10];
	cout << endl << "\t";

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			popArray(i, j, table);
			printArray(i, j, table);

		}

	}

	cout << "\t\t\t";
	system("PAUSE");
	return 0;

}



//////////////////////popArray()
//----------populates an array with multiples
void popArray(int x, int y, int table[10][10]) {

	table[x][y] = (x + 1) * (y + 1);

}



//////////////////////printArray()
//----------prints out the array as a table
void printArray(int x, int y, int table[10][10]) {

	cout << table[x][y] << "\t";

	if (y == 9) {

		cout << endl << endl << "\t";

	}
	   
}