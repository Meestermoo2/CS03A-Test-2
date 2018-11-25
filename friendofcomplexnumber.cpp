#include "complexnumber.h"

std::ostream& operator<<(std::ostream &out, complexNumber&c)
{
    mixedNumber real(0, c.num, c.denom);

    out << real;

    if (c.imaginary != 0)
        out  << " + " << c.imaginary << "i";

    return out;
}

std::istream& operator<<(std::istream &in, complexNumber&c)
{
    return in;
}


complexNumber operator+(const complexNumber &x, const complexNumber &y)
{
//    complexNumber temp(x.getReal()+y.getReal(), x.imaginary+y.imaginary);
//    return temp;
}
