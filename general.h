#ifndef MATLIB_GENERAL_H
#define MATLIB_GENERAL_H

#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>

class General
{
public:
    static int GetDigits(double d);
    static long long Power(int a, int b);
    static int GCD(int x, int y);
    static int LCM(int ad, int bd);
    static bool isPrime(long long n);
    static void GetPrime(int n, std::vector<int> &primes);
};


#endif //MATLIB_GENERAL_H
