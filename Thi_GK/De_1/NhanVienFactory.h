#pragma once
#include "NhanVien.h"
#include "KeToanVien.h"
#include "LapTrinhVien.h"
#include "NhanVienKiemThu.h"
#include "ChuyenVienPhanTich.h"
#include "INhanVienFactory.h"
/// <summary>
/// Ke thua va override INhanVienFactory
/// Factory NhanVien theo loai
/// </summary>
class NhanVienFactory : public INhanVienFactory {
public:
    NhanVienFactory();

    /// <summary>
    /// override INhanVienFactory
    /// </summary>
    /// <param name="loaiNV"></param>
    /// <param name="maso"></param>
    /// <param name="hoten"></param>
    /// <param name="luongCB"></param>
    /// <returns></returns>
    NhanVien *createNhanVien(const int loaiNV, const string maso, const string hoten, double luongCB) override;

    /// <summary>
    /// override INhanVienFactory
    /// </summary>
    /// <param name="loaiNV"></param>
    /// <returns></returns>
    NhanVien *createNhanVien(const int loaiNV) override;
};
