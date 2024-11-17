#include "ChuyenVienPhanTich.h"

ChuyenVienPhanTich::ChuyenVienPhanTich(const string maso, const string hoten, double luongCB)
        : NhanVien(maso, hoten, luongCB) {}

ChuyenVienPhanTich::ChuyenVienPhanTich() : NhanVien() {}

double ChuyenVienPhanTich::getTienThuong() const {
    return 0.25 * getLuongCB();
}

string ChuyenVienPhanTich::toString() const {
    return "Chuyen vien phan tich" + NhanVien::toString();
}