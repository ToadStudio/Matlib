#include "root.h"

Root::Root(unsigned int radicand)
{
    this->_index = 2;
    this->_coefficient = 1;
    this->_radicand = radicand;
    this->simplify();
}

Root::Root(int coefficient, unsigned int index, unsigned int radicand)
{
    this->_index = index;
    this->_coefficient = coefficient;
    this->_radicand = radicand;
    this->simplify();
}

int Root::coefficient()
{
    return this->_coefficient;
}

int Root::index()
{
    return this->_index;
}

int Root::radicand()
{
    return this->_radicand;
}

void Root::simplify()
{
    double root = std::pow(this->radicand(), 1.0 / this->index());
    if (General::GetDigits(root) == 0)
    {
        this->_coefficient *= int(root);
        this->_radicand = 1;
        this->_index = 1;
        return;
    }

    vector<int> f;
    General::GetPrime(this->radicand(), f);
    unsigned short table[997] = {0};
    for (int i = 0; i < f.size(); i++)
    {
        table[f[i]]++;
    }
    int multi = 1, mod = 1;
    for (int i = 2; i < 998; i++)
    {
        if (table[i] == 0)
            continue;
        multi *= General::Power(i, table[i] / 2);
        if (table[i] % 2 == 0)
        {
            continue;
        }
        mod *= i;
    }
    this->_coefficient *= multi;
    this->_radicand = mod;
}

void Root::print()
{
    if (this->index() == 1)
    {
        std::cout << this->coefficient();
        return;
    }
    if (this->coefficient() != 1)
        std::cout << this->coefficient();
    if (this->index() != 2)
        std::cout << '^' << this->index();
    std::cout << "√(" << this->radicand() << ")";
}

double Root::toDouble()
{
    return double(this->coefficient()) * (std::pow(this->radicand(), 1.0 / this->index()));
}