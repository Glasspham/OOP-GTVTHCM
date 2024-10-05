#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // !a
    Fraction();
    Fraction(int num, int denom);
    Fraction(int n);

    // !b
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // !c
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;

    // !d
    friend ostream& operator<<(ostream& os, const Fraction& frac);
    friend istream& operator>>(istream& is, Fraction& frac);
};