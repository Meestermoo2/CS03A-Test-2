#include "complexnumber.h"

complexNumber::complexNumber()
{
}

complexNumber::~complexNumber()
{
    nukeEveryone();
}

complexNumber::complexNumber(const complexNumber &other)
{
    copy(other);
}

//complexNumber::complexNumber(mixedNumber real, mixedNumber imaginary)
//{
//    num = real.num;
//    denom = real.denom;
//}

complexNumber& complexNumber::operator=(const complexNumber &other)
{
    if(this != &other)
        copy(other);
    return *this;
}
complexNumber& complexNumber::operator=(const mixedNumber &other)
{
    if(this != &other)
        copy(other);
    return *this;
}
complexNumber& complexNumber::operator=(const fraction &other)
{
    if(this != &other)
        copy(other);
    return *this;
}
complexNumber& complexNumber::operator=(const int &other)
{
    if(this != &other)
        copy(other);
    return *this;
}
complexNumber& complexNumber::operator=(const double &other)
{
    if(this != &other)
        copy(other);
    return *this;
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
