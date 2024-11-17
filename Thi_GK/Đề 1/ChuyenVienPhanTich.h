#pragma once
#include "NhanVien.h"
class ChuyenVienPhanTich :
    public NhanVien
{
public:
    ChuyenVienPhanTich(const string maso, const string hoten, double luongCB);
    ChuyenVienPhanTich();
    double getTienThuong() const override;
    string toString() const override;
    //trien khai lại cac operactor lớp cha 
};