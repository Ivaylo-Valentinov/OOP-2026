#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0);
    static Complex add(const Complex& c1, const Complex& c2);
    static Complex multiply(const Complex& c1, const Complex& c2);
    Complex conjugate() const;
    void print() const;
};

#endif
