#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include "mixednumber.h"
#include <complex>
#include <cmath>
#include <iomanip>

enum complexERRORS{INVALIDCOMPLEX, INVALIDTYPE};

class complexNumber : public mixedNumber
{
    public:
        complexNumber();
        ~complexNumber();
        complexNumber(const mixedNumber &realPart, const mixedNumber &imaginaryPart = 0);
        complexNumber(const double &realPart, const double &imaginaryPart = 0);
        complexNumber(const int &realPart, const int &imaginaryPart = 0);
        complexNumber(const complexNumber &other);
        complexNumber(const complexNumber &mag, const complexNumber &rad);

        mixedNumber getReal() const;
        mixedNumber getImaginary() const;
        mixedNumber magnitude() const;
        mixedNumber angle() const;
        complexNumber conjugate() const;

        void setValue(const mixedNumber realPart, const mixedNumber imaginaryPart);
        void setReal(const mixedNumber &a);
        void setReal(const double &d);
        void setReal(const int &i);

        void polarForm() const;

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
