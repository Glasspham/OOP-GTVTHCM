#include "LapTrinhVien.h"

LapTrinhVien::LapTrinhVien(const string maso, const string hoten, double luongCB)
    : NhanVien(maso, hoten, luongCB) {}

LapTrinhVien::LapTrinhVien() : NhanVien() {}

double LapTrinhVien::getTienThuong() const {
    if(phuongthucTienThuong)
        return phuongthucTienThuong->tinhTienThuong(luongCB);
    return 0.0;
}

string LapTrinhVien::toString() const {
    return "Maso: " + maso + ", HoTen: " + hoten + ", LuongCB: " + to_string((int)luongCB);
}

ostream& operator<<(ostream& out, const LapTrinhVien& nv) {
    out << nv.toString();
    return out;
}

istream& operator>>(istream& in, LapTrinhVien& nv) { 
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
