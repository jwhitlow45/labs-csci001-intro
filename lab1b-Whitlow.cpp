// Guessing Game

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessGame(); // function prototype
bool isCorrect(int, int); // function prototype 

int main()
{
	srand(time(0)); // seed random number generator
	guessGame();

	return 0;
}

void guessGame()
{
	int answer;
	int guess;
	char response;

	do {
		answer = 1 + rand() % 1000;

		// prompt for guess
		cout << "I have a number between 1 and 1000.\n"
			<< "Can you guess my number?\n"
			<< "Please type your first guess." << endl << "? ";

		cin >> guess;

		// loop until correct number
		while (!isCorrect(guess, answer))
			cin >> guess;

		// prompt for another game
		cout << "\nExcellent! You guessed the number!\n"
			<< "Would you like to play again (y or n)? ";

		cin >> response;

		cout << endl;

	} while (response == 'y');

}

bool isCorrect(int g, int a) //Breaks when entering a character because bool is expecting a variable from guess and receives a character
							 //Don't know exactly why this causes the program to loop, but it does
{
	if (g == a)
		return true;

	if (g < a)
		cout << "Too low. Try again.\n? ";

	else
		cout << "Too high. Try again.\n? ";

	return false;
}