#include "complexnumber.h"

std::ostream& operator<<(std::ostream &out, complexNumber&c)
{
    //why not create the real part?
    mixedNumber real(0, c.num, c.denom);

    out << real << " + " << c.imaginary << "i";

    return out;
}

std::istream& operator>>(std::istream &in, complexNumber&c)
{
    return in;
}

complexNumber operator+(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;

    temp.imaginary = x.imaginary + y.imaginary;

    return temp;
}

complexNumber operator-(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;

    temp.imaginary = x.imaginary + y.imaginary;

    return temp;
}

complexNumber operator*(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;


    temp.imaginary = x.imaginary + y.imaginary;

    return temp;
}

complexNumber operator/(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;

    temp.imaginary = x.imaginary + y.imaginary;

    return temp;
}

complexNumber operator^(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;

    temp.imaginary = x.imaginary + y.imaginary;

    return temp;
}
