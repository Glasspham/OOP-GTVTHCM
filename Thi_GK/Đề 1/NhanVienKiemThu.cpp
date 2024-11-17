#include "NhanVienKiemThu.h"

NhanVienKiemThu::NhanVienKiemThu(const string maso, const string hoten, double luongCB)
        : NhanVien(maso, hoten, luongCB) {}
    
NhanVienKiemThu::NhanVienKiemThu() : NhanVien() {}

double NhanVienKiemThu::getTienThuong() const {
    return 0.1 * getLuongCB();
}

string NhanVienKiemThu::toString() const {
    return "Nhan Vien Kiem Thu: " + NhanVien::toString();
}