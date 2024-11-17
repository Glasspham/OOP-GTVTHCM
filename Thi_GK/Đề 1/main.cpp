// ! Hàm main chỉ để test không phải đề cho 
#if 1 // a
#include <iostream>
#include "TienThuongNgoaiGio.h"
#include "TienThuongNgoaiTinh.h"
#include "TienThuongThongThuong.h"

int main() {
    double luongCB = 5000; // Example basic salary

    // Create instances of different reward strategies
    TienThuong* rewardNgoaiGio = new TienThuongNgoaiGio();
    TienThuong* rewardNgoaiTinh = new TienThuongNgoaiTinh();
    TienThuong* rewardThongThuong = new TienThuongThongThuong();

    // Calculate bonuses
    cout << "Bonus for overtime: " << rewardNgoaiGio->tinhTienThuong(luongCB) << endl;
    cout << "Bonus for out-of-province work: " << rewardNgoaiTinh->tinhTienThuong(luongCB) << endl;
    cout << "Standard bonus: " << rewardThongThuong->tinhTienThuong(luongCB) << endl;

    // Clean up
    delete rewardNgoaiGio;
    delete rewardNgoaiTinh;
    delete rewardThongThuong;

    return 0;
}
#endif

#if 1 // b
#include <iostream>
#include "KeToanVien.h"
#include "LapTrinhVien.h"
#include "NhanVienKiemThu.h"
#include "ChuyenVienPhanTich.h"

int main() {
    NhanVien* nv1 = new KeToanVien("KT001", "Nguyen A", 6000);
    NhanVien* nv2 = new LapTrinhVien("LT001", "Tran B", 8000);
    NhanVien* nv3 = new NhanVienKiemThu("KT001", "Le C", 7000);
    NhanVien* nv4 = new ChuyenVienPhanTich("CVPT001", "Pham D", 9000);

    cout << *nv1 << ", Tien Thuong: " << nv1->getTienThuong() << endl;
    cout << *nv2 << ", Tien Thuong: " << nv2->getTienThuong() << endl;
    cout << *nv3 << ", Tien Thuong: " << nv3->getTienThuong() << endl;
    cout << *nv4 << ", Tien Thuong: " << nv4->getTienThuong() << endl;

    delete nv1;
    delete nv2;
    delete nv3;
    delete nv4;

    return 0;
}
#endif

#if 1 // c
#include <iostream>
#include "NhanVienFactory.h"
#include "NhanVienKiemThu.h"
#include "LapTrinhVien.h"
#include "ChuyenVienPhanTich.h"
#include "KeToanVien.h"

using namespace std;

int main() {
    // Tạo factory
    NhanVienFactory factory;

    // Test case a: Tạo nhân viên kiểm thử
    NhanVien* nv1 = factory.createNhanVien(1, "KT001", "Nguyen Van A", 1000.0);

    // Test case b: Tạo lập trình viên
    NhanVien* nv2 = factory.createNhanVien(2, "LTV001", "Tran Thi B", 1200.0);

    // Test case c: Tạo chuyên viên phân tích
    NhanVien* nv3 = factory.createNhanVien(3, "CVPT001", "Le Van C", 1500.0);

    // Kiểm tra và in thông tin
    if (nv1) {
        cout << "Nhan vien 1: " << nv1->toString() << endl;
        cout << "Tien thuong: " << nv1->getTienThuong() << endl;
    }
    if (nv2) {
        cout << "Nhan vien 2: " << nv2->toString() << endl;
        cout << "Tien thuong: " << nv2->getTienThuong() << endl;
    }
    if (nv3) {
        cout << "Nhan vien 3: " << nv3->toString() << endl;
        cout << "Tien thuong: " << nv3->getTienThuong() << endl;
    }

    // Giải phóng bộ nhớ
    delete nv1;
    delete nv2;
    delete nv3;

    return 0;
}
#endif