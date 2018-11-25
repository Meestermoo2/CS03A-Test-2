#include "mixednumber.h"

std::ostream& operator<<( std::ostream &out, const mixedNumber &m)
{
     int whole = m.num/m.denom, numerator = m.num % m.denom;
     if(numerator == 0)
         out<<whole;
     else
         if(whole == 0)
             out<<numerator<<"/"<<m.denom;
        else
             out<<whole<<" "<<abs(numerator)<<"/"<<m.denom;
     return out;
}

std::istream& operator>>( std::istream &in, mixedNumber &m)
{ // Need to add cin logic? // need to add getline logic?
    fraction temp_whole, temp_mixed;

    if (in >> temp_whole)
        if (in.peek() == ' ')
        {
            in >> temp_mixed;
            if (temp_mixed.getDenom() < temp_mixed.getNum())
                throw improper_mixed;
        }

    if(temp_whole < 0)
        temp_mixed *= -1;

    if(in.fail())
    {
        m=temp_whole;
        in.clear();
    }
    else
        m = (temp_whole += temp_mixed);
    return in;
}
