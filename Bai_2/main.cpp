#include "DiemSinhVien.h"

DiemHocVien nhapThongTin() {
    string hoTen;
    int namSinh;
    float diemMon1, diemMon2, diemMon3;
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap nam sinh: ";
    cin >> namSinh;
    cout << "Nhap diem mon 1: ";
    cin >> diemMon1;
    cout << "Nhap diem mon 2: ";
    cin >> diemMon2;
    cout << "Nhap diem mon 3: ";
    cin >> diemMon3;
    DiemHocVien hocVien(hoTen, namSinh, diemMon1, diemMon2, diemMon3);
    return hocVien;
}

void hienThiMenu() {
    cout << "---------------------------------------------------------------\n";
    cout << "1. Nhap thong tin sinh vien moi\n";
    cout << "2. Xem danh sach sinh vien\n";
    cout << "3. Xem so luong sinh vien lam luan van, thi tot nghiep, thi lai\n";
    cout << "0. Thoat\n";
    cout << "---------------------------------------------------------------\n";
    cout << "Chon: ";
}

void taoCungSinhVien(vector<DiemHocVien>& danhSachHocVien) {
    danhSachHocVien.push_back(DiemHocVien("Nguyen Van A", 2000, 8.0, 9.0, 8.5));
    danhSachHocVien.push_back(DiemHocVien("Tran Thi B", 2001, 7.0, 6.5, 7.0));
    danhSachHocVien.push_back(DiemHocVien("Le Van C", 2002, 4.0, 5.0, 6.0));
    danhSachHocVien.push_back(DiemHocVien("Phan Thi D", 2000, 9.0, 8.0, 9.0));
    danhSachHocVien.push_back(DiemHocVien("Do Van E", 1999, 3.5, 5.5, 7.0));
    danhSachHocVien.push_back(DiemHocVien("Hoang Thi F", 2003, 6.0, 5.5, 6.0));
}

int main() {
    vector<DiemHocVien> danhSachHocVien;
    taoCungSinhVien(danhSachHocVien);
    int luaChon;
    do {
        hienThiMenu();
        cin >> luaChon;
        cin.ignore();
        switch (luaChon) {
            case 1: {
                danhSachHocVien.push_back(nhapThongTin());
                break;
            }
            case 2: {
                cout << "Danh sach hoc vien:\n";
                for (const auto& hocVien : danhSachHocVien)
                    cout << hocVien;
                break;
            }
            case 3: {
                int soLuongLamLuanVan = 0;
                int soLuongThiTotNghiep = 0;
                int soLuongThiLai = 0;
                for (const auto& hocVien : danhSachHocVien) {
                    if (hocVien.isLamLuanVanTotNghiep())
                        soLuongLamLuanVan++;
                    else if (hocVien.isThiTotNghiep())
                        soLuongThiTotNghiep++;
                    else soLuongThiLai++;
                }
                cout << "So luong hoc vien lam luan van: " << soLuongLamLuanVan << endl;
                cout << "So luong hoc vien thi tot nghiep: " << soLuongThiTotNghiep << endl;
                cout << "So luong hoc vien thi lai: " << soLuongThiLai << endl;
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Moi ban chon lai.\n";
        }
    } while (luaChon != 0);

    return 0;
}
