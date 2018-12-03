#include "complexnumber.h"
#include <complex>

std::ostream& operator<<(std::ostream &out, complexNumber&c)
{
    //why not create the real part?

    if (c.getReal() !=0)
       out << c.getReal();

    if (c.imaginary != 0)
    {
        if (c.imaginary > 0 && c.getReal() !=0)
            out << '+';
        if (c.imaginary != 1 && c.imaginary != -1)
            out << c.imaginary;
        if (c.imaginary == -1)
            out << '-';
        out << 'i';
    }

    if (c.imaginary == 0 && c.getReal() == 0)
        out << '0';

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
            throw INVALIDCOMPLEX;
        ss<<possibleComplex;
        ss>>c;

    }
    else//Let's assume everything else is a file (for now)
    {
        while (in.peek() == ' ')
            in.get();

        char op; //used to contain operators
//        std::cout << "buffer :" << in.rdbuf()->in_avail() << std::endl;

        if (in.peek() == '+' || in.peek() == '-') // catches instances of ("+i" or "-i")
        {
            in >> op; // nabs operator for negation below
            if (in.peek() == 'i')
            {
                c.imaginary=(op == '-' ? -1:1); //if operator is negative,assign -1, otherwise 1
//                std::cout << "buffer :" << in.rdbuf()->in_avail() << std::endl;
                in.get();
                if (in.rdbuf()->in_avail() > 0) // if the buffer contains more than i..
                    throw INVALIDTYPE;
                return in;
            } else
                in.rdbuf()->sputbackc(op); // putback the operator if no 'i' was found
        }
//        std::cout << "buffer :" << in.rdbuf()->in_avail() << std::endl;

        if (in.peek() == 'i') // catches instances of i by itself ("i")
        {
            c.imaginary=1;
            // There is an odd interaction where if you input ("i21312" it will only return 1 for the buffer size. I believe this has to do with datatypes and their respective sizes)
            in >> op; // in pulling out the i to check empty buffer
//            std::cout << "buffer :" << in.rdbuf()->in_avail() << std::endl;
            if (in.rdbuf()->in_avail() > 0) // if the buffer contains more than i..
                throw INVALIDTYPE;
            return in;
        }

        mixedNumber temp; // Start taking numbers
        in >> temp;

//        std::cout << in.rdbuf()->in_avail();

        if (in.peek() == 'i')
        {
            c.setValue(0,temp);
            in.get();
            if (in.rdbuf()->in_avail() > 0) // if the buffer contains more than i..
                throw INVALIDTYPE;
            return in;
        }
        else
        {
            c.setReal(temp);
            if (in.peek() == '+' || in.peek() == '-')
            { // If an operator is found, assume there is a number that follows
                in >> op;
                if (in.peek() == 'i')
                {
                    in.get();
                    c.imaginary=(op == '-' ? -1:1); //if operator is negative,assign -1, otherwise 1
                    if (in.rdbuf()->in_avail() > 0) // if the buffer contains more than i..
                        throw INVALIDTYPE;
                    return in;
                } else
                    in.rdbuf()->sputbackc(op);

                in>>c.imaginary;
                if (in.peek() != 'i') //If i doesnt follow the input, throw an invalid type
                    throw INVALIDCOMPLEX;
                else
                {
                    in.get();
                    if (in.rdbuf()->in_avail() > 0) // if the buffer contains more than i..
                        throw INVALIDTYPE;
                }
            } else if (in.rdbuf()->in_avail() > 0)
                throw INVALIDTYPE;
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
    using namespace std;

    complex<double> a(x.getDouble(), x.imaginary.getDouble()),
                        b(y.getDouble(), y.imaginary.getDouble()),
                        c;

    c = exp(b*log(a));

    return complexNumber(c.real(),c.imag());
}
