#include <complex/complex.h>
//#include <doctest/doctest.h>
#include <iostream>

int main() {
    Complex a = Complex(2.5, 5.5);
    Complex b = Complex(3.0, 4.3);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl << std::endl;

    Complex c;
    std::cin >> c;
    std::cout << -c << std::endl;

    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "a / b = " << (a + b)  << std::endl << std::endl;

    std::cout << "(a == b) = " << (a == b) << std::endl << std::endl;

    std::cout << "b + 5.5 = " << (b + 5.5) << std::endl;
    std::cout << "b + 5.5 = " << (5.5 + b) << std::endl;
    std::cout << "b / 2 = " << (b / 2) << std::endl;
    std::cout << "b * 2 = " << (2 * b) << std::endl;
    std::cout << "b * 2 = " << (b * 2) << std::endl;

    return 0;
}