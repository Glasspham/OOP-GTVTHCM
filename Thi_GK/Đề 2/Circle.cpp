#include "Circle.h"

// Hàm khởi tạo mặc định
Circle::Circle() : x(0), y(0), r(1) {}

// Hàm khởi tạo với x, y, r
Circle::Circle(int x0, int y0, int r0) : x(x0), y(y0), r(r0) {}

// Hàm khởi tạo với bán kính
Circle::Circle(int r0) : x(0), y(0), r(r0) {}

// Copy constructor
Circle::Circle(const Circle& p) : x(p.x), y(p.y), r(p.r) {}

// Toán tử << (xuất)
ostream& operator<<(ostream& out, const Circle& p) {
    out << "(" << p.x << "," << p.y << "," << p.r << ")";
    return out;
}

// Toán tử >> (nhập)
istream& operator>>(istream& in, Circle& p) {
    in >> p.x >> p.y >> p.r;
    return in;
}

// Toán tử tính khoảng cách giữa hai tâm
double operator-(const Circle& p1, const Circle& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Toán tử so sánh tâm
bool operator==(const Circle& p1, const Circle& p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}
bool operator!=(const Circle& p1, const Circle& p2) {
    return !(p1 == p2);
}

// So sánh bán kính (sắp xếp)
bool Circle::operator<(const Circle& c2) const {
    return r < c2.r;
}

// Kiểm tra tiếp xúc
bool Circle::operator^(const Circle& c2) const {
    double d = *this - c2;
    return d == (r + c2.r) || d == abs(r - c2.r);
}