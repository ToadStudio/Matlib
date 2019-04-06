#ifndef MATLIB_FRACTION_H
#define MATLIB_FRACTION_H

#include "general.h"
#include <iostream>
#include <cmath>

class Fraction
{
public:
    Fraction(int numerator, int denominator);
    int denominator() const;
    int numerator() const;
    void print();
    static Fraction Parse(double num);
    void reduce();
    double toDouble();

    static Fraction Inverse(Fraction f);

    bool operator==(const Fraction &f) const;
    bool operator==(const double &d) const;
    bool operator!=(const Fraction &f) const;
    bool operator!=(const double &d) const;

    Fraction operator+(const Fraction &f) const;
    Fraction operator+(const double &d) const;
    Fraction operator-(const Fraction &f) const;
    Fraction operator-(const double &d) const;

    Fraction operator*(const Fraction &f) const;
    Fraction operator*(const double &d) const;
    Fraction operator/(const Fraction &f) const;
    Fraction operator/(const double &d) const;


private:
    int _numerator;
    int _denominator;
};


#endif //MATLIB_FRACTION_H
