#pragma once
#include "NhanVien.h"
class LapTrinhVien :
    public NhanVien
{
public:
    LapTrinhVien(const string maso, const string hoten, double luongCB);
    LapTrinhVien();
    double getTienThuong() const override;
    string toString() const override;
    //trien khai lại cac operactor lớp cha 
};