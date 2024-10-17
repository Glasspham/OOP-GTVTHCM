#include "pointManagement.h"

int main() {
    vector<pointManagement> danhSachSV;
    int choice;
    string filename;
    ifstream ifs;
    ofstream ofs;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            nhapDanhSach(danhSachSV);
            break;
        case 2:
            printTitle();
            xuatDanhSach(danhSachSV);
            break;
        case 3: {
            cout << "Nhap ten file de ghi: ";
            cin >> filename;
            ofs.open(filename);
            if (!ofs) {
                cout << "Khong mo duoc file.\n";
                continue;
            }
            ghiFile(ofs, danhSachSV);
            cout << "Ghi thanh cong!\n";
            ofs.close();
            break;
        }
        case 4: {
            danhSachSV.clear();
            cout << "Nhap ten file de doc: ";
            cin >> filename;
            ifs.open(filename);
            if (!ifs) {
                cout << "Khong mo duoc file.\n";
                continue;
            }
            docFile(ifs, danhSachSV);
            cout << "Doc thanh cong!\n";
            ifs.close();
            break;
        }
        case 5:
            inSinhVienDuDieuKien(danhSachSV);
            break;
        case 6:
            inSinhVienHoNguyen(danhSachSV);
            break;
        case 7:
            inSinhVienTrungTen(danhSachSV);
            break;
        case 0:
            cout << "Ket thuc chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
            break;
        }
    } while (choice != 0);
    return 0;
}