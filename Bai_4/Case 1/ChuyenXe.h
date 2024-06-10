#ifndef CHUYENXE_H
#define CHUYENXE_H

#include <iostream>
#include <string>
#include <vector>

class ChuyenXe {
protected:
    std::string maSoChuyen;
    std::string hoTenTaiXe;
    int soXe;
    float doanhThu;
public:
    ChuyenXe(std::string maSo, std::string tenTaiXe, int soXe, float doanhThu) 
        : maSoChuyen(maSo), hoTenTaiXe(tenTaiXe), soXe(soXe), doanhThu(doanhThu) {}
    
    virtual float tinhDoanhThu() = 0;
    
    virtual void hienThiThongTin() = 0;
};

class ChuyenXeNoiThanh : public ChuyenXe {
private:
    int soTuyen;
    float soKmDiDuoc;
public:
    ChuyenXeNoiThanh(std::string maSo, std::string tenTaiXe, int soXe, float doanhThu, int soTuyen, float soKm) 
        : ChuyenXe(maSo, tenTaiXe, soXe, doanhThu), soTuyen(soTuyen), soKmDiDuoc(soKm) {}

    float tinhDoanhThu() override {
        return doanhThu;
    }

    void hienThiThongTin() override {
        std::cout << "Chuyen xe noi thanh - Ma so: " << maSoChuyen << ", Tai xe: " << hoTenTaiXe << ", So xe: " << soXe << ", So tuyen: " << soTuyen << ", So km di duoc: " << soKmDiDuoc << ", Doanh thu: " << doanhThu << std::endl;
    }
};

class ChuyenXeNgoaiThanh : public ChuyenXe {
private:
    std::string noiDen;
    int soNgayDiDuoc;
public:
    ChuyenXeNgoaiThanh(std::string maSo, std::string tenTaiXe, int soXe, float doanhThu, std::string noiDen, int soNgay) 
        : ChuyenXe(maSo, tenTaiXe, soXe, doanhThu), noiDen(noiDen), soNgayDiDuoc(soNgay) {}

    float tinhDoanhThu() override {
        return doanhThu;
    }

    void hienThiThongTin() override {
        std::cout << "Chuyen xe ngoai thanh - Ma so: " << maSoChuyen << ", Tai xe: " << hoTenTaiXe << ", So xe: " << soXe << ", Noi den: " << noiDen << ", So ngay di duoc: " << soNgayDiDuoc << ", Doanh thu: " << doanhThu << std::endl;
    }
};

#endif