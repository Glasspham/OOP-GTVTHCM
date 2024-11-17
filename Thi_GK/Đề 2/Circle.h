#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Circle {
protected:
    int x, y; // tọa độ tâm
    int r;    // bán kính
public:
    // Các hàm khởi tạo
    Circle();                               // Khởi tạo mặc định (0, 0, 1)
    Circle(int x0, int y0, int r0);         // Khởi tạo với x, y, r
    Circle(int r);                          // Khởi tạo với bán kính r (tâm mặc định 0, 0)
    Circle(const Circle& c);                // Copy constructor

    // Các hàm get
    int getX() const { return x; }
    int getY() const { return y; }
    int getR() const { return r; }

    // Toán tử xuất và nhập
    friend ostream& operator << (ostream& out, const Circle& c); // Xuất
    friend istream& operator >> (istream& in, Circle& c);        // Nhập

    // Toán tử tính khoảng cách tâm
    friend double operator - (const Circle& c1, const Circle& c2);

    // So sánh tâm (trùng/khác tâm)
    friend bool operator == (const Circle& c1, const Circle& c2);
    friend bool operator != (const Circle& c1, const Circle& c2);

    // So sánh bán kính
    bool operator < (const Circle& c) const; // Trả về true nếu bán kính nhỏ hơn

    // Kiểm tra vị trí tương đối
    bool operator ^ (const Circle& c) const; // Kiểm tra tiếp xúc
};
