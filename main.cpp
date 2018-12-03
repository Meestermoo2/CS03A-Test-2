/* Complex Calculate
 * -By Edgar Flores and Rafael Betita.
 * */
#include "complexcalculate.h"
#include <fstream>

typedef void (*function)(const std::string &arg, memories &me);


void executeArguments(int argc, char *argv[], memories &mem, std::map<std::string, function> list, std::string &filename, bool &save);

int main(int argc, char *argv[])
{
    memories mem; // Creates a library to store our complex numbers.
    std::map<std::string, function> functionList; // Initialize a map of functions, using strings as keys.
    loadFunction(functionList);
    bool programLoop = (argc < 4), save = false, execute = false; // Check if there are CL arguments, no greater than 3
    std::string savename = "";
    executeArguments(argc, argv, mem, functionList, savename, save);

    while (programLoop)
    {
        try
        {
            getInput(std::cin, mem, functionList, save, execute, savename);
        }
        catch (fraction_ERRORS e)
        {
            switch(e)
            {
            case DIVBYZERO :
                std::cout << "Division by zero" << std::endl;
                break;
            case INVALIDFRACTION:
                std::cout << "Invalid fraction was entered" << std::endl;
                break;
            }
        }
        catch (mixedNumber_ERRORS f)
        {
            switch(f)
            {
            case INVALIDMIXED :
                std::cout << "Improper Mixed Number" << std::endl;
                break;
            }
        }catch(complexERRORS g)
        {
            switch(g) {
            case INVALIDTYPE:
                std::cout << "Extraneous input entered from user" << std::endl;
                break;
            case INVALIDCOMPLEX:
                std::cout << "Invalid complex number" << std::endl;
                break;
            }
        }
        catch(memories_ERRORS h)
        {
            switch(h)
            {
            case INVALID_INPUT:
                std::cout << "You entered an invalid input" << std::endl;
                break;
            }
        }
        catch (...)
        {
            std::cout << "An unknown error has occured.";
        }
    }
}

void executeArguments(int argc, char *argv[], memories &mem, std::map<std::string, function> list, std::string &filename, bool &save)
{
    introduction();
    using namespace std;

    if (argc == 2)
    {
        //load file associated with this parameter
        filename = argv[1];

        if(filename == "/h" || filename == "/?")
        {
            std::cout << "It seems that you need help, "
                    "you must include the name of the file that you wish to load" << std::endl;
            exit(1);
        }

        list["LOAD"](filename, mem); // LOADS FILES
    }
    else if (argc == 3)
    {
        ifstream file;
        string EXorRE;

        //first argument is a command, either execute or record
        EXorRE = argv[1];

        for (unsigned int i = 0; i < EXorRE.length(); ++i) // converts to uppercase
            EXorRE[i] = toupper(EXorRE[i]);

        //second argument is a script file
        filename = argv[2];
        if(filename.find('.') > filename.size())
             filename += ".spt";

        if (EXorRE == "EXECUTE")
        {
            cout << "Executing File" << endl;
            //activates execute flag, treats the file commands as if they were input by a user
            file.open(filename);

            while (!file.eof())
            {
                std::string temp;
                getline(file, temp);
                std::stringstream ss(temp);
                std::cout <<"\nCOMMAND: ";
                std::cout << temp << std::endl;
                getInput(ss, mem, list, save, true, filename="");
            }
            exit(1);
        }
        else if (EXorRE == "RECORD")
        {
            cout << "Recording File" << endl;
            cout << "Your inputs are being recorded" << endl;
            //activates record flag, records user input commands into the file given by the commandline
            getInput(cin, mem, list, save, false, filename);
        }
    }
    if (argc > 3)
    {
        cout << "Too many command line arguments.\nExiting program..\n\n";
        exit(1);
    }

}

/********************************************************************
This Program is called complexCalculate and it is an complexNumber
Calculator that that will store up to 26 complex numbers.
*******************************************************************

COMMAND: load testFile
The file "testFile.complex" was loaded!

COMMAND: display

A=3+2i
B=3 3/4-1 1/2i
C=5+4i
D=3-2i
E=-119 713397/1000000-1005 6689/125000i
F=3+4i
G=25i
H=20
I=0
J=0
K=0
L=0
M=0
N=0
O=0
P=0
Q=0
R=0
S=0
T=0
U=0
V=0
W=0
X=0
Y=0
Z=0


COMMAND: let I=3 1/2-2.5i

I = 3 1/2-2 1/2i

COMMAND: J =D+a

J=6

COMMAND: save testFile2
Save successful.

COMMAND: exit
Thank You!
Press <RETURN> to close this window...

*/
