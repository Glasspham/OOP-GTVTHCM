#include "Fraction.h"

int GCD(int a, int b) {
    a = abs(a), b = abs(b);
    while(b) {
        int t = a % b;
        a = b;
        b = t;
    } return a;
}

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        this->numerator = 0;
        this->denominator = 1;
    } else {
        this->numerator = numerator;
        this->denominator = denominator;
        this->simplify();
    }
}

Fraction::Fraction(int random) {
    int num = rand() % random + 1;
    int dem = rand() % random + 1;
    this->numerator = num;
    this->denominator = dem;
    this->simplify();
}

void Fraction::simplify() {
    int gcd = GCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

float Fraction::toFloat() const {
    return static_cast<float>(numerator) / denominator;
}

ostream& operator << (ostream& os, Fraction f) {
    os << f.numerator << '/' << f.denominator;
    return os;
}

Fraction Fraction::operator + (const Fraction& other) const {
    Fraction result; 
    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    result.simplify();
    return result;
}

Fraction Fraction::operator - (const Fraction& other) const {
    Fraction result; 
    result.numerator = numerator * other.denominator - other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    result.simplify();
    return result;
}

Fraction Fraction::operator * (const Fraction& other) const {
    Fraction result; 
    result.numerator = numerator * other.numerator;
    result.denominator = denominator * other.denominator;
    result.simplify();
    return result;
}