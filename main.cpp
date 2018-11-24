#include <iostream>
#include "mixednumber.h"

using namespace std;

void introduction();
//brief intro to the program

int main()
{
    stringstream ss;
    string input;

    while(1)
    {
        mixedNumber a,b,c;
        char junk = ' ';
        cout << "Please enter an operation between two mixed numbers: ";
        getline(cin, input);
        ss << input;

        ss >> a;

        if(!(ss >> junk))
            cout << "a = " << a << endl;
        else
        {
            ss >> b;

            switch(junk)
            {
                case '+':
                    c=a+b;
                    cout << "a+b = " << c << endl;
                    break;
                case '-':
                    c=a-b;
                    cout << "a-b = " << c << endl;
                    break;
                case '*':
                    c=a*b;
                    cout << "a*b = " << c << endl;
                    break;
                case '/':
                    c=a/b;
                    cout << "a/b = " << c << endl;
                    break;
                default:
                    cout << endl;
            }
        }
        ss.clear();
    }

    return 0;
}

void introduction()
{
    string border(80, '*');

    cout << border << endl;
    cout << "This Program is called complexCalculate and it is an complexNumber Calculator /n that that will store up to 26 complex numbers." << endl;
    cout << border << endl;
}
