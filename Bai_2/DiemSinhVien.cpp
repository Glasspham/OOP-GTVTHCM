#include "DiemSinhVien.h"

DiemHocVien::DiemHocVien(string hoTen, int namSinh, float diemMon1, float diemMon2, float diemMon3)
    : hoTen(hoTen), namSinh(namSinh), diemMon1(diemMon1), diemMon2(diemMon2), diemMon3(diemMon3) {}

DiemHocVien::~DiemHocVien() {}

string DiemHocVien::getHoTen() const { return hoTen; }
int DiemHocVien::getNamSinh() const { return namSinh; }
float DiemHocVien::getDiemMon1() const { return diemMon1; }
float DiemHocVien::getDiemMon2() const { return diemMon2; }
float DiemHocVien::getDiemMon3() const { return diemMon3; }

bool DiemHocVien::isLamLuanVanTotNghiep() const {
    float diemTrungBinh = (diemMon1 + diemMon2 + diemMon3) / 3;
    return (diemTrungBinh > 7) && (diemMon1 >= 5) && (diemMon2 >= 5) && (diemMon3 >= 5);
}

bool DiemHocVien::isThiTotNghiep() const {
    float diemTrungBinh = (diemMon1 + diemMon2 + diemMon3) / 3;
    return (diemTrungBinh <= 7) && (diemMon1 >= 5) && (diemMon2 >= 5) && (diemMon3 >= 5);
}

bool DiemHocVien::isThiLai() const {
    return (diemMon1 < 5) || (diemMon2 < 5) || (diemMon3 < 5);
}

vector<string> DiemHocVien::getMonThiLai() const {
    vector<string> monThiLai;
    if (diemMon1 < 5) monThiLai.push_back("Mon 1");
    if (diemMon2 < 5) monThiLai.push_back("Mon 2");
    if (diemMon3 < 5) monThiLai.push_back("Mon 3");
    return monThiLai;
}

ostream& operator<<(ostream& os, const DiemHocVien& hocVien) {
    os << "Ho ten: " << hocVien.hoTen << ", Nam sinh: " << hocVien.namSinh << endl;
    os << "Diem mon 1: " << hocVien.diemMon1 << ", Diem mon 2: " << hocVien.diemMon2 << ", Diem mon 3: " << hocVien.diemMon3 << endl;
    return os;
}