# Matlib

A lightweight, simple math library written in C++.

![](https://img.shields.io/badge/version-Alpha%200.0.1-red.svg) [![](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/ToadStudio/Matlib/blob/master/LICENSE)
-----
## Initialization

First, clone this repo:

```
git clone https://github.com/toadstudio/Matlib
```

And at the beginning of the CPP file, add the sentence:

```
#include "matlib.h"
```

Enjoy!

## Requirement

Any C++ compiler supports `C++ 98` or higher standard.

Matlib is compatible with `Windows` or `Unix-like` operating systems.

## Usage

The Matlib includes many parts of Classes:

#### Fraction

This class is used for operating fractions instead of decimals.

Use `Fraction fraction_name(numerator, denominator)` to initialize a fraction. The numerator and denominator must be integers. Or use `Fraction fraction_name = Fraction::Parse(decimal_name)` to generate a fraction from a decimal (or from an integer). The fraction will be generated to an irreducible fraction automatically.

Use `fraction_name.print()` to print a fraction instead of using std functions. The symbol of the fraction will be processed.

Use `fraction_name.reduce()` to reduce the fraction.

In other cases, use standard operators to calculate.

P.S. A fraction cannot be mdified manually. Use `fraction_name.numerator` or `fraction_name.denominator` to get the numerator or denominator of the fraction.

#### General

This class includes many general functions that are not included in the `cmath` header or those defined in `cmath` are inefficient.

`int General::GCD(int x, int y)` Calculating the greatest common divisor of x and y with `Stein Algorithm`.

`int General::GetDigits(double d)` Getting the number of digits after the decimal point.

`long long General::Power(int a, int b)` Calculating the result of $ a^b $.

`int General::LCM(int x, int y)` Calculating the lowest common multiple.

P.S. All functions defined in this class are static.

## License

The Matlib uses the [MIT License](https://github.com/ToadStudio/Matlib/blob/master/LICENSE).
