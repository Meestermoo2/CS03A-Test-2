#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include "mixednumber.h"

class complexNumber : public mixedNumber
{
    public:

        complexNumber();
        ~complexNumber();
        complexNumber(mixedNumber realPart, mixedNumber imaginaryPart);
        complexNumber(const complexNumber &other);

        mixedNumber getReal() const;
        mixedNumber getImaginary() const;

        void setValue(mixedNumber realPart, mixedNumber imaginaryPart);
        complexNumber conjugate();

        complexNumber& operator=(const complexNumber &other);
        complexNumber& operator=(const mixedNumber &other);
        complexNumber& operator=(const fraction &other);
        complexNumber& operator=(const double &other);
        complexNumber& operator=(const int &other);

        friend
        complexNumber operator+(const complexNumber &x, const complexNumber &y);

        friend
        complexNumber operator-(const complexNumber &x, const complexNumber &y);

        friend
        complexNumber operator*(const complexNumber &x, const complexNumber &y);

        friend
        complexNumber operator/(const complexNumber &x, const complexNumber &y);

        friend
        complexNumber operator^(const complexNumber &x, const complexNumber &y);

        friend
        std::istream& operator>>(std::istream &in, complexNumber&c);

        friend
        std::ostream& operator<<(std::ostream &out, complexNumber&c);



    private:

        mixedNumber imaginary;
        void copy(const complexNumber &other);
        void nukeEveryone();

};

#endif // COMPLEXNUMBER_H
