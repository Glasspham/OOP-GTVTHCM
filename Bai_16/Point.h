#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Point {
private:
    double x, y, distance;
public:
    Point();
    Point(double x, double y);

    bool operator < (const Point &p);
    friend istream &operator >> (istream& is, Point &p);
    friend ostream &operator << (ostream& os, Point p);
};