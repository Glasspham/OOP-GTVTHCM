#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class Fraction{
private:
    // Tu so
    int numerator;
    // Mau so
    int denominator;
public:
    Fraction();
    Fraction(int num, int den);
    void simplify();
    friend ostream& operator << (ostream &os, Fraction f);
    friend istream& operator >> (istream &is, Fraction &f);
    
    bool operator == (const Fraction &other) const;
    bool operator < (const Fraction &other) const;
    bool operator > (const Fraction &other) const;
};