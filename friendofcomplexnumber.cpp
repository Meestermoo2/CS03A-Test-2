#include "complexnumber.h"

std::ostream& operator<<(std::ostream &out, complexNumber&c)
{
    //why not create the real part?
    mixedNumber real(0, c.num, c.denom);

    out << real;


    if (c.imaginary != 0)
    {
        if (c.imaginary > 0)
            out << "+";
        out << c.imaginary << "i";
    }

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
    complexNumber a,b, result;

    a = x * y.conjugate();
    b = y * y.conjugate();
    // If you multiply a complex by its conjugate, it will isolate the real number

    mixedNumber tempReal, tempImag;
    tempReal = a.getReal()/b.getReal();
    tempImag = a.getImaginary()/a.getReal();
    result.setValue(tempReal, tempImag);

    return result;
}

complexNumber operator^(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    return temp;
}
