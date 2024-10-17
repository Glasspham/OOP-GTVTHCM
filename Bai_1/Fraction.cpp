#include"Fraction.h"

// !a
Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {}

Fraction::Fraction(int n) {
    numerator = rand() % n + 1;
    denominator = rand() % n + 1;
}

// !b
Fraction Fraction::operator+(const Fraction& other) const {
    Fraction result; 
    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction result; 
    result.numerator = numerator * other.denominator - other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction result; 
    result.numerator = numerator * other.numerator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction::operator/(const Fraction& other) const {
    Fraction result; 
    result.numerator = numerator * other.denominator;
    result.denominator = denominator * other.numerator;
    return result;
}

// !c
bool Fraction::operator==(const Fraction& other) const {
    return (numerator * other.denominator == other.numerator * denominator);
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return (numerator * other.denominator >= other.numerator * denominator);
}

bool Fraction::operator<=(const Fraction& other) const {
    return (numerator * other.denominator <= other.numerator * denominator);
}

// !d
ostream& operator<<(ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

istream& operator>>(istream& is, Fraction& frac) {
    is >> frac.numerator >> frac.denominator;
    return is;
}