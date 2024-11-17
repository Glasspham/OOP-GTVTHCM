#include "LapTrinhVien.h"

LapTrinhVien::LapTrinhVien(const string maso, const string hoten, double luongCB)
        : NhanVien(maso, hoten, luongCB) {}

LapTrinhVien::LapTrinhVien() : NhanVien() {}

double LapTrinhVien::getTienThuong() const {
    return 0.2 * getLuongCB();
}

string LapTrinhVien::toString() const {
    return "Lap Trinh: " + NhanVien::toString();
}