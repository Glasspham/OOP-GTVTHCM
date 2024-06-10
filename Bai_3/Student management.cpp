/*
Quản lý học sinh, sinh viên
*/
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

class HocSinh {
private:
	    string Hoten;
	    float diemtoan;
	    float diemvan;
	    float diemanh;

public:
    HocSinh() {
        Hoten = " ";
        diemtoan = 0;
        diemvan = 0;
        diemanh = 0;
    }

    HocSinh(string ten, float toan, float van, float anh) {
        this->Hoten = ten;
        this->diemtoan = toan;
        this->diemvan = van;
        this->diemanh = anh;
    }

    float diemtrungbinh() {
        return (this->diemtoan + this->diemvan + this->diemanh) / 3.0;
    }

    void xuatthongtin() {
        cout << "\n\t=========== Thong Tin Cua Sinh Vien La ==========" << endl;
        cout << "\t\tTen Cua Hoc Sinh La: " << Hoten << endl;
        cout << "\t\tDiem Toan Cua Hoc Sinh La: " << diemtoan << endl;
        cout << "\t\tDiem Van Cua Hoc Sinh La: " << diemvan << endl;
        cout << "\t\tDiem Anh Cua Hoc Sinh La: " << diemanh << endl;
        cout << "\t\tDiem Trung Binh: " << diemtrungbinh() << endl;
    }
};

int DemSoLuongHocSinh(HocSinh* danhSachHocSinh, int soLuongHocSinh) {
    int soLuong = 0;
    for (int i = 0; i < soLuongHocSinh; i++) {
        if (danhSachHocSinh[i].diemtrungbinh() >= 0) {
            soLuong++;
        }
    }
    return soLuong;
}

int main() {
	system("color E");
    const int maxHocSinh = 100;
    HocSinh* danhSachHocSinh = new HocSinh[maxHocSinh];
    int soLuongHocSinh = 0;
	
    while (true) {
        cout << "==============: Menu :=================" << endl;
        cout<<"XIN MOI CAC BAN CHON CAC CHUC NANG SAU !"<<endl;
        cout << "1. Them hoc sinh" << endl;
        cout << "2. Xuat danh sach hoc sinh" << endl;
        cout << "3. Xoa hoc sinh" << endl;
        cout << "4. In so luong hoc sinh" << endl;
        cout << "5. Thoat" << endl;
        cout << "Chon: ";
        int luaChon;
        cin >> luaChon;

        switch (luaChon) {
        	//Them hoc sinh
            case 1:
                  if (soLuongHocSinh < maxHocSinh) {
                    cout << "Nhap thong tin hoc sinh:" << endl;
                    string ten;
                    float toan, van, anh;
                    cout << "Nhap ten: ";
                    cin.ignore();
                    getline(cin, ten);
                    cout << "Nhap diem Toan: ";
                    cin >> toan;
                    cout << "Nhap diem Van: ";
                    cin >> van;
                    cout << "Nhap diem Anh: ";
                    cin >> anh;
                    HocSinh hs(ten, toan, van, anh);
                    danhSachHocSinh[soLuongHocSinh++] = hs;
                    cout << "Hoc sinh da duoc them." << endl;
                } else {
                    cout << "Danh sach hoc sinh da day, khong the them them hoc sinh." << endl;
                }
                break;
                //Xuat danh sach hoc sinh
            case 2:
                 cout << "Danh sach hoc sinh:" << endl;
                for (int i = 0; i < soLuongHocSinh; i++) {
                    cout << "Hoc Sinh Thu " << (i + 1) << ":" << endl;
                    danhSachHocSinh[i].xuatthongtin();
                }
                break;
			//Xoa hoc sinh
            case 3:
               if (soLuongHocSinh > 0) {
                    int index;
                    cout << "Nhap vi tri hoc sinh can xoa (1-" << soLuongHocSinh << "): ";
                    cin >> index;
                    if (index >= 1 && index <= soLuongHocSinh) {
                        for (int i = index - 1; i < soLuongHocSinh - 1; i++) {
                            danhSachHocSinh[i] = danhSachHocSinh[i + 1];
                        }
                        soLuongHocSinh--;
                        cout << "Hoc sinh da duoc xoa." << endl;
                    } else {
                        cout << "Vi tri khong hop le." << endl;
                    }
                } else {
                    cout << "Danh sach hoc sinh rong, khong the xoa." << endl;
                }
                break;
			//Dem so luong hoc sinh
            case 4:
                cout << "So luong hoc sinh hien co: " << DemSoLuongHocSinh(danhSachHocSinh, soLuongHocSinh) << endl;
                break;
			//Thoat
            case 5:
                delete[] danhSachHocSinh;
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai!" << endl;
                break;
        }
    }
    return 0;
}
