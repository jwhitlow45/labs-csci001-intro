//Jacob Whitlow
//04-23-19
//Gets as many string as the user would like to input. Stores them in a vector,
//prints the strings back to the user, and then prints a random string out to the user
//from the vector of strings.
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

//function prototypes
void printStrings(vector<string> arg);
string randomString(vector<string> arg);

int main()
{
    srand(time(NULL));
    vector<string> userStrings;

    cout << "Enter as many strings as you would like. "
         << "Enter a blank string when you are done." << endl
         << endl;

    do
    {
        string userInput;
        getline(cin, userInput);

        if (userInput == "")
        {
            break;
        }

        userStrings.push_back(userInput);
    } while (true);

    printStrings(userStrings);
    cout << endl;
    cout << "Random string from user input: " << randomString(userStrings);

    system("PAUSE");
    return 0;
}

void printStrings(vector<string> arg)
{
    cout << "Strings in the vector : ";

    for (int i = 0; i < arg.size(); i++)
    {
        cout << arg[i] << " ";
    }
}

string randomString(vector<string> arg)
{
    return arg[rand() % arg.size()];
}