#include "Ring.h"

Ring::Ring(int x, int y, int r, int r2) : Circle(x, y, r), r2(r2) {
    if (r > r2) {
        // Swap r and r2 if r is greater than r2
        int temp = this->r;
        this->r = r2;
        this->r2 = temp;
    }
}

Ring::Ring(const Circle& c1, int r2) : Circle(c1), r2(r2) {
    if (c1.getR() > r2) {
        // Swap r and r2 if r is greater than r2
        int temp = this->r;
        this->r = r2;
        this->r2 = temp;
    }
}

ostream& operator << (ostream& out, const Ring& p) {
    out << "(" << p.x << "," << p.y << "," << p.r << "," << p.r2 << ")";
    return out;
}

int Ring::width() const {
    return r2 - r;
}
