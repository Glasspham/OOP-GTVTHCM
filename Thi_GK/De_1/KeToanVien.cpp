#include "KeToanVien.h"

KeToanVien::KeToanVien(const string maso, const string hoten, double luongCB)
    : NhanVien(maso, hoten, luongCB) {}

KeToanVien::KeToanVien() : NhanVien() {}

double KeToanVien::getTienThuong() const {
    if(phuongthucTienThuong)
        return phuongthucTienThuong->tinhTienThuong(luongCB);
    return 0.0;
}

string KeToanVien::toString() const {
    return "Maso: " + maso + ", HoTen: " + hoten + ", LuongCB: " + to_string((int)luongCB);
}

ostream& operator<<(ostream& out, const KeToanVien& nv) {
    out << nv.toString();
    return out;
}

istream& operator>>(istream& in, KeToanVien& nv) { 
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
