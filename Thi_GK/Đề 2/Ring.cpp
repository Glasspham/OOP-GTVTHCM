#include "Ring.h"

// Hàm khởi tạo với (x, y, r, r2), đảm bảo r <= r2
Ring::Ring(int x, int y, int r, int r2) : Circle(x, y, r) {
    if (r > r2) swap(this->r, this->r2); // Hoán đổi nếu r > r2
    else this->r2 = r2;
}

// Hàm khởi tạo với Circle và bán kính r2, đảm bảo r <= r2
Ring::Ring(const Circle& c1, int r2) : Circle(c1) {
    if(r > r2) swap(this->r, this->r2); // Hoán đổi nếu r > r2
    else this->r2 = r2;
}

// Toán tử << (xuất)
ostream& operator << (ostream& out, const Ring& p) {
    out << "(" << p.x << "," << p.y << "," << p.r << "," << p.r2 << ")";
    return out;
}

// Độ dày của Ring
int Ring::width() const {
    return r2 - r;
}

// Toán tử kiểm tra tiếp xúc
bool Ring::operator ^ (const Ring& r) const {
    Circle outer1(x, y, r2);       // Đường tròn ngoài của Ring 1
    Circle outer2(r.x, r.y, r.r2); // Đường tròn ngoài của Ring 2
    return outer1 ^ outer2;
}

// Toán tử kiểm tra rời nhau
bool Ring::operator | (const Ring& r) const {
    Circle outer1(x, y, r2);
    Circle outer2(r.x, r.y, r.r2);
    double d = outer1 - outer2; // Khoảng cách giữa tâm
    return d > (outer1.getR() + outer2.getR());
}

// Toán tử kiểm tra cắt nhau
bool Ring::operator & (const Ring& r) const {
    Circle outer1(x, y, r2);
    Circle outer2(r.x, r.y, r.r2);
    double d = outer1 - outer2; // Khoảng cách giữa tâm
    return d < (outer1.getR() + outer2.getR()) && d > abs(outer1.getR() - outer2.getR());
}