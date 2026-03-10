#include "Complex.hpp"
#include <iostream>

Complex::Complex(double r, double i) : real(r), imag(i) {}

Complex Complex::add(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex Complex::multiply(const Complex& c1, const Complex& c2) {
    // (a+bi)(c+di) = (ac - bd) + (ad + bc)i
    double r = c1.real * c2.real - c1.imag * c2.imag;
    double i = c1.real * c2.imag + c1.imag * c2.real;
    return Complex(r, i);
}

Complex Complex::conjugate() const {
    return Complex(real, -imag);
}

void Complex::print() const {
    std::cout << real << (imag >= 0 ? " + " : " - ") << (imag >= 0 ? imag : -imag) << "i" << std::endl;
}
