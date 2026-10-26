#include <catch2/catch_test_macros.hpp>
#include "Fraction.h"

TEST_CASE("Fraction addition", "[fraction]")
{
    SECTION("Simple addition with same denominator")
    {
        Fraction a(1, 4);
        Fraction b(1, 4);
        Fraction result = a.add(b);

        // Проверяем числитель и знаменатель результата
        REQUIRE(result.print() == "¹⁄₂");
    }

    SECTION("Addition with different denominators")
    {
        Fraction a(1, 2);
        Fraction b(1, 4);
        Fraction result = a.add(b);

        REQUIRE(result.print() == "³⁄₄"); // 1/2 + 1/4 = (1*4 + 1*2)/8 = 6/8
    }

    SECTION("Проверка сложения с целыми числами")
    {
        Fraction a(1, 2);
        REQUIRE(a.add(2).print() == "2¹⁄₂");
    }

    SECTION("Проверка сложения дроби с двузначным знаменателем")
    {
        Fraction a(5, 15);
        Fraction b(9, 15);
        REQUIRE(a.add(b).print() == "¹⁴⁄₁₅");
    }
}

TEST_CASE("Fraction substraction", "[fraction]")
{
    Fraction a(3, 4);
    Fraction b(1, 2);
    SECTION("Проверка вычитания")
    {
        REQUIRE(a.substract(b).print() == "¹⁄₄");
    }

    SECTION("Проверка отрицательных значений")
    {
        REQUIRE(b.substract(a).print() == "-¹⁄₄");
    }

    SECTION("Проверка перегрузки операторов")
    {
        Fraction c = a - b;
        REQUIRE(c.print() == "¹⁄₄");
    }

     SECTION("Проверка нуля")
     {
        Fraction a(1, 4);
        Fraction b(1, 4);
        Fraction c = a - b;
        REQUIRE(c.print() == "0");
     }
}

TEST_CASE("Fraction printing", "[fraction]")
{
    Fraction f(3, 5);
    REQUIRE(f.print() == "³⁄₅");
}