//Kế thừa lại lớp NhanVien
#pragma once
#include "NhanVien.h"
class KeToanVien :
    public NhanVien
{
public:
    KeToanVien(const string maso, const string hoten, double luongCB);
    KeToanVien();
    double getTienThuong() const override;
    string toString() const override;
    //trien khai lại cac operactor lớp cha 
};