#ifndef MATLIB_AREA_H
#define MATLIB_AREA_H

#include <cmath>

class Area
{
public:
    static long double Triangle(long double a, long double h);
    static long double Rectangle(long double a, long double b);
    static long double Parallelogram(long double a, long double h);
    static long double Circle(long double r);
    static long double Trapezoid(long double a, long double b, long double h);
};


#endif //MATLIB_AREA_H
