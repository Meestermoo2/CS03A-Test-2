#include "fraction.h"

fraction::fraction()
{
    num = 0;
    denom = 1;
}

fraction::fraction(int n, int d)
{
   setValue(n,d);
}

fraction::~fraction()
{
    num = denom = 0;
}

fraction::fraction(const fraction &frac)
{
    num = frac.num;
    denom = frac.denom;
}

fraction::fraction(const double &other)
{   //Turns double into a string, which is divided into two parts (whole.fraction)
    std::string wholePart, fractionPart;
    std::stringstream ss;

    ss<<other;
    // This operation turns the double into a string
    getline(ss, wholePart,'.');
    // This takes the first 'part' of the string delimited by the period

    getline(ss,fractionPart);
    // This takes in the rest of the double following the decimal

    int numDigits = fractionPart.size();
    // This is to keep track of fraction's size, used for iterating through the fractionPart string in the makeDenom method
    if(fractionPart == "")
            fractionPart += '0';
    // This is required because when a decimal such as "3.0" is inserted into string stream, it evaluates it says "3" instead, causing an empty string.

    denom = makeDenom(numDigits, allDecimalsTheSame(fractionPart));

    // This will convert repeating decimals and non repeating decimals into an denominator (as an int).
    num = (denom * abs(std::stoi(wholePart))) + abs(std::stoi(fractionPart));
    // 1.5 -> 1 whole part
    //      -> 5 fraction part
    // We get 10 as the denom (based on makeDenom)
    // And we take the whole part and multiply it by the denom.
    // We add the remaining fraction on top of the numerator (from fractionPart)

    reduce(); // Simplifies the fraction

    if (wholePart[0] == '-') // Negates the fraction, if applicable
        num *= -1;

}

bool fraction::allDecimalsTheSame(const std::string &fracPart)
{
    if(fracPart.size() < 3) // This will account for single digit parts (e.g .1 is not repeating)
                return false;

    bool yes = true;
    for(int i = 1; yes && i < fracPart.size(); ++i)
        yes = (fracPart[0] == fracPart[i]);
    return yes;
}

int fraction::makeDenom(int digits, bool same)
{
    std::string result("1");
    for(int i = 0; i < digits; ++i)
        result += "0";
    return (std::stoi(result) - static_cast<int>(same));
    // If we have a repeating decimal, we typically divide by 9 to get the denominator.
    // This logic allows us to subtract from the power of 10 if this is the case.
    // e.g. (.222..) can be converted to 2/9
    // If we have a non repeating decimal, we simply divide by a power of 10 to get the denominator.
    // e.g. (.30) can be converted to 3/10. We get a power of 10 (depending on number of digits in decimal)
    // e.g. (.3213) can be converted to 3213/10000
}

fraction& fraction::operator=(const fraction &frac)
{
    if(this != &frac)
    {
        num = frac.num;
        denom = frac.denom;
    }
    return *this;
}

fraction& fraction::operator+=(const fraction &other)
{
    *this = *this + other;
    return *this;
}

fraction& fraction::operator-=(const fraction &other)
{
    *this = *this - other;
    return *this;
}

fraction& fraction::operator*=(const fraction &other)
{
    *this = *this * other;
    return *this;
}

fraction& fraction::operator/=(const fraction &other)
{
    *this = *this / other;
    return *this;
}


int fraction::getNum() const //accessor function for numerator
{
    return num;
}

int fraction::getDenom() const//accessor function for denominator
{
    return denom;
}

void fraction::setValue(int n, int d) //mutator function
{
    num = n;
    denom = d;
    if (!denom)
        throw DivByZero;
    reduce();
}

void fraction::display()
{
    std::cout<<" "<<num;
    if(denom != 1)
       std::cout<<"/"<<denom<<" ";
}


void fraction::getInput()
{
    char junk;
    std::cin>>num>>junk>>denom;
    reduce();
}


void fraction::reduce()
{
    bool neg = num < 0 || denom < 0,
         both = num < 0 && denom < 0;
    int divisor = gcd(abs(num), abs(denom));
    num = abs(num) / divisor;
    denom = abs(denom) / divisor;
    if(!both) //Asking is both == false
        if(neg)
            num *= -1;
}

int fraction::gcd(int p, int q)
{
   return !q ? p : gcd(q, p%q);  //!q is the same as asking q == 0;
}


