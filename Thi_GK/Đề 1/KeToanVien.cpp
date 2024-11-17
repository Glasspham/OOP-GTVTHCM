#include "KeToanVien.h"

KeToanVien::KeToanVien(const string maso, const string hoten, double luongCB)
    : NhanVien(maso, hoten, luongCB) {}

KeToanVien::KeToanVien() : NhanVien() {}

double KeToanVien::getTienThuong() const {
    return 0.1 * getLuongCB();
}

string KeToanVien::toString() const {
    return "Ke Toan: " + NhanVien::toString();
}