#pragma once
#include "NhanVien.h"
/// <summary>
/// INhanVienFactory la mot lop ao thuan tuy nhu mot inetrface
/// Nhiem vu cung cap nguoi dung giao dien factory NhanVien theo loai
/// loaiNV = [1 : NhanVienKiemThu, 2: LapTrinhVien, 3 :ChuyenVienPhanTich, 4: KeToanVien]
/// NhanVienKiemThu được tính tiền thưởng theo TienThuongNgoaiGio
/// LapTrinhVien được tính tiền thưởng theo TienThuongNgoaiGio
/// ChuyenVienPhanTich  được tính tiền thưởng theo TienThuongNgoaiTinh
/// KeToanVien được tính tiền thưởng theo TienThuongThongThuong
/// </summary>
class INhanVienFactory {
public:
    /// <summary>
    /// Method ao thuan tuy cac lop con ke thua can trien khai day du
    /// Voi 4 tham so bat buoc
    /// </summary>
    /// <param name="loaiNV"></param>
    /// <param name="maso"></param>
    /// <param name="hoten"></param>
    /// <param name="luongCB"></param>
    /// <returns></returns>
    virtual NhanVien* createNhanVien(const int loaiNV, const string maso, const string hoten, double luongCB) = 0 ;

    /// <summary>
    /// Method ao thuan tuy cac lop con ke thua can trien khai day du
    /// Moi 1 tham so loaiNV
    /// </summary>
    /// <param name="loaiNV"></param>
    /// <returns></returns>
    virtual NhanVien* createNhanVien(const int loaiNV) = 0;
};