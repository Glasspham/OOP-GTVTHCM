#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class TienThuong
{
public:
	/// <summary>
	/// Phuong thuc Ao moi lop con se trien khai va override lai
	/// TienThuongNgoaiGio = luongCB* 0.15
    /// TienThuongNgoaiTinh = luongCB * 0.3
    /// TienThuongThongThuong = luongCB * 0.05
	/// </summary>
	/// <param name="luongCB"></param>
	/// <returns></returns>
	virtual double tinhTienThuong(double luongCB) = 0;
};