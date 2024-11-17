#pragma once
#include "Circle.h"

class Ring : public Circle {
protected:
    int r2; // Bán kính lớn

public:
    int getR2() const { return r2; }

    Ring(int x, int y, int r, int r2); // Khởi tạo với tâm (x, y), bán kính r, r2
    Ring(const Circle& c1, int r2); // Khởi tạo với Circle và bán kính r2

    friend ostream& operator << (ostream& out, const Ring& p); // Toán tử xuất
    int width() const; // Độ dày của Ring (hiệu hai bán kính)

    // Toán tử vị trí tương đối
    bool operator ^ (const Ring& r) const; // Kiểm tra tiếp xúc
    bool operator | (const Ring& r) const; // Kiểm tra rời nhau
    bool operator & (const Ring& r) const; // Kiểm tra cắt nhau
};