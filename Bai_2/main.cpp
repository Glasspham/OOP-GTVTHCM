#include "DiemSinhVien.h"

int main() {
    int soLuongSinhVien;
    std::cout << "Nhap so luong sinh vien: ";
    std::cin >> soLuongSinhVien;

    std::vector<DiemHocVien> danhSachHocVien;

    // Nhập thông tin cho từng sinh viên
    for (int i = 0; i < soLuongSinhVien; ++i) {
        std::string hoTen;
        int namSinh;
        float diemMon1, diemMon2, diemMon3;

        std::cout << "Nhap thong tin cho sinh vien " << i + 1 << ":" << std::endl;
        std::cout << "Ho ten: ";
        std::cin.ignore();
        std::getline(std::cin, hoTen);
        std::cout << "Nam sinh: ";
        std::cin >> namSinh;
        std::cout << "Diem mon 1: ";
        std::cin >> diemMon1;
        std::cout << "Diem mon 2: ";
        std::cin >> diemMon2;
        std::cout << "Diem mon 3: ";
        std::cin >> diemMon3;

        DiemHocVien hocVien(hoTen, namSinh, diemMon1, diemMon2, diemMon3);
        danhSachHocVien.push_back(hocVien);
    }

    // Kiểm tra và đếm số lượng học viên làm luận văn tốt nghiệp, thi tốt nghiệp, và cần thi lại
    int soLuongLamLuanVan = 0;
    int soLuongThiTotNghiep = 0;
    int soLuongThiLai = 0;

    std::cout << "Danh sach hoc vien:" << std::endl;
    for (const auto& hocVien : danhSachHocVien) {
        std::cout << hocVien;

        if (hocVien.isLamLuanVanTotNghiep()) {
            soLuongLamLuanVan++;
            std::cout << "Lam luan van tot nghiep" << std::endl;
        } else if (hocVien.isThiTotNghiep()) {
            soLuongThiTotNghiep++;
            std::cout << "Thi tot nghiep" << std::endl;
        } else {
            soLuongThiLai++;
            std::vector<std::string> monThiLai = hocVien.getMonThiLai();
            std::cout << "Thi lai";
            for (const auto& mon : monThiLai) {
                std::cout << " " << mon;
            }
            std::cout << std::endl;
        }
    }

    std::cout << "So luong hoc vien lam luan van tot nghiep: " << soLuongLamLuanVan << std::endl;
    std::cout << "So luong hoc vien thi tot nghiep: " << soLuongThiTotNghiep << std::endl;
    std::cout << "So luong hoc vien phai thi lai: " << soLuongThiLai << std::endl;

    return 0;
}