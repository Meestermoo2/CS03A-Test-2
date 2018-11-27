#include "complexCalculate.h"

typedef void (*function)();

void introduction()
{
    using namespace std;
    string border(67, '*');
    cout << border << endl;
    cout << "This Program is called complexCalculate and it is an complexNumber "
            "\nCalculator that that will store up to 26 complex numbers." << endl;
    cout << border << endl;
}

void getInput(std::istream &in, memories &me, std::map<std::string, function> &list)
{ // This will retrieve input from either user or filestream.
    using namespace std;

    string userInput = "", argument = "";

    if (&in == &cin)
    {
        cout << "\nCOMMAND";
        getline(cin, userInput);
        if (userInput.empty())
            exit();
         // Using extractor operation, we will parse the first word and take it in as a command
        stringstream user_ss(userInput);
        user_ss >> userInput;
        getline(user_ss, argument);
    }
    else
    {
        cout << "Reading from in";
        std::exit(1);
    }
}

void let()
{

}

void print()
{

}

void save()
{

}

void load()
{

}

void exit()
{
    std::cout << "Exiting program.";
    std::exit(1);
}

void wexit()
{

}

void add()
{

}

void subtract()
{

}

void multiply()
{

}

void divide()
{

}

void power()
{

}

void orthogonal()
{

}

void trig()
{

}

void conjugate()
{

}

void loadFunction(std::map<std::string, function> &list)
{ // This will load up our array of function pointers.
    using namespace std;

    list["LET"] = let;
    list["PRINT"] = print;
    list["SAVE"] = save;
    list["LOAD"] = load;
    list["EXIT"] = exit;
    list["WEXIT"] = wexit;
    list["ADD"] = add;
    list["SUBTRACT"] = subtract;
    list["MULTIPLY"] = multiply;
    list["DIVIDE"] = divide;
    list["POWER"] = power;
    list["ORTHOGONAL"] = orthogonal;
    list["TRIG"] = trig;
    list["CONJUGATE"] = conjugate;
}

bool validateCommand(const std::string &arg)
{

    return false;
}
