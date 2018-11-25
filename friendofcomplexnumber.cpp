#include "complexnumber.h"

std::ostream& operator<<(std::ostream &out, complexNumber&c)
{
    mixedNumber real(0,c.num, c.denom);

    out << real  << " + " << c.imaginary << "i";

    return out;
}
