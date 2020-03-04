//Jacob Whitlow
//04-23-19
//Populates the variables of a structure of type person with user input data
#include <iostream>
#include <string>

using namespace std;

struct person
{
    string firstName, middleName, lastName;
    int age;
    char gender;
};

int main()
{
    person person;

    cout << "Enter your first name: ";
    getline(cin, person.firstName);

    cout << "Enter your middle name: ";
    getline(cin, person.middleName);

    cout << "Enter your last name: ";
    getline(cin, person.lastName);

    cout << "Enter your age: ";
    cin >> person.age;

    cout << "Enter your gender (M/F): ";
    cin >> person.gender;

    cout << endl
         << endl
         << "Name: " << person.firstName << " " << person.middleName << " " << person.lastName << endl;

    cout << "Age: " << person.age << endl;

    cout << "Gender: " << person.gender << endl;

    system("PAUSE");
    return 0;
}