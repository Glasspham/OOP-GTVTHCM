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
    void simplify();
    friend ostream& operator << (ostream& os, Fraction f);
    
    // Overload post-increment operator (f++)
    Fraction operator ++ (int);
    // Overload pre-increment operator (++f)
    Fraction operator ++ ();
    // Overload post-decrement operator (f--)
    Fraction operator -- (int);
    // Overload pre-decrement operator (--f)
    Fraction operator -- ();
};