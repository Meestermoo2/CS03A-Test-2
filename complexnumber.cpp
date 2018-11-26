#include "complexnumber.h"

complexNumber::complexNumber()
{
    imaginary = 0;
}

complexNumber::~complexNumber()
{
    nukeEveryone();
}

complexNumber::complexNumber(const complexNumber &other)
{
    copy(other);
}

complexNumber::complexNumber(const mixedNumber &realPart, const mixedNumber &imaginaryPart)
{
    num = realPart.getNum();
    denom = realPart.getDenom();

    imaginary = imaginaryPart;
}

complexNumber::complexNumber(const double &realPart, const double &imaginaryPart)
{
    mixedNumber temp(realPart), temp2(imaginaryPart);
    this->setValue(temp, temp2);
}

complexNumber::complexNumber(const int &realPart, const int &imaginaryPart)
{
    mixedNumber temp(realPart), temp2(imaginaryPart);
    this->setValue(temp, temp2);
}

complexNumber& complexNumber::operator=(const complexNumber &other)
{
    if(this != &other)
    {
        num = other.num;
        denom = other.denom;

        imaginary = other.imaginary;
    }
    return *this;
}

complexNumber& complexNumber::operator=(const mixedNumber &other)
{ // This creates a temp fraction because a mixedNumber can be constructed from its fraction constituents.
    fraction temp(other);
    *this = temp;
    return *this;
}

complexNumber& complexNumber::operator=(const fraction &other)
{    
    num = other.getNum();
    denom = other.getDenom();

    imaginary = 0;
    return *this;
}

complexNumber& complexNumber::operator=(const int &other)
{
    fraction temp(other);
    *this = temp;
    return * this;
}

complexNumber& complexNumber::operator=(const double &other)
{
    fraction temp(other);
    *this = temp;
    return * this;
}

void complexNumber::copy(const complexNumber &other)
{
    num = other.num;
    denom = other.denom;

    imaginary = other.imaginary;
}

void complexNumber::nukeEveryone()
{
    imaginary = 0;
}

mixedNumber complexNumber::getReal() const
{
    mixedNumber temp(0, num, denom);
    return temp;
}

mixedNumber complexNumber::getImaginary() const
{
    return imaginary;
}

void complexNumber::setValue(const mixedNumber realPart, const mixedNumber imaginaryPart)
{
    *this = realPart;
    imaginary = imaginaryPart;
}

complexNumber complexNumber::conjugate() const
{
    complexNumber temp;
    temp.setValue(this->getReal(), this->getImaginary());
    temp.imaginary *= -1;

    return temp;
}

mixedNumber complexNumber::magnitude()
{
    mixedNumber temp, temp2, square, magnitude;
    mixedNumber a,b,c;

    temp = *this;
    temp2 = imaginary;

//    std::cout << "Temp: " << temp << std::endl;
//    std::cout << "Temp2: " << temp2 << std::endl;

    a = temp^2;
    b= temp2^2;

//    std::cout << a << std::endl;
//    std::cout << b << std::endl;

    square = a + b;

//    std::cout << "The square is " << square<< std::endl;

    magnitude = square.squareRoot();

    return magnitude;
}
void complexNumber::setReal(const mixedNumber &a)
{
    num = a.getNum();
    denom = a.getDenom();
}
