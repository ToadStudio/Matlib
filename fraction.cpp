#include "fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
    _numerator = numerator;
    _denominator = denominator;
    this->reduce();
}

int Fraction::denominator() const
{
    return this->_denominator;
}

int Fraction::numerator() const
{
    return this->_numerator;
}

void Fraction::print()
{
    if (this->denominator() == 0)
    {
        std::cout << "Err: Fraction Invalid!";
    }
    else if (this->numerator() * this->denominator() > 0)
        std::cout << std::abs(this->numerator()) << '/' << std::abs(this->denominator());
    else if (this->numerator() * this->denominator() < 0)
        std::cout << '-' << std::abs(this->numerator()) << '/' << std::abs(this->denominator());
}

Fraction Fraction::Parse(double num)
{
    const int d = General::Power(10, General::GetDigits(num));
    Fraction f(int(num * d), d);
    f.reduce();
    return f;
}

void Fraction::reduce()
{
    int gcd = General::GCD(this->_numerator, this->_denominator);
    this->_numerator /= gcd;
    this->_denominator /= gcd;
    if (this->denominator() < 0)
        this->_denominator *= -1, this->_numerator *= -1;
}

Fraction Fraction::Inverse(Fraction f)
{
    Fraction ret(f.denominator(), f.numerator());
    return ret;
}

double Fraction::toDouble()
{
    return double(this->numerator()) / double(this->denominator());
}

bool Fraction::operator==(const Fraction &f) const
{
    int tg = General::GCD(this->numerator(), this->denominator());
    return (this->denominator() / tg == f.denominator() && this->numerator() / tg == f.numerator());
}

bool Fraction::operator==(const double &d) const
{
    int tg = General::GCD(this->numerator(), this->denominator());
    Fraction f = Parse(d);
    return (this->denominator() / tg == f.denominator() && this->numerator() / tg == f.numerator());
}

bool Fraction::operator!=(const Fraction &f) const
{
    int tg = General::GCD(this->numerator(), this->denominator());
    int fg = General::GCD(f.denominator(), f.numerator());
    return !(this->denominator() / tg == f.denominator() / fg && this->numerator() / tg == f.numerator() / fg);
}

bool Fraction::operator!=(const double &d) const
{
    int tg = General::GCD(this->numerator(), this->denominator());
    Fraction f = Parse(d);
    return !(this->denominator() / tg == f.denominator() && this->numerator() / tg == f.numerator());
}

Fraction Fraction::operator+(const Fraction &f) const
{
    int lcm = General::LCM(this->denominator(), f.denominator());
    int atimes = lcm / this->denominator();
    int ftimes = lcm / f.denominator();
    Fraction res(this->numerator() * atimes + f.numerator() * ftimes, lcm);
    return res;
}

Fraction Fraction::operator+(const double &d) const
{
    Fraction f = Parse(d);
    int lcm = General::LCM(this->denominator(), f.denominator());
    int atimes = lcm / this->denominator();
    int ftimes = lcm / f.denominator();
    Fraction res(this->numerator() * atimes + f.numerator() * ftimes, lcm);
    return res;
}

Fraction Fraction::operator-(const Fraction &f) const
{
    int lcm = General::LCM(this->denominator(), f.denominator());
    int atimes = lcm / this->denominator();
    int ftimes = lcm / f.denominator();
    Fraction res(this->numerator() * atimes - f.numerator() * ftimes, lcm);
    res.reduce();
    return res;
}

Fraction Fraction::operator-(const double &d) const
{
    Fraction f = Parse(d);
    int lcm = General::LCM(this->denominator(), f.denominator());
    int atimes = lcm / this->denominator();
    int ftimes = lcm / f.denominator();
    Fraction res(this->numerator() * atimes - f.numerator() * ftimes, lcm);
    return res;
}

Fraction Fraction::operator*(const Fraction &f) const
{
    int de = this->denominator() * f.denominator();
    int nu = this->numerator() * f.numerator();
    Fraction res(nu, de);
    return res;
}

Fraction Fraction::operator*(const double &d) const
{
    Fraction f = Parse(d);
    int de = this->denominator() * f.denominator();
    int nu = this->numerator() * f.numerator();
    Fraction res(nu, de);
    return res;
}

Fraction Fraction::operator/(const Fraction &f) const
{
    Fraction inv = Inverse(f);
    Fraction ts(this->numerator(), this->denominator());
    Fraction ret = ts * inv;
    return ret;
}

Fraction Fraction::operator/(const double &d) const
{
    Fraction f = Parse(d);
    Fraction inv = Inverse(f);
    Fraction ts(this->numerator(), this->denominator());
    Fraction ret = ts * inv;
    return ret;
}