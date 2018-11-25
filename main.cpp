#include <iostream>
#include "memories.h"

using namespace std;

void introduction();
//brief intro to the program

int main()
{
//    stringstream ss;
//    string input;

//    while(1)
//    {
//        mixedNumber a,b,c;
//        char junk = ' ';
//        cout << "Please enter an operation between two mixed numbers: ";
//        getline(cin, input);
//        ss << input;

//        ss >> a;

//        if(!(ss >> junk))
//            cout << "a = " << a << endl;
//        else
//        {
//            ss >> b;

//            switch(junk)
//            {
//                case '+':
//                    c=a+b;
//                    cout << "a+b = " << c << endl;
//                    break;
//                case '-':
//                    c=a-b;
//                    cout << "a-b = " << c << endl;
//                    break;
//                case '*':
//                    c=a*b;
//                    cout << "a*b = " << c << endl;
//                    break;
//                case '/':
//                    c=a/b;
//                    cout << "a/b = " << c << endl;
//                    break;
//                default:
//                    cout << endl;
//            }
//        }
//        ss.clear();
//    }

//    cout << "Here are your memories: " << d << endl;

//    cout << "testing display function ";
//    d.display();

//    cout << "testing print function ";
//    d.print("A");

//    cout << "testign save function ";
//    d.save("hello");

    mixedNumber a(2,1,2),b(3,3,4), j(2), k(1), l;
    complexNumber c(a,b);
    complexNumber d(b,a);

    complexNumber e,f,g,h(j,k);

    cout << "C = " << c << endl;
    cout << "D = " << d << endl;

    e=c+d;
    cout << "C+D = " << e << endl;
    f=c-d;
    cout << "C-D = " << f << endl;
    g=c*d;
    cout << "C*D = " << g << endl;
    cout << c << endl;
    c.conjugate();
    cout << c << endl;
    cout << "l is equal to: " << h << endl;

    l = h.magnitude();
    cout << "The magnitude of l is " << l << endl;






    return 0;
}

void introduction()
{
    string border(80, '*');

    cout << border << endl;
    cout << "This Program is called complexCalculate and it is an complexNumber Calculator /n that that will store up to 26 complex numbers." << endl;
    cout << border << endl;
}
