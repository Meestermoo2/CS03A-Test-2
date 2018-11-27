#include "memories.h"
#include <cstdlib>
#include <iomanip>

memories::memories()
{
    for(unsigned int i = 0; i < 26; ++i)
    {
        library[i] = 0;
    }
    initializeMap();
}

memories::~memories()
{
    clearLibrary();
}

void memories::clearLibrary()
{
    for(unsigned int i = 0; i < 26; ++i)
    {
        library[i] = 0;
    }
}

void memories::initializeMap()
{
    commandMap["let"] = LET;
    commandMap["print"] = PRINT;
    commandMap["load"] = LOAD;
    commandMap["save"] = SAVE;
    commandMap["exit"] = EXIT;
    commandMap["display"] = DISPLAY;
    commandMap["wexit"] = WEXIT;
    commandMap["magnitude"] = MAGNITUDE;
    commandMap["trig"] = TRIG;
    commandMap["clear"] = CLEAR;
}
void memories::let(const std::string &arg)
{ // Configures an given expression derived from arg to a poly, also derived
  // from arg. E.g. "F=3X^3" etc.
    std::stringstream temp;
    std::string index2 = "";
    char index; // Holds first char to be used as index
    char junk; // Will hold '='

    temp << arg;
    temp >> index >> junk;
    index = toupper(index);
    index2 += index;
    if(index2.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ")<index2.size())
            throw INVALID_INPUT;

    complexNumber b;
    library[index-65] = b; // Sets the destination expression to zero before insertion
    temp >> library[index-65];

    // Displays a successful configuration
    std::cout << std::endl << index << " = "
              << library[int(index-65)] << std::endl;
}

// Loads preconfigured library of expression to current working library
void memories::load(const std::string &arg)
{
    std::ofstream out;
    std::ifstream in;
    std::string filename = arg;

    // Open with arg name, check to overwrite
    if(filename.find('.') > filename.size())
      filename+= ".complex";
    in.open(filename);
    if((in.fail()))

    {
        std::cout << "The input file does not exist!" << std::endl;
    }
    else
    {
        in >> *this;
        std::cout << "The file \"" << filename << "\" was loaded! \n";
    }
}
void memories::save(const std::string arg)
{ // Saves current expression library to file while checking for existing file
    std::ofstream out;
    std::ifstream in;
    std::string filename = arg;

    char ans;
    if(filename.find('.') > filename.size())
        filename += ".complex";
    in.open(filename);
    in.close();
    if(in.fail())
        out.open(filename);
    else
    {
        in.clear();
        std::cout<<"That file exists!!"<< std::endl;
        std::cout<<"Do you wish to overwrite it?" << std::endl;
        std::cin >> ans;

        char symbol;
        do
        {
            std::cin.get(symbol);
        } while (symbol != '\n');

        if(ans == 'Y' || ans == 'y')
            out.open(filename);
        else
        {
            std::cout << "You chose not to overwrite." << std::endl;
            return;
        }
    }

    out << *this; // Writes to file
    std::cout << "Save successful." << std::endl;
}

void memories::wexit(const std::string &arg)
{
        save(arg);
        exit(1);
}

void memories::Exit(const std::string &arg, const bool &saved)
{
    char ans;
    std::string filename;
    if(!(saved))
    {
        std::cout << "Do you wish to save the data to a file? "<<std::endl;
        std::cin >> ans;

        char symbol;
        do
        {
            std::cin.get(symbol);
        } while (symbol != '\n');

        if(ans == 'Y' || ans == 'y')
        {
            std::cout << "What is the name of the file? "<<std::endl;
            getline(std::cin, filename);
            save(filename);
            std::cout <<"Thank You!" << std::endl;
            exit(1);
        }
    }
    std::cout << "Thank You!" << std::endl;
    exit(1);
}

void memories::display()
{
    for(unsigned int i = 0; i < 26; ++i)
    {
        std::cout << static_cast<char>(i+65)
                  << " = " << library[i] << std::endl;;
    }

    std::cout << std::endl;
}

void memories::print(const std::string &arg)
{
    std:: cout << arg[0] << " = "<< library[toupper(arg[0])-65] << std::endl;
}

void memories::magnitude(const std::string &arg)
{
    std:: cout << "The magnitude of " << arg[0] << " is equal to "<< library[toupper(arg[0])-65].magnitude() << std::endl;
}

void memories::trig(const std::string &arg)
{
    library[int(arg[0]-65)].polarForm();
}
void memories::choice(const std::string &input,
                        const std::string &argument, bool saved)
{ // Maps a given input to our predefined functions
    std:: string temp_str = "";

    for (unsigned int i = 0; i < input.length(); ++i)
    {
        temp_str += tolower(input[i]);
    }

    switch(commandMap[temp_str])
    {
    case LET:
        let(argument);
        break;

    case EXIT:
        Exit(argument, saved);
        break;

    case WEXIT:
        wexit(argument);
        break;
    case CLEAR:
        clearLibrary();
        break;

    case TRIG:
        trig(argument);
        break;

    case PRINT:
        print(argument);
        break;

    case LOAD:
        load(argument);
        break;

    case SAVE:
        save(argument);
        break;

    case DISPLAY:
        display();
        break;

    case MAGNITUDE:
        magnitude(argument);
        break;
    }

}

void memories::add(const int index, const int arg1, const int arg2)
{
    library[index] = library[arg1] + library[arg2];
    std::cout << std::endl << char(index+65) << "=" << library[index] << std::endl;
}
void memories::subtract(const int index, const int arg1, const int arg2)
{
    library[index] = library[arg1] - library[arg2];
    std::cout << std::endl << char(index+65) << "=" << library[index] << std::endl;
}
void memories::multiply(const int index, const int arg1, const int arg2)
{
    library[index] = library[arg1] * library[arg2];
    std::cout << std::endl << char(index+65) << "=" << library[index] << std::endl;
}
void memories::divide(const int index, const int arg1, const int arg2)
{
    library[index] = library[arg1] / library[arg2];
    std::cout << std::endl << char(index+65) << "=" << library[index] << std::endl;
}
void memories::conjugate(const int index, const int arg1)
{
    library[index] = library[arg1].conjugate();
    std::cout << std::endl << char(index+65) << "=" << library[index] << std::endl;
}
void memories::power(const int index, const int arg1, const int arg2)
{
    library[index] = library[arg1]^library[arg2];
    std::cout << std::endl << char(index+65) << "=" << library[index] << std::endl;
}
