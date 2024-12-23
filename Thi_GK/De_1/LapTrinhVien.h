#pragma once
#include "NhanVien.h"
class LapTrinhVien : public NhanVien {
public:
    LapTrinhVien(const string maso, const string hoten, double luongCB);
    LapTrinhVien();
    double getTienThuong() const override;
    string toString() const override;
    //trien khai lại cac operactor lớp cha
    friend ostream& operator<<(ostream& out, const LapTrinhVien& nv);
    friend istream& operator>>(istream& in, LapTrinhVien& nv);
};