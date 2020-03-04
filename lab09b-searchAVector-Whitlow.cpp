//Jacob Whitlow
//04-23-19
//Populates a 15 element vector, outputs contents to screen, checks if a num is
//in the vector, and asks the user if they would like to search the vector again.
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

//function prototypes
void populateVector(vector<int> &arg);
bool searchVector(vector<int> arg, int num);

int main()
{
    //seeds rng
    srand(time(NULL));

    int searchFor;
    char again;
    vector<int> numbers;

    populateVector(numbers);

    do
    {
        cout << endl
             << endl
             << "Enter a number to find in the vector: ";
        cin >> searchFor;

        cout << endl
             << "Vector: ";

        for (int i = 0; i < 15; i++)
        {
            cout << numbers[i] << " ";
        }

        cout << endl;

        if (searchVector(numbers, searchFor))
        {
            cout << "Number is present in the vector!";
        }
        else
        {
            cout << "Number is not present in the vector!";
        }

        cout << endl
             << "Search for another number? (y/n): ";
        cin >> again;
    } while (again == 'y');

    system("PAUSE");
    return 0;
}

void populateVector(vector<int> &arg)
{
    for (int i = 0; i < 15; i++)
    {
        arg.push_back(rand() % 10);
    }
}

bool searchVector(vector<int> arg, int num)
{
    for (int i = 0; i < arg.size(); i++)
    {
        if (num == arg[i])
        {
            return true;
        }
    }
    return false;
}