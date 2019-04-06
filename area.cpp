#include "area.h"

long double Area::Circle(long double r)
{
    return M_PI * r * r;
}

long double Area::Rectangle(long double a, long double b)
{
    return a * b;
}

long double Area::Parallelogram(long double a, long double h)
{
    return a * h;
}

long double Area::Triangle(long double a, long double h)
{
    return a * h / 2;
}

long double Area::Trapezoid(long double a, long double b, long double h)
{
    return (a + b) * h / 2;
}