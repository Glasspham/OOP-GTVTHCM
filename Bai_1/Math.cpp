#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Fraction {
private:
    int numerator; // Tử số
    int denominator; // Mẫu số

public:
    // Hàm tạo mặc định
    Fraction() : numerator(0), denominator(1) {}

    // Hàm tạo mới 
    Fraction(int num, int denom) : numerator(num), denominator(denom) {}

    // Hàm tạo với một tham số để sinh tử và mẫu ngẫu nhiên
    Fraction(int n) {
        numerator = rand() % (n) + 1;
        denominator = rand() % (n) + 1;
    }

    // Overloading các toán tử để thực hiện phép tính cộng, trừ, nhân, chia
    Fraction operator+(const Fraction& other) const {
        Fraction result; 
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    Fraction operator-(const Fraction& other) const {
        Fraction result; 
        result.numerator = numerator * other.denominator - other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    Fraction operator*(const Fraction& other) const {
        Fraction result; 
        result.numerator = numerator * other.numerator;
        result.denominator = denominator * other.denominator;
        return result;
    }

    Fraction operator/(const Fraction& other) const {
        Fraction result; 
        result.numerator = numerator * other.denominator;
        result.denominator = denominator * other.numerator;
        return result;
    }

    // Overloading các toán tử so sánh để so sánh bằng, khác, lớn hơn hoặc bằng, nhỏ hơn hoặc bằng
    bool operator==(const Fraction& other) const {
        return (numerator * other.denominator == other.numerator * denominator);
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator>=(const Fraction& other) const {
        return (numerator * other.denominator >= other.numerator * denominator);
    }

    bool operator<=(const Fraction& other) const {
        return (numerator * other.denominator <= other.numerator * denominator);
    }

    // Overloading toán tử << để xuất ra màn hình
    friend ostream& operator<<(ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    // Overloading toán tử >> để nhập từ bàn phím
    friend istream& operator>>(istream& is, Fraction& frac) {
        cout << "Enter a fraction: ";
        is >> frac.numerator;
        cout << "Enter a denominator: ";
        is >> frac.denominator;
        return is;
    }
};

int main() {
    // Fraction a, b;
    // cin >> a >> b;
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;
    // cout << "a + b = " << a + b << endl;
    // cout << "a - b = " << a - b << endl;
    // cout << "a * b = " << a * b << endl;
    // cout << "a / b = " << a / b << endl;
    // cout << "a == b: " << (a == b) << endl;
    // cout << "a != b: " << (a != b) << endl;
    // cout << "a >= b: " << (a >= b) << endl;
    // cout << "a <= b: " << (a <= b) << endl;
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    // Sinh ra 100 phân số ngẫu nhiên
    Fraction fractions[100];
    for (int i = 0; i < 100; ++i) {
        fractions[i] = Fraction(n);
    }

    // In ra các phân số nhỏ hơn hoặc bằng 1/2
    cout << "All fractions less than or equal to 1/2: ";
    Fraction half(1, 2); // Khởi tạo phân số 1/2
    for (int i = 0; i < 100; ++i) {
        if (fractions[i] <= half) { // So sánh với phân số 1/2
            cout << fractions[i] << " ";
        }
    }
    cout << endl;

    // In ra các phân số duy nhất
    cout << "All unique fractions:";
    for (int i = 0; i < 100; ++i) {
        bool isUnique = true;
        for (int j = i + 1; j < 100; ++j) {
            if (fractions[i] == fractions[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            cout << fractions[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

