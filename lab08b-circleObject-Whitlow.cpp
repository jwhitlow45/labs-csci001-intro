#include <iostream>
#include <math.h>
using namespace std;

struct circle
{
private:
    double r, h, k;

public:
    void setRadius()
    {
        bool valid;
        //input validation for radius so radius cannot be a negative number
        do
        {
            valid = true;
            cin >> r;

            if (r <= 0)
            {
                cout << "Please enter a valid radius: ";
                valid = false;
            }
        } while (!valid);
    }
    void setH()
    {
        cin >> h;
    }
    void setK()
    {
        cin >> k;
    }
    //gets the stats of the circle from the user
    void getStats(int num)
    {
        cout << "Enter the radius of circle " << num << ": ";
        setRadius();

        cout << "Enter the x pos of the center circle " << num << ": ";
        setH();

        cout << "Enter the y pos of the center circle " << num << ": ";
        setK();
    }

    //calculates the area of the circle
    double calcArea()
    {
        return 3.141593 * pow(r, 2);
    }
    //calculates the circumference of the circle
    double calcCircum()
    {
        return 3.141593 * r * 2;
    }

    //prints the stats of the circle
    void printStats(int num)
    {
        cout << "Equation of circle " << num << ": ";

        if (h < 0 && k < 0)
        {
            cout << "(x+" << h * -1 << ")^2 + (y+"
                 << k * -1 << ")^2 = " << pow(r, 2);
        }
        else if (h < 0)
        {
            cout << "(x+" << h * -1 << ")^2 + (y"
                 << k * -1 << ")^2 = " << pow(r, 2);
        }
        else if (k < 0)
        {
            cout << "(x" << h * -1 << ")^2 + (y+"
                 << k * -1 << ")^2 = " << pow(r, 2);
        }
        else
        {
            cout << "(x" << h * -1 << ")^2 + (y"
                 << k * -1 << ")^2 = " << pow(r, 2);
        }

        cout << endl
             << "Area of circle " << num << ": " << calcArea();

        cout << endl
             << "Circumference of circle " << num << ": " << calcCircum();

        cout << endl;
    }
};

int main()
{
    circle circle1, circle2;

    //gets dimensions and coordinates of the circle
    circle1.getStats(1);
    cout << endl;
    circle2.getStats(2);

    //prints stats of the circle to the user
    cout << endl;
    circle1.printStats(1);
    cout << endl;
    circle2.printStats(2);
    cout << endl;

    system("PAUSE");
    return 0;
}