#include "Point.h"

Point::Point() : x(0), y(0), distance(0) {};

Point::Point(double x, double y) : x(x), y(y) {
    distance = sqrt(pow(x,2) + pow(y,2));
}

bool Point::operator < (const Point& p) {
    return this->distance < p.distance;
}

istream& operator >> (istream& is, Point &p) {
    is >> p.x >> p.y;
    p.distance = sqrt(pow(p.x,2) + pow(p.y,2));
    return is;
}

ostream& operator << (ostream& os, Point p) {
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}