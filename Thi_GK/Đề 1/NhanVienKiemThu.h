#pragma once
#include "NhanVien.h"
class NhanVienKiemThu :
    public NhanVien
{
public:
    NhanVienKiemThu(const string maso, const string hoten, double luongCB);
    NhanVienKiemThu();
    double getTienThuong() const override;
    string toString() const override;
    //trien khai lại cac operactor lớp cha 
};