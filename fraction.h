#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>

enum fraction_ERRORS {DivByZero, Invalid_Type};

class fraction
{
    public:

        fraction();

        fraction(int n, int d = 1);

        ~fraction();

        fraction(const fraction &fraction);

        fraction(const double &other);

        fraction& operator=(const fraction &fraction);
        fraction& operator+=(const fraction &fraction);
        fraction& operator-=(const fraction &fraction);
        fraction& operator*=(const fraction &fraction);
        fraction& operator/=(const fraction &fraction);

        int getNum() const; //accessor function for numerator
        int getDenom() const;//accessor function for denominator
        void setValue(int n, int d = 1); //mutator function
        void display();
        void getInput();

        friend
        std::ostream& operator<<(std::ostream& out, const fraction &frac);

        friend
        std::istream& operator>>(std::istream& out, fraction &frac);

        friend
        fraction operator+(const fraction &x,const fraction &y);

        friend
        fraction operator-(const fraction &x,const fraction &y);

        friend
        fraction operator*(const fraction &x,const fraction &y);

        friend
        fraction operator^(const fraction &x,const fraction &y);

        friend
        fraction operator/(const fraction &x,const fraction &y);

        friend
        bool operator==(const fraction &x,const fraction &y);

        friend
        bool operator>=(const fraction &x,const fraction &y);

        friend
        bool operator<=(const fraction &x,const fraction &y);

        friend
        bool operator!=(const fraction &x,const fraction &y);

        friend
        bool operator<(const fraction &x,const fraction &y);

        friend
        bool operator>(const fraction &x,const fraction &y);

    protected:
        int num, denom;

    private:
        void reduce();
        int gcd(int p, int q);

        bool allDecimalsTheSame(const std::string &fracPart);
        int makeDenom(int digits, bool same);
};

#endif // FRACTION_H
