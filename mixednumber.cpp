#include "mixednumber.h"

mixedNumber::mixedNumber()
{
}

mixedNumber::~mixedNumber()
{
    nukeEveryone();
}

mixedNumber::mixedNumber(int w, int n, int d)
{
    setValues(w,n,d);
}
//Fix for taking in double to mixed number
mixedNumber::mixedNumber(const double &other)
{
    //converts it to temp
    fraction temp(other);
    //sets the value of mixed number to temp
    *this = temp;
}

mixedNumber::mixedNumber(const mixedNumber &other)
{
    copy(other);
}

mixedNumber& mixedNumber::operator=(const mixedNumber &other)
{
    if(this != &other)
       copy(other);
    return *this;
}


mixedNumber& mixedNumber::operator=(const fraction &other)
{
    num = other.getNum();
    denom = other.getDenom();
    return *this;
}


mixedNumber& mixedNumber::operator=(const int &other)
{
    fraction temp(other);
    *this = temp;
    return *this;
}

mixedNumber& mixedNumber::operator=(const double &other)
{
    fraction temp(other);
    *this = temp;
    return *this;
}

void mixedNumber::getValues(int &w, int &n, int &d)
{
    w = num/denom;
    n = num%denom;
    d = denom;
}

void mixedNumber::setValues(int w, int n, int d)
{
    if (w < 0)
        d *= -1;
    fraction::setValue(w*d + n, d);
}

void mixedNumber::copy(const mixedNumber &other)
{
    num = other.num;
    denom = other.denom;
}

void mixedNumber::nukeEveryone()
{
    num = 0;
    denom = 1;
}

