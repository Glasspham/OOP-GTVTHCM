#ifndef DIEMHOCVIEN_H
#define DIEMHOCVIEN_H

#include <iostream>
#include <string>
#include <vector>

class DiemHocVien {
private:
    std::string hoTen;
    int namSinh;
    float diemMon1, diemMon2, diemMon3;

public:
    DiemHocVien(std::string hoTen, int namSinh, float diemMon1, float diemMon2, float diemMon3);
    ~DiemHocVien();

    std::string getHoTen() const;
    int getNamSinh() const;
    float getDiemMon1() const;
    float getDiemMon2() const;
    float getDiemMon3() const;

    bool isLamLuanVanTotNghiep() const;
    bool isThiTotNghiep() const;
    bool isThiLai() const;
    std::vector<std::string> getMonThiLai() const;

    friend std::ostream& operator<<(std::ostream& os, const DiemHocVien& hocVien);
};

#endif // DIEMHOCVIEN_H