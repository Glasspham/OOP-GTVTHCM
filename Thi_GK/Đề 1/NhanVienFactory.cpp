#include "NhanVienFactory.h"

NhanVienFactory::NhanVienFactory() {}

NhanVien* NhanVienFactory::createNhanVien(const int loaiNV, const string maso, const string hoten, double luongCB) {
    switch (loaiNV) {
    case 1:
        return new NhanVienKiemThu(maso, hoten, luongCB);
    case 2:
        return new LapTrinhVien(maso, hoten, luongCB);
    case 3:
        return new ChuyenVienPhanTich(maso, hoten, luongCB);
    case 4:
        return new KeToanVien(maso, hoten, luongCB);
    default:
        return nullptr;
    }   
}

NhanVien* NhanVienFactory::createNhanVien(const int loaiNV) {
    switch (loaiNV) {
    case 1:
        return new NhanVienKiemThu();
    case 2:
        return new LapTrinhVien();
    case 3:
        return new ChuyenVienPhanTich();
    case 4:
        return new KeToanVien();
    default:
        return nullptr;
    }
}