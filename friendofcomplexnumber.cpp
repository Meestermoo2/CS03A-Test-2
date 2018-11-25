#include "complexnumber.h"

std::ostream& operator<<(std::ostream &out, complexNumber&c)
{
    //why not create the real part?
    mixedNumber real(0, c.num, c.denom);

    out << real;

    if (c.imaginary != 0)
        out  << " + " << c.imaginary << "i";

    return out;
}

std::istream& operator>>(std::istream &in, complexNumber&c)
{
    return in;
}
complexNumber operator+(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    mixedNumber realsum, imagsum;
    std::cout << "This is a test";
    realsum = x.getReal()+y.getReal();
    imagsum = x.getImaginary()+y.getImaginary();

    temp.setValue(realsum, imagsum);

    return temp;
}

complexNumber operator-(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    mixedNumber realsum, imagsum;

    realsum = x.getReal()-y.getReal();
    imagsum = x.getImaginary()-y.getImaginary();

    temp.setValue(realsum, imagsum);

    return temp;
}

complexNumber operator*(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    mixedNumber realsum, imagsum;

    realsum = (x.getReal()*y.getReal())-
                 (x.getImaginary()*y.getImaginary());

    imagsum = (x.getReal()*y.getImaginary())+
                 (y.getReal()*x.getImaginary());

    temp.setValue(realsum,imagsum);

    return temp;
}

complexNumber operator/(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    return temp;
}

complexNumber operator^(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    return temp;
}
