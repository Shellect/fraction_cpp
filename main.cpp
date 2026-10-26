#include "Fraction.h"

#include <iostream>


int main()
{
    Fraction half(1, 2);
    Fraction quarter(1, 4);
    Fraction result = half.add(quarter);
    std::cout << result.print();

    return 0;
}