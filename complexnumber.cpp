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

mixedNumber complexNumber::magnitude() const
{
    mixedNumber temp = this->getReal(), temp2 = imaginary, magnitude;

    magnitude = (temp^2) + (temp2^2);
    magnitude = magnitude.squareRoot();
    return magnitude;
}
void complexNumber::setReal(const mixedNumber &a)
{
    num = a.getNum();
    denom = a.getDenom();
}

void complexNumber::setReal(const double &d)
{
    mixedNumber temp(d);
    setReal(temp);
}

void complexNumber::setReal(const int &i)
{
    mixedNumber temp(i);
    setReal(temp);
}

void complexNumber::polarForm() const
{
    using namespace std;
    complexNumber theta;

    theta = imaginary/this->getReal();

    cout << '(' << this->magnitude() << "," << atan(theta.getDouble()) << ')' << endl;
}


