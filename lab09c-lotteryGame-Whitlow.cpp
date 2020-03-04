//Jacob Whitlow
//04-24-19
//Lottery game for the user to play. The user enters the winning ticket number and
//the program displays a random "quick pick". To win all 5 numbers must match

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

//function prototypes
int generateTicket(vector<int> &ticket);
void printTicket(vector<int> ticket);
void getUserTicket(vector<int> &ticket);
int countMatches(vector<int> ticket, vector<int> userTicket);

int main()
{
    srand(time(NULL));

    char again;
    vector<int> randTicket;
    vector<int> userTicket;

    do
    {
        randTicket.clear();
        userTicket.clear();

        generateTicket(randTicket);
        getUserTicket(userTicket);
        cout << endl
             << "Random ticket:\t";
        printTicket(randTicket);
        cout << endl
             << "User ticket:\t";
        printTicket(userTicket);
        cout << endl;
        cout << "There are " << countMatches(randTicket, userTicket) << " matches." << endl;

        if (countMatches(randTicket, userTicket) == 5)
        {
            cout << "You win!" << endl;
        }

        cout << "Play again?(y/n): ";
        cin >> again;
        cout << endl;
    } while (again == 'y');

    return 0;
}

int generateTicket(vector<int> &ticket)
{
    int num;
    bool repeat;

    for (int i = 0; i < 5; i++)
    {
        repeat = false;
        num = rand() % 10;

        for (int j = 0; j < ticket.size(); j++)
        {
            if (num == ticket[j])
            {
                repeat = true;
                i--;
            }
        }

        if (repeat == false)
        {
            ticket.push_back(num);
        }
    }
}

void getUserTicket(vector<int> &ticket)
{
    int input;
    cout << "Enter 5 DIFFERENT numbers from 0-9: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> input;
        ticket.push_back(input);
    }
}

void printTicket(vector<int> ticket)
{
    for (int i = 0; i < ticket.size(); i++)
    {
        cout << ticket[i] << " ";
    }
}

int countMatches(vector<int> ticket, vector<int> userTicket)
{
    int numMatches = 0;

    for (int i = 0; i < ticket.size(); i++)
    {
        for (int j = 0; j < ticket.size(); j++)
        {
            if (ticket[i] == userTicket[j])
            {
                numMatches++;
            }
        }
    }
    return numMatches;
}