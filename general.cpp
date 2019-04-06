#include "general.h"

int General::GetDigits(double d)
{
    int n = 0;
    char s[100];
    std::sprintf(s,"%lf", d);
    int l = std::strlen(s);
    bool isDotFound = false;
    for (int i = 0; i < l; i++)
    {
        if (s[i] != '.' && !isDotFound)
        {
            continue;
        }
        if (s[i] == '.')
        {
            isDotFound = true;
            continue;
        }
        if (s[i] == '0')
        {
            bool isEnd = true;
            for (int j = i; j < l; j++)
            {
                if (s[j] != '0')
                {
                    isEnd = false;
                    break;
                }
            }
            if (isEnd)
            {
                break;
            }
        }
        n++;
    }
    return n;
}

long long General::Power(int a, int b)
{
    int ans = 1,base = a;
    while (b != 0)
    {
        if (b & 1)
            ans *= base;
        base *= base;
        b >>= 1;
    }
    return ans;
}

int General::GCD(int x, int y)
{
    bool LowerThanZero = false;
    if ((x < 0  && y > 0) || (x > 0) && (y < 0))
    {
        LowerThanZero = true;
        x = std::abs(x);
        y = std::abs(y);
    }
    unsigned int factor = 0;
    unsigned int temp;
    if ( x < y )
    {
        temp = x;
        x = y;
        y = temp;
    }
    if (0 == y)
        return 0;
    while (x != y)
    {
        if (x & 0x1)
        {
            if (y & 0x1)
            {
                y = (x - y) >> 1;
                x -= y;
            }
            else
            {
                y >>= 1;
            }
        }
        else
        {
            if (y & 0x1)
            {
                x >>= 1;
                if (x < y)
                {
                    temp = x;
                    x = y;
                    y = temp;
                }
            }
            else
            {
                x >>= 1;
                y >>= 1;
                ++factor;
            }
        }
    }
    return LowerThanZero ? -(x << factor) : (x << factor);
}

int General::LCM(int ad, int bd)
{
    return ad * bd / GCD(ad, bd) * (ad > bd ? ad : bd);
}

bool General::isPrime(long long n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= (int)sqrt((double) n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void General::GetPrime(int n, std::vector<int> &primes)
{

    if (isPrime(n)) {

        primes.push_back(n);
        return;
    }

    int k = 2;
    while (k <= (int) sqrt((double) n)) {

        if (n % k == 0) {

            if (isPrime(k)) {

                primes.push_back(k);
            } else {

                GetPrime(k, primes);
            }

            int j = n / k;

            if (isPrime(j)) {

                primes.push_back(j);
            } else {
                GetPrime(j, primes);
            }

            return;
        }

        k++;
    }
}