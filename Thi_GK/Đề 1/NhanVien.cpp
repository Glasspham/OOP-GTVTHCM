#include "NhanVien.h"
// TODO: insert return statement here
NhanVien::NhanVien() : maso(""), hoten(""), luongCB(0), phuongthucTienThuong(nullptr) {}

NhanVien::NhanVien(const string maso, const string hoten, double luongCB)
        : maso(maso), hoten(hoten), luongCB(luongCB), phuongthucTienThuong(nullptr) {}

string NhanVien::toString() const {
    return "Maso: " + maso + ", HoTen: " + hoten + ", LuongCB: " + to_string(luongCB);
}

double NhanVien::getTienThuong() const {
    return phuongthucTienThuong->tinhTienThuong(luongCB);
}

string NhanVien::getMaso() const {
    return maso;
}

string NhanVien::getHoten() const {
    return hoten;
}

double NhanVien::getLuongCB() const {
    return luongCB;
}

TienThuong* NhanVien::getPhuongthucTienThuong() const {
    return phuongthucTienThuong;
}

void NhanVien::setMaso(const string& maso) {
    this->maso = maso;
}

void NhanVien::setHoten(const string& hoten) {
    this->hoten = hoten;
}

void NhanVien::setLuongCB(double luongCB) {
    this->luongCB = luongCB;
}

void NhanVien::setPhuongthucTienThuong(TienThuong* phuongthuc) {
    this->phuongthucTienThuong = phuongthuc;
}

ostream& operator<<(ostream& out, const NhanVien& nv) {
    out << nv.toString();
    return out;
}

istream& operator>>(istream& in, NhanVien& nv) {
    cout << "Nhap ma so: ";
    in >> nv.maso;
    cout << "Nhap ho ten: ";
    in.ignore();
    getline(in, nv.hoten);
    cout << "Nhap luong co ban: ";
    in >> nv.luongCB;
    return in;
}