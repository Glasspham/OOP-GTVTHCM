#include <iostream>
#include "ChuyenXe.h"

int main() {
    std::vector<ChuyenXe*> danhSachChuyenXe;

    danhSachChuyenXe.push_back(new ChuyenXeNoiThanh("NT001", "Tai xe A", 123, 1000.0, 1, 50));
    danhSachChuyenXe.push_back(new ChuyenXeNoiThanh("NT002", "Tai xe B", 456, 1500.0, 2, 70));
    danhSachChuyenXe.push_back(new ChuyenXeNgoaiThanh("NG001", "Tai xe C", 789, 2000.0, "C1", 3));
    danhSachChuyenXe.push_back(new ChuyenXeNgoaiThanh("NG002", "Tai xe D", 101, 2500.0, "C2", 4));

    float tongDoanhThu = 0;
    float tongDoanhThuNoiThanh = 0;
    float tongDoanhThuNgoaiThanh = 0;

    for (auto chuyenXe : danhSachChuyenXe) {
        tongDoanhThu += chuyenXe->tinhDoanhThu();
        if (dynamic_cast<ChuyenXeNoiThanh*>(chuyenXe)) {
            tongDoanhThuNoiThanh += chuyenXe->tinhDoanhThu();
        } else if (dynamic_cast<ChuyenXeNgoaiThanh*>(chuyenXe)) {
            tongDoanhThuNgoaiThanh += chuyenXe->tinhDoanhThu();
        }
    }

    std::cout << "Tong doanh thu cua tat ca cac chuyen xe: " << tongDoanhThu << std::endl;
    std::cout << "Tong doanh thu cua cac chuyen xe noi thanh: " << tongDoanhThuNoiThanh << std::endl;
    std::cout << "Tong doanh thu cua cac chuyen xe ngoai thanh: " << tongDoanhThuNgoaiThanh << std::endl;

    for (auto chuyenXe : danhSachChuyenXe) {
        delete chuyenXe;
    }

    return 0;
}