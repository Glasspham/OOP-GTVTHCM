#include "ChuyenVienPhanTich.h"

ChuyenVienPhanTich::ChuyenVienPhanTich(const string maso, const string hoten, double luongCB)
    : NhanVien(maso, hoten, luongCB) {}

ChuyenVienPhanTich::ChuyenVienPhanTich() : NhanVien() {}

double ChuyenVienPhanTich::getTienThuong() const {
    if(phuongthucTienThuong)
        return phuongthucTienThuong->tinhTienThuong(luongCB);
    return 0.0;
}

string ChuyenVienPhanTich::toString() const {
    return "Maso: " + maso + ", HoTen: " + hoten + ", LuongCB: " + to_string((int)luongCB);
}

ostream& operator<<(ostream& out, const ChuyenVienPhanTich& nv) {
    out << nv.toString();
    return out;
}

istream& operator>>(istream& in, ChuyenVienPhanTich& nv) { 
    string maso, hoten;
    double luongCB;
    in >> maso; in.ignore();
    string line; getline(in, line);
    size_t lastSpace = line.find_last_of(' ');
    hoten = line.substr(0, lastSpace);
    luongCB = stoi(line.substr(lastSpace + 1));
    nv.setMaso(maso);
    nv.setHoten(hoten);
    nv.setLuongCB(luongCB);
    return in;
}
