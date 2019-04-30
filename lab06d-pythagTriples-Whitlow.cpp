//Jacob Whitlow
//3-7-19
//Uses the concept of brute force to find all pythag triples, with sides being integers between 1 and 500

#include<iostream>

using namespace std;

//function prototypes
void bruteTriple(), printTriple(int, int, int);


int main() {


	cout << "LIST OF PYTHAGOREAN TRIPLES WITH SIDES 1-500\n";
	cout << "============================================\n";
	cout << "Side A\tSideB\tHypotenuse\n";

	bruteTriple();

	system("PAUSE");
	return 0;

}



////////////////////bruteTriple()
//----------uses brute force to find pythagorean triples with sides 1-500, calls upon printTriple if a pythag triple is found
void bruteTriple() {

	for (int i = 1; i < 501; i++) {

		for (int j = 1; j < 501; j++) {

			for (int k = 1; k < 501; k++) {

				if (i * i + j * j == k * k) {

					printTriple(i, j, k);

				}

			}

		}

	}


}



////////////////////printTriple()
//----------prints out three parameters given to the function, all on the same line, with a tab between the integers
void printTriple(int x, int y, int z) {

	cout << x << "\t" << y << "\t" << z << endl;

}