#include "complexnumber.h"

std::ostream& operator<<(std::ostream &out, complexNumber&c)
{
    mixedNumber real = c.num/c.denom, imaginaryPart = c.imaginary;

    out << real << " + " << imaginaryPart << "i";

    return out;
}
