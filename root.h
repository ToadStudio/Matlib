#ifndef MATLIB_ROOT_H
#define MATLIB_ROOT_H

#include "general.h"
#include <vector>
#include <cmath>
#include <iostream>
using std::vector;

class Root {
public:
    Root(int coefficient, unsigned int index, unsigned int radicand);
    Root(unsigned int radicand);
    int index();
    int coefficient();
    int radicand();
    void print();
    void simplify();
    double toDouble();

private:
    unsigned int _index;
    int _coefficient;
    unsigned int _radicand;
};


#endif //MATLIB_ROOT_H
