#include "memories.h"

std::ostream& operator<<(std::ostream& out, memories &m)
{
    for(unsigned int i = 0; i < 26; ++i)
    {
        out<< char(i+65) << "=" << m.library[i] << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, memories &m)
{
    std::string line;
    std::stringstream ss;
    char junk;
    char index;

    m.clearLibrary();
    for(unsigned int i = 0; i < 26; ++i)
    {
        //grabs a line
        getline(in, line);
        //puts in stream
        ss << line;
        //grabs index
        ss >> index; //index unused
        //throws away equals
        ss >> junk;
        //saves expresion as element of library(holds polynomials)
        ss >> m.library[i];
        ss.clear();

    }


    return in;

}
