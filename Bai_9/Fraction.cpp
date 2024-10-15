#include "Fraction.h"

Fraction::Fraction() : numerator(0), denominator(1) {};

Fraction::Fraction(int num, int dem) : numerator(num), denominator(dem) {
    if(denominator == 0)
        cout << "Loi! Khong duoc khoi tao mau bang khong!" << endl;
    simplify();
};

void Fraction::setNumerator(int numerator) { this->numerator = numerator; }

void Fraction::setDenominator(int denominator) {
    if(denominator == 0)
        cout << "Loi! Khong duoc truyen mau so bang khong!" << endl;
    this->denominator = denominator; 
}

int Fraction::getNumerator() { return numerator; }

int Fraction::getDenominator() { return denominator; }

void Fraction::show() {
    if(denominator == 1) cout << numerator << endl;
    else if(numerator == 0) cout << 0 << endl;
    else cout << numerator << '/' << denominator << endl;
}

void Fraction::input() { 
    string ps; cin >> ps;
    string num = "";
    for(int i = 0; i < ps.size(); ++i){
        if(ps[i] != '/') num += ps[i];
        else if(ps[i] == '/'){
            numerator = stoi(num);
            num = "";
        }
        if(i == ps.size() - 1){
            denominator = stoi(num);
            if(denominator == 0) {
                cout << "Loi! mau so khong the bang khong!" << endl;
                cout << "Nhap lai phan so: ";
                input();
            }
        }
    }
    simplify();
}

int GCD(int a, int b) {
    a = abs(a), b = abs(b);
    while(b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
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

const Fraction Fraction::add(const Fraction &other) const {
    int sumNumerator =  numerator * other.denominator + denominator * other.numerator;
    int sumDenominator = denominator * other.denominator;
    return Fraction(sumNumerator, sumDenominator);
}