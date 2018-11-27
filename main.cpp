#include "complexCalculate.h"
#include <fstream>

typedef void (*function)();

int main(int argc, char *argv[])
{
    introduction();
    std::map<std::string, function> functionList; // Initialize a map of functions, using strings as keys.
    loadFunction(functionList);
    bool programLoop = (argc < 3); // Check if there are CL arguments, no greater than 3

    while (programLoop)
    {
        memories mem; // Creates a library to store our complex numbers.
        std::ifstream in; // Used for reading from filestream.

        try
        {
            if (argc==1) // If there is only one argument, then we are reading from cin
                getInput(std::cin, mem, functionList);
            else         // If there is more than one argument, then  we are expecting a file
                getInput(in, mem, functionList);
        }
        catch (...)
        {
            std::cout << "An unknown error has occured.";
        }
    }
}




