#include <sstream>
#include <cassert>
#include "TienThuongNgoaiGio.h"
#include "TienThuongNgoaiTinh.h"
#include "TienThuongThongThuong.h"
#include "NhanVien.h"
#include "LapTrinhVien.h"
#include "KeToanVien.h"
#include "NhanVienKiemThu.h"
#include "ChuyenVienPhanTich.h"
#include "NhanVienFactory.h"

int main() {
    int op; cin >> op;
    double result;
    TienThuong* tienthuong;
    #if 1 // a
    switch (op) {
        case 1: {
            tienthuong = new TienThuongNgoaiGio();
            result = tienthuong->tinhTienThuong(10000);
            assert(result == 1500);
            cout << "Test Case 1 PASSED!" << endl;
            break;
        }
        case 2: {
            tienthuong = new TienThuongNgoaiTinh();
            result = tienthuong->tinhTienThuong(10000);
            assert(result == 3000);
            cout << "Test Case 2 PASSED!" << endl;
            break;
        }
        default: {
            tienthuong = new TienThuongThongThuong();
            result = tienthuong->tinhTienThuong(10000);
            assert(result == 500);
            cout << "Test Case 3 PASSED!" << endl;
            break;
        }
    }
    #endif

   #if 1 // b
    LapTrinhVien* nv1;
    KeToanVien* nv2;
    NhanVienKiemThu *nv3;
    ChuyenVienPhanTich* nv4;
    string expectedOutput;
    stringstream ss;
    stringstream outStream;
    LapTrinhVien nv;
    switch(op) {
        case 1: {
            nv1 = new LapTrinhVien("LT001", "Nguyen Van A", 15000000);
            nv2 = new KeToanVien("KT001", "Tran Thi B", 12000000);
            assert(nv1->getMaso() == "LT001");
            assert(nv1->getHoten() == "Nguyen Van A");
            assert(nv1->getLuongCB() == 15000000);
            assert(nv2->getMaso() == "KT001");
            assert(nv2->getHoten() == "Tran Thi B");
            assert(nv2->getLuongCB() == 12000000);
            cout << "OK" << endl;
            break;
        }
        case 2: {
            nv1 = new LapTrinhVien("LT001", "Nguyen Van A", 15000000);
            nv2 = new KeToanVien("KT001", "Tran Thi B", 12000000);
            nv1->setPhuongthucTienThuong(new TienThuongNgoaiGio());
            nv2->setPhuongthucTienThuong(new TienThuongThongThuong());
            assert(nv1->getTienThuong() == 15000000 * 0.15);
            assert(nv2->getTienThuong() == 12000000 * 0.05);
            cout << "OK" << endl;
            break;
        }
        case 3: {
            nv1 = new LapTrinhVien("LT001", "Nguyen Van A", 15000000);
            expectedOutput = "Maso: LT001, HoTen: Nguyen Van A, LuongCB: 15000000";
            assert(nv1->toString() == expectedOutput);
            cout << "OK" << endl;
            break;
        }
        case 4: {
            ss << "LT002 Nguyen Van B 18000000\n";
            ss >> nv;

            assert(nv.getMaso() == "LT002");
            assert(nv.getHoten() == "Nguyen Van B");
            assert(nv.getLuongCB() == 18000000);

            outStream << nv;
            expectedOutput = "Maso: LT002, HoTen: Nguyen Van B, LuongCB: 18000000";
            assert(outStream.str() == expectedOutput);
            cout << "OK" << endl;
            break;
        }
        default: {
            nv1 = new LapTrinhVien("LT001", "Nguyen Van A", 15000000);
            nv2 = new KeToanVien("KT001", "Tran Thi B", 12000000);
            nv3 = new NhanVienKiemThu("KT002", "Pham Van C", 14000000);
            nv4 = new ChuyenVienPhanTich("CV001", "Le Thi D", 20000000);

            nv1->setPhuongthucTienThuong(new TienThuongNgoaiGio());
            nv2->setPhuongthucTienThuong(new TienThuongThongThuong());
            nv3->setPhuongthucTienThuong(new TienThuongNgoaiTinh());
            nv4->setPhuongthucTienThuong(new TienThuongNgoaiGio());

            assert(nv1->getTienThuong() == 15000000 * 0.15);
            assert(nv2->getTienThuong() == 12000000 * 0.05);
            assert(nv3->getTienThuong() == 14000000 * 0.3);
            assert(nv4->getTienThuong() == 20000000 * 0.15);
            cout << "OK" << endl;
            break;
        }
    }
    #endif

    #if 1 // c
    NhanVienFactory factory;
    NhanVien* nhanVien;
    switch (op) {
        case 1: {
            nhanVien = factory.createNhanVien(1, "MS01", "Nguyen Van A", 5000.0);
            result = nhanVien->getTienThuong();
            tienthuong = new TienThuongNgoaiGio();
            result = tienthuong->tinhTienThuong(5000.0);
            assert(result == nhanVien->getTienThuong());
            cout << "OK" << endl;
            break;
        }
        case 2: {
            nhanVien = factory.createNhanVien(2, "MS02", "Le Thi B", 7000.0);
            tienthuong = new TienThuongNgoaiGio();
            result = tienthuong->tinhTienThuong(7000.0);
            assert(result == nhanVien->getTienThuong());
            cout << "OK" << endl;
            break;
        }
        case 3: {
            nhanVien = factory.createNhanVien(3, "MS03", "Pham Van C", 6000.0);
            tienthuong = new TienThuongNgoaiTinh();
            result = tienthuong->tinhTienThuong(6000.0);
            assert(result == nhanVien->getTienThuong());
            cout << "OK" << endl;
            break;
        }
        case 4: {
            nhanVien = factory.createNhanVien(4, "MS04", "Tran Thi D", 5500.0);
            tienthuong = new TienThuongThongThuong();
            result = tienthuong->tinhTienThuong(5500.0);
            assert(result == nhanVien->getTienThuong());
            cout << "OK" << endl;
            break;
        }
        case 5: {
            nhanVien = factory.createNhanVien(5, "MS05", "Hoang Van E", 5000.0);
            assert(nhanVien == nullptr);
            cout << "OK" << endl;
            break;
        }
        default: {
            nhanVien = factory.createNhanVien(2);
            assert(dynamic_cast<LapTrinhVien*>(nhanVien) != nullptr);
            cout << "OK" << endl;
            break;
        }
    }
    #endif
    return 0;
}