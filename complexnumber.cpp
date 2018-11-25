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

complexNumber::complexNumber(mixedNumber realPart, mixedNumber imaginaryPart)
{
    num = realPart.getNum();
    denom = realPart.getDenom();

    imaginary = imaginaryPart;
}

complexNumber& complexNumber::operator=(const mixedNumber &other)
{ // This creates a temp fraction because a mixedNumber can be constructed from its fraction constituents.
    fraction temp(other);
    *this = temp;
    return * this;
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
