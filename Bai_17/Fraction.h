#pragma once
#include <iostream>
using namespace std;
class Fraction {
private:
	// Tu so
	int numerator;
	// Mau so
	int denominator;
public:
    Fraction();
    Fraction(int num, int den);
    Fraction(int random);
    void simplify();
    friend ostream& operator << (ostream& os, Fraction f);
};