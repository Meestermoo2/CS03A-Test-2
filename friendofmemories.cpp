#include "memories.h"

std::ostream& operator<<(std::ostream& out, const memories &m)
{
    for(unsigned int i = 0; i < 26; ++i)
    {
        out<< char(i+65) << "=" << m.library[i] << std::endl;
    }
    return out;
}

//std::istream& operator>>(std::istream& in, memories m)
//{

//}
