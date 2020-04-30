#include "doctest.h"
#include <iostream>
#include <complex>
#include "solver.hpp"
using namespace std;
using namespace solver;



TEST_CASE(" linear real equation ") {
    RealVariable x;
            CHECK(solve(5 * x == 0) == 0);
            CHECK(solve(2 + x == 4 - x) == 1);
            CHECK(solve(-1 + x == x - 1 + x) == 0);
            CHECK(solve(x - x == x + 2) == -2);
            CHECK(solve(3 * (-x - 7) + 1 == 8 * x) == 2);
            CHECK(solve(2 * (x + 3) == 8 * (2 * x - 6)) + 12 == 3);
            CHECK(solve(8 * x - 5 * x == -6) == -2);
            CHECK(solve(23.4 * x + 234.54 == 53.54 + 435.4 * x) == 0.4393204);
            CHECK(solve(12 + 5.1 * x == 5 * x + 2) == -100.0);
            CHECK(solve(3 * x + 4 == x / 3) == -1.5);
            CHECK(solve(x == 0.5 * x) == 0);
            CHECK(solve(23 * x + 1 == 3 * x - 1) == -0.1);
            CHECK(solve(34 * x / 1.55 - 5 == 20 * x) == 2.5833333333);
            CHECK(solve(12.5 + 2.0 * x / 0.5 == 41 - 5.5 * x / 5) == 2.567567568);
            CHECK(solve(-2 * x + 5 == 4 * x - 1.6) == 1.1);
            CHECK(solve(1.23 * x - 8.4 == -0.77 * x) == 4.2);
            CHECK(solve(2 * x - 1 == -3 * x + 5) == 1.2);
    CHECK_THROWS(solve((x ^ 2) == -17));
    CHECK_THROWS(solve((x ^ 2) == -1999));
    CHECK_THROWS(solve((x ^ 2) == -7867));
    CHECK_THROWS(solve((x ^ 2) == -6776));
    CHECK_THROWS(solve((x ^ 2) == -100.0082));
    CHECK_THROWS(solve((x ^ 2) == -4333.0537));
    CHECK_THROWS(solve((x ^ 2) == -56124.7502));
    CHECK_THROWS(solve((x ^ 2) == -144455));
    CHECK_THROWS(solve((x ^ 2) == -1119));
    CHECK_THROWS(solve((x ^ 2) == -1743));
    CHECK_THROWS(solve((x ^ 2) == -120500));
    CHECK_THROWS(solve((x ^ 2) == -16.1198));
            CHECK(solve(x ^ 2 - 3 * x == -2) == 1);
            CHECK(solve(((x + 1) ^ 2) + (x + 1) == 0) == -1);
            CHECK(solve(2 * x + 7 - 5 * x - 12 == -8 * x + 3) == 8 / 5);
            CHECK(solve(((1 - 2 * x) ^ 2) == (2 * x - 1)) == 0.5);
            CHECK(solve(x + 2 * x / 4 == 0) == 0);
            CHECK(
            (solve((2 * (x ^ 2) + x) * 2 == 0) == double(0) || (solve((2 * (x ^ 2) + x) * 3 == 0) == double(-1))));
            CHECK(solve(5 * x * 5 == 50) == double(2));
            CHECK((solve((x ^ 2) * 9 == 81) == double(-3) || (solve((x ^ 2) * 9 == 81) == double(3))));
            CHECK(solve(6 * x + 3 * 4 == 0) == double(-2));
            CHECK(solve(16 * x - 4 * 3 * x == 12) == double(3));
            CHECK(solve(4 * x - 5 * x == (x + 30) * 2) == double(-20));
            CHECK(solve(6 * x - 5 * x == 7) == double(7));
            CHECK(solve(6 * x * 0 + 5 * x == 25) == double(5));
            CHECK(solve(6 * x * 0 + 5 * x == 25 * 0) == double(0));
            CHECK(
            (solve((2 * (x ^ 2) + x) * 2 == 0) == double(0) || (solve((2 * (x ^ 2) + x) * 3 == 0) == double(-1))));

    ComplexVariable y;
            CHECK(solve((x + 1i) ^ 2 == 15 + 8i) == 4.0);
            CHECK(solve((x + 1i) ^ 1 == 2 * x - 1i) == 2i);
            CHECK(solve((x ^ 2) == -16) == 4i);
            CHECK(solve(x * x == (x ^ 2) + x) == 0.0);
            CHECK(solve((5 * x + 5i) / (3 + 4i) == 2 - 1i) == 2.0);
            CHECK(solve((x + 1i) / (1i + x) == x) == 1.0);
            CHECK(solve((1 / x) == 0.5) == 2.0);
    CHECK_THROWS(solve((x + 1i) / (2 * x + 2i) == 1));
    CHECK_THROWS(solve((x + 2i) / 0 == 0));
            CHECK(solve(5 + 12.2 * y == 4i) == 0.4098 + 0.3278i);
            CHECK(solve(y / 3 - 1i == 2 * y + 12) == 7.0344 - 0.4137i);
            CHECK(solve(y + 4 == 3i + 2.0) == -2.0 + 3i);
            CHECK(solve(y + 3 + 3i == 24 * y + 1i + 0.5) == 0.1086 + 0.0869i);
            CHECK(solve(y == 0.0714i) == 0.0714i);
            CHECK(solve(y + 1i == -25) == -25.0 - 1i);
            CHECK(solve(12i == 5 * y / 2) == 4.8i);
            CHECK(solve(8i - y == 21 * y) == 0.3636i);
            CHECK(solve(1i - y + 10 == 2.0 - 4i) == 8.0 + 5i);
            CHECK(solve(3 * y == 15.0 + 1i) == 5.0 + 0.3333i);
            CHECK((solve((y ^ 2) == -98) == std::complex<double>(0, 9.8994) ||
                   solve((y ^ 2) == -98) == std::complex<double>(0, -9.8994)));
            CHECK((solve((y ^ 2) == -1000) == std::complex<double>(0, 31.6227) ||
                   solve((y ^ 2) == -1000) == std::complex<double>(0, -31.6227)));
            CHECK((solve((y ^ 2) == -9.9990) == std::complex<double>(0, 3.1621) ||
                   solve((y ^ 2) == -9.9990) == std::complex<double>(0, -3.1621)));
            CHECK((solve((y ^ 2) + 196 == -12345.678) == std::complex<double>(0, 111.9896) ||
                   solve((y ^ 2) + 196 == -12345.678) == std::complex<double>(0, -111.9896)));
            CHECK((solve((y ^ 2) + 0.5 == 0) == std::complex<double>(0, 0.7071) ||
                   solve((y ^ 2) + 0.5 == 0) == std::complex<double>(0, -0.7071)));
            CHECK((solve((y ^ 2) + 1997 == 0) == std::complex<double>(0, 44.6878) ||
                   solve((y ^ 2) + 1997 == 0) == std::complex<double>(0, -44.6878)));
            CHECK((solve((y ^ 2) + y + 1 == 0) == std::complex<double>(-0.5, 0.8660) ||
                   solve((y ^ 2) + y + 1 == 0) == std::complex<double>(-0.5, -0.8660)));
            CHECK((solve((2 * y ^ 2) + 3 * y + 2 == 0) == std::complex<double>(-0.75, -0.6614) ||
                   solve((2 * y ^ 2) + 3 * y + 1 == 0) == std::complex<double>(-0.75, 0.6614)));
            CHECK((solve((12 * y ^ 2) + 63 * y == -5) == std::complex<double>(-0.0806, 0) ||
                   solve((12 * y ^ 2) + 63 * y == -5) == std::complex<double>(-5.1693, 0)));
            CHECK((solve(3 * y - 8 == y - 3) == std::complex<double>(2.5, 0)));
    CHECK_THROWS(solve((y ^ 6) + (y ^ 5) + 8i == 0));
    CHECK_THROWS(solve((4 * y ^ 6) + (4 * y ^ 5) + 34 == 2000));
    CHECK_THROWS(solve((y ^ 4) == -64));
    CHECK_THROWS(solve((y ^ 5) + (y ^ 2) == 67i));
    CHECK_THROWS(solve((y ^ 10) == 100));
    CHECK_THROWS(solve((y ^ 2) / 0 * 7i == 0));
    CHECK_THROWS(solve((y ^ 2) / 0 == -100));
    CHECK_THROWS(solve((y ^ 70) == -64));
            CHECK((solve(4 * y - 7.5 == y - 3) == std::complex<double>(1.5, 0)));
            CHECK((solve(3 * y - 6 == y - 3) == std::complex<double>(1.5, 0)));
            CHECK((solve(3 * y - 18 == y - 3) == std::complex<double>(7.5, 0)));
            CHECK((solve(3 * y == y - 3) == std::complex<double>(-1.5, 0)));
            CHECK(solve((x ^ 2) + 5 * x + 6i == 5 * x + 6i) == std::complex<double>(0.0, 0.0));
            CHECK(solve(40 * x - 10i == 10 * x - 40i) == std::complex<double>(-0, -1));
            CHECK(solve(2 * x + 3i == 4 * x - 7i) == std::complex<double>(0.0, 5.0));
            CHECK(solve(3 * (x ^ 2) / 3 == 0) == std::complex<double>(0.0, 0.0));
            CHECK(solve((24 * x + 12i) / 2 == 0i) == std::complex<double>(-0.0, -0.5));
            CHECK(solve(10 * x + 3i == 9 * x + 3i) == std::complex<double>(0.0, 0.0));
            CHECK(solve(20 * x + 101i == 10 * x + 1i) == std::complex<double>(0.0, -10.0));
            CHECK(solve((x ^ 2) + 3 * x + 3i == 3 * x + 3i) == std::complex<double>(0.0, 0.0));
}