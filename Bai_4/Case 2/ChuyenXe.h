#ifndef CHUYENXE_H
#define CHUYENXE_H

#include<iostream>
#include <vector>
#include <string>

class ChuyenXe {
protected:
    std::string maSoChuyen;
    std::string hoTenTaiXe;
    int soXe;
    float doanhThu;
public:
    ChuyenXe(std::string maSo, std::string tenTaiXe, int soXe, float doanhThu);
    virtual float tinhDoanhThu() = 0;
    virtual void hienThiThongTin() = 0;
};

#endif