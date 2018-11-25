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

complexNumber::complexNumber(mixedNumber realPart, mixedNumber imaginaryPart)
{
    num = realPart.getNum();
    denom = realPart.getDenom();

    imaginary = imaginaryPart;
}

//complexNumber& complexNumber::operator=(const complexNumber &other)
//{
//    if(this != &other)
//        copy(other);
//    return *this;
//}
//complexNumber& complexNumber::operator=(const mixedNumber &other)
//{
//    if(this != &other)
//        copy(other);
//    return *this;
//}
//complexNumber& complexNumber::operator=(const fraction &other)
//{
//    if(this != &other)
//        copy(other);
//    return *this;
//}
//complexNumber& complexNumber::operator=(const int &other)
//{
//    if(this != &other)
//        copy(other);
//    return *this;
//}
//complexNumber& complexNumber::operator=(const double &other)
//{
//    if(this != &other)
//        copy(other);
//    return *this;
//}

std::ostream& operator<<(std::ostream &out, complexNumber&c)
{
    mixedNumber real = c.num/c.denom, imaginaryPart = c.imaginary;

    out << real << " + " << imaginaryPart << "i";

    return out;
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
