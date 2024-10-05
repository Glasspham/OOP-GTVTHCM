#include"Circle.h"

Circle::Circle() : x(0), y(0), r(1) {}

Circle::Circle(int x0, int y0, int r0) : x(x0), y(y0), r(r0) {}

Circle::Circle(int r0) : x(0), y(0), r(r0) {}

Circle::Circle(const Circle& p) : x(p.x), y(p.y), r(p.r) {}

ostream& operator<< (ostream& out, const Circle& p) {
    out << "(" << p.x << "," << p.y << "," << p.r << ")";
    return out;
}

istream& operator>> (istream& in, Circle& p) {
    in >> p.x >> p.y >> p.r;
    return in;
}

double operator-(const Circle& p1, const Circle& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool operator==(const Circle& p1, const Circle& p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

bool operator!=(const Circle& p1, const Circle& p2) {
    return !(p1 == p2);
}

bool Circle::operator<(const Circle& c2) const {
    return r < c2.r;
}

bool Circle::operator^(const Circle& c2) const {
    double distance = *this - c2; // Tính khoảng cách giữa 2 tâm đường tròn
    return (distance == abs(r - c2.r)) || (distance == r + c2.r);
}
