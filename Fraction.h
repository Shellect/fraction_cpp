#include <string>

class Fraction
{
private:
    int numerator;   // числитель
    int denominator; // знаменатель

    std::string upperIndex[10]{"⁰", "¹", "²", "³", "⁴", "⁵", "⁶", "⁷", "⁸", "⁹"};
    std::string lowerIndex[10]{"₀", "₁", "₂", "₃", "₄", "₅", "₆", "₇", "₈", "₉"};

    int gcd(int a, int b); // НОД
    void simplifying();

public:
    Fraction(int numerator, int denominator);
    ~Fraction();

    // Методы

    Fraction add(const Fraction &other);
    Fraction add(int other);

    Fraction substract(const Fraction &other);
    Fraction substract(int other);

    // Операторы

    Fraction operator+(const Fraction &other) const;
    Fraction operator+(int other) const;

    Fraction operator-(const Fraction &other) const;
    Fraction operator-(int other) const;

    std::string print();
};
