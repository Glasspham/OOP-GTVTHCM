#pragma once
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;
class Fraction {
private:
	int numerator, denominator;
public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(int random);

    void simplify();
    float toFloat() const;
    friend ostream& operator << (ostream& os, Fraction f);

    Fraction operator + (const Fraction& other) const;
    Fraction operator - (const Fraction& other) const;
    Fraction operator * (const Fraction& other) const;
};
#endif