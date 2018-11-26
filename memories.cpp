#include "memories.h"

memories::memories()
{
    for(unsigned int i = 0; i < 26; ++i)
    {
        library[i] = 0;
    }
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

void memories::save(std::string arg)
{ // Saves current expression library to file while checking for existing file
    std::ofstream out;
    std::ifstream in;
    std::string filename = arg;

    char ans;
    if(filename.find('.') > filename.size())
        filename += ".exp";
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

void memories::display()
{
    for(unsigned int i = 0; i < 26; ++i)
        std::cout<< static_cast<char>(i+65)
                  << " = " << library[i] << std::endl;

    std::cout << std::endl;
}

void memories::print(const std::string &arg)
{
    std:: cout << arg[0] << " = "<< library[toupper(arg[0])-65] << std::endl;
}
