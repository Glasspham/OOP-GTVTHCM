#include "NhanVienFactory.h"
#include "LapTrinhVien.h"
#include "KeToanVien.h"
#include "NhanVienKiemThu.h"
#include "ChuyenVienPhanTich.h"
#include "TienThuongNgoaiGio.h"
#include "TienThuongNgoaiTinh.h"
#include "TienThuongThongThuong.h"

NhanVienFactory::NhanVienFactory() {}

NhanVien* NhanVienFactory::createNhanVien(const int loaiNV, const string maso, const string hoten, double luongCB) {
    switch (loaiNV) {
        case 1: {
            NhanVien* nhanVien = new NhanVienKiemThu(maso, hoten, luongCB);
            nhanVien->setPhuongthucTienThuong(new TienThuongNgoaiGio());
            return nhanVien;
        }
        case 2: {
            NhanVien* nhanVien = new LapTrinhVien(maso, hoten, luongCB);
            nhanVien->setPhuongthucTienThuong(new TienThuongNgoaiGio());
            return nhanVien;
        }
        case 3: {
            NhanVien* nhanVien = new ChuyenVienPhanTich(maso, hoten, luongCB);
            nhanVien->setPhuongthucTienThuong(new TienThuongNgoaiTinh());
            return nhanVien;
        }
        case 4: {
            NhanVien* nhanVien = new KeToanVien(maso, hoten, luongCB);
            nhanVien->setPhuongthucTienThuong(new TienThuongThongThuong());
            return nhanVien;
        }
        default: return nullptr;
    }
}

NhanVien* NhanVienFactory::createNhanVien(const int loaiNV) {
    switch (loaiNV) {
        case 1: {
            NhanVien* nhanVien = new NhanVienKiemThu();
            nhanVien->setPhuongthucTienThuong(new TienThuongNgoaiGio());
            return nhanVien;
        }
        case 2: {
            NhanVien* nhanVien = new LapTrinhVien();
            nhanVien->setPhuongthucTienThuong(new TienThuongNgoaiGio());
            return nhanVien;
        }
        case 3: {
            NhanVien* nhanVien = new ChuyenVienPhanTich();
            nhanVien->setPhuongthucTienThuong(new TienThuongNgoaiTinh());
            return nhanVien;
        }
        case 4: {
            NhanVien* nhanVien = new KeToanVien();
            nhanVien->setPhuongthucTienThuong(new TienThuongThongThuong());
            return nhanVien;
        }
        default:
            return nullptr;
    }
}
