#include "Fraction.h"

#include <sstream>
#include <string>
#include <cstdlib>

int Fraction::gcd(int a, int b)
{
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a == 0 ? 1 : a;
}

void Fraction::simplifying()
{
    int divider = gcd(numerator, denominator);
    numerator /= divider;
    denominator /= divider;
}

Fraction::Fraction(int n, int d) : numerator(n), denominator(d)
{
    if (denominator == 0)
        throw std::invalid_argument("denominator == 0");
    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
    simplifying();
}
Fraction::~Fraction() {}

Fraction Fraction::add(const Fraction &other)
{
    return *this + other;
}

Fraction Fraction::add(int other)
{
    return *this + other;
}

Fraction Fraction::substract(const Fraction &other)
{
    return *this - other;
}

Fraction Fraction::substract(int other)
{
    return *this - other;
}

//--------------- Операторы -------------------------------

Fraction Fraction::operator+(const Fraction &other) const
{
    // 1/2 + 1/4 = ?
    // (1 * 4 + 1 * 2)/ 4 * 2 = ?
    int newNumerator = numerator * other.denominator + other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    return Fraction{newNumerator, newDenominator};
}

Fraction Fraction::operator+(int other) const
{
    return Fraction{numerator + other * denominator, denominator};
}

Fraction Fraction::operator-(const Fraction &other) const
{
    int newNumerator = numerator * other.denominator - other.numerator * denominator;
    int newDenominator = denominator * other.denominator;
    return Fraction{newNumerator, newDenominator};
}

Fraction Fraction::operator-(int other) const
{
    return Fraction{numerator - other * denominator, denominator};
}

std::string Fraction::print()
{
    std::ostringstream oss;
    // Выводим знак
    if (numerator < 0)
    {
        oss << "-";
    }

    // Выводим целую часть
    int integerPart = numerator / denominator;
    if (integerPart != 0)
        oss << integerPart;
    if (numerator == 0)
    {
        oss << '0';
        return oss.str();
    }

    // Выводим числитель
    int rem = std::abs(numerator) % denominator;
    if (rem != 0 || integerPart == 0)
    {
        for (const char c : std::to_string(rem))
            oss << upperIndex[c - '0'];

        // Выводим разделитель
        oss << "⁄";

        // Выводим знаменатель
        for (const char c : std::to_string(denominator))
            oss << lowerIndex[c - '0'];
    }
    return oss.str();
}
