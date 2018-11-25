#include "complexnumber.h"

std::ostream& operator<<(std::ostream &out, complexNumber&c)
{
    //why not create the real part?

    if (c.getReal() !=0)
       out << c.getReal();

    if (c.imaginary != 0)
    {
        if (c.imaginary > 0 && c.getReal() !=0)
            out << "+";
        if (c.imaginary != 1 && c.imaginary != -1)
            out << c.imaginary;
        out << "i";
    }

    return out;
}

std::istream& operator>>(std::istream &in, complexNumber&c)
{
    c.nukeEveryone();
    std::stringstream ss;
    std::string possibleComplex;
    if(&in == &std::cin) //This means that the program is reading from the console
    {
        std::getline(in, possibleComplex);
        if(possibleComplex.find_first_not_of("-+0123456789./i ") < possibleComplex.size())
            throw INVALIDTYPE;
        ss<<possibleComplex;
        ss>>c;

    }
    else//Let's assume everything else is a file (for now)
    {
        mixedNumber temp;
        in >> temp;


        if (in.peek() == 'i')
        {
            c.setValue(0,temp);
            return in;
        }
        else
        {
            c.setReal(temp);
            if (in.peek() == '+' || in.peek() == '-')
            {
                in>>c.imaginary;
                if (in.peek() != 'i')
                    throw INVALIDTYPE;
            }
        }
    }
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
    tempImag = a.getImaginary()/b.getReal();
    result.setValue(tempReal, tempImag);

    return result;
}

complexNumber operator^(const complexNumber &x, const complexNumber &y)
{
    complexNumber temp;
    return temp;
}
