#pragma once
#include "NhanVien.h"
class ChuyenVienPhanTich : public NhanVien {
public:
    ChuyenVienPhanTich(const string maso, const string hoten, double luongCB);
    ChuyenVienPhanTich();
    double getTienThuong() const override;
    string toString() const override;
    //trien khai lại cac operactor lớp cha
    friend ostream& operator<<(ostream& out, const ChuyenVienPhanTich& nv);
    friend istream& operator>>(istream& in, ChuyenVienPhanTich& nv);
};