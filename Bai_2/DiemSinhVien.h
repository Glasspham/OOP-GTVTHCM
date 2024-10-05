#ifndef DIEMHOCVIEN_H
#define DIEMHOCVIEN_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class DiemHocVien {
private:
    string hoTen;
    int namSinh;
    float diemMon1, diemMon2, diemMon3;

public:
    DiemHocVien(string hoTen, int namSinh, float diemMon1, float diemMon2, float diemMon3);
    ~DiemHocVien();

    string getHoTen() const;
    int getNamSinh() const;
    float getDiemMon1() const;
    float getDiemMon2() const;
    float getDiemMon3() const;

    bool isLamLuanVanTotNghiep() const;
    bool isThiTotNghiep() const;
    bool isThiLai() const;
    vector<string> getMonThiLai() const;

    friend ostream& operator<<(ostream& os, const DiemHocVien& hocVien);
};

#endif // DIEMHOCVIEN_H