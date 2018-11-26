#include <iostream>
#include <fstream>
#include <sstream>
#include "memories.h"
#include "driverprogram.cpp"

using namespace std;

void introduction();
//brief intro to the program

bool checkCL(int count);
//checks if there are any arguments in the command line, returns flag if true or false

void getInput(istream& in, memories&a, char *commands[],
              int count, bool record = false, bool execute = false);
//single input function for reading from file or terminal


void recordFile(std::string filename, string userInput);
//opens file, records given input, closes file

void executeFile(string filename, string &userInput, int&count);
//opens file, assigns command from file to userInput, closes file
int main(int argc, char *argv[])
{

    introduction();
    bool CL = checkCL(argc);
    while(1)
    {
       try
        {
            memories a;
            ifstream in;

            if(CL)
                getInput(in, a, argv, argc); //if parameters in command line, we're reading from a file
            else
                getInput(cin, a, argv, argc); //read straight from the terminal

        }
        catch (fraction_ERRORS e)
        {
            switch(e)
            {
                case DivByZero :
                    cout << "Division by zero" << endl;
                    break;
                case Invalid_Type :
                    cout << "Invalid type was entered" << endl;
                    break;
            }
        }
        catch (mixedNumber_ERRORS f)
        {
            switch(f)
            {
                case improper_mixed :
                    cout << "Improper Mixed Number" << endl;
                    break;
            }
        }catch(complexERRORS e)
        {
            switch(e) {
            case INVALIDINPUT:
                cout << "User has entered an invalid input";
                break;
            case INVALIDTYPE:
                cout << "Invalid Type" << endl;
                break;
            default:
                cout << "An unknown error has occured" << endl;
            }
        }
        catch (...)
        {
            cout << "an unknown error has occured" << endl;
        }
    }
    return 0;
}

void introduction()
{
    string border(80, '*');
    cout << border << endl;
    cout << "This Program is called complexCalculate and it is an complexNumber Calculator \n that that will store up to 26 complex numbers." << endl;
    cout << border << endl;
}

bool checkCL(int count)
{
    //if command line containes 1 or 2 parameters (excluding the name of the program)
    if(count == 2 || count == 3)
    {
        return true;
    }
    //if command line contains more than 2 parameters, error out
    else if(count > 3)
    {
        cout << "Error, there are more than 2 parameters on the command line \n"
             << "The program will now exit \n";
        exit(1);
    }
    //if no command line arguments, return false
    return false;
}

void getInput(istream& in, memories& a, char *commands[], int count,
              const bool record, const bool execute)
{
    string userInput;
    string arg;
    char junk;
    bool saved = false;

    int comCount=0;
    //reading from terminal
    if(&in == &cin)
    {
        while(1)
        {
            cout << "\nCOMMAND: ";

            //if execute was flagged
            if(execute)
            {
                //open file and reads from it, inputs line into userInput, closes file, this will be repeated
                //until the end.
                executeFile(commands[2], userInput, comCount);
            }
            else
                // Get user input from the command line
                getline(cin, userInput);

            stringstream user_ss(userInput);

            //if record was flagged, record every following input
            if(record)
            {
                recordFile(commands[2], userInput);
            }
            //if size of string is 0, (enter was pressed), terminate program
            if (userInput.size() == 0)
            {
                cout << "See ya!" << endl;
                exit(1);
            }

            //if second element of string is equals sign, go this path (ex. F=G+H, F=G'')
            if (userInput[1]=='=')
            {
                char index, b, c;

                index = toupper(userInput[0]); // takes initial element as variable for poly a
                b = toupper(userInput[2]);// takes 3rd element as letter for poly b

                //for derivative calculator (ex F=G')
                if (b == '~')
                {
                    c=toupper(userInput[3]);
                    a.conjugate(index-65, c-65);
                    //calculate conjugate
                }
                //for expresison calculator (ex F=G+H)
                else
                {
                    c= toupper(userInput[4]);
                    //switch that depends on operator
                    switch (userInput[3])
                    {
                    case '+':
                        a.add(index-65, b-65, c-65);
                        break;
                    case '-':
                        a.subtract(index-65, b-65, c-65);
                        break;
                    case '*':
                        a.multiply(index-65, b-65, c-65);
                        break;
                    case '/':
                        a.divide(index-65, b-65, c-65);
                        break;
                    case '^':
                        a.power(index-65, b-65, c-65);
                        break;
                    default:
                        cout << "Error " << endl;
                        exit(1);
                    }
                }
            }
            //if a command preceeds the expression (ex. Let F=2X+4)
            else
            {
                //take command
                user_ss >> userInput;
                user_ss.get(junk);
                //take expression
                getline(user_ss, arg);
                //passes it to choice function
                a.choice(userInput, arg, saved);
            }

        }
    }
    //if there are arguments in the command line
    else
    {
        string filename;

        //one argument after the name of the program
        if(count == 2)
        {
            cout << "There is one parameter in the command line" << endl;

            //load file associated with this parameter
            filename = commands[1];

            if(filename == "/h" || filename == "/?")
            {
                cout << "It seems that you need help, "
                        "you must include the name of the file that you wish to load" << endl;
                exit(1);
            }

            //load expressions from file chosen
            a.choice("load", filename, saved);

            //goes back to reading user input from terminal after loading expressions
            getInput(cin, a, commands, count, false, false);

        }
        //two arguemnts after the name of the program
        else if(count == 3)
        {
            ifstream file;
            string EXorRE;

            cout <<"There are two parameters in the command line" << endl;

            //first argument is a command, either execute or record
            EXorRE = commands[1];

            for (unsigned int i = 0; i < EXorRE.length(); ++i) // converts to uppercase
                EXorRE[i] = toupper(EXorRE[i]);

            //second argument is a script file
            filename = commands[2];

            if (EXorRE == "EXECUTE")
            {
                cout << "Executing File" << endl;
                //activates execute flag, treats the file commands as if they were input by a user
                getInput(cin, a, commands, count, false, true);

            }
            else if (EXorRE == "RECORD")
            {
                cout << "Recording File" << endl;
                //activates record flag, records user input commands into the file given by the commandline
                getInput(cin, a, commands, count, true, false);
            }

        }
    }
}

void recordFile(std::string filename, string userInput)
{ // Saves current expression library to file while checking for existing file
    cout << "Write Fired" << endl;
    ofstream out;
    std::ifstream in;

    if(filename.find('.') > filename.size())
        filename += ".spt";

    out.open(filename,ios_base::app);

    out << userInput << endl;

    out.close();
}

void executeFile(string filename, string &userInput, int &count)
{
    //open input file, keep grabbing a line from the file
    ifstream in;
    string line;
    if(filename.find('.') > filename.size())
        filename += ".spt";

    in.open(filename);

    for(int i = 0; i < count; i++)
    {
        getline(in, line);
    }
    getline(in, userInput);
    count++;
    in.close();
}
