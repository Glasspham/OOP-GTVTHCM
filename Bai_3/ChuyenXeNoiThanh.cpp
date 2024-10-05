#include "ChuyenXeNoiThanh.h"

ChuyenXeNoiThanh::ChuyenXeNoiThanh(std::string maSo, std::string tenTaiXe, int soXe, float doanhThu, int soTuyen, float soKm)
    : ChuyenXe(maSo, tenTaiXe, soXe, doanhThu), soTuyen(soTuyen), soKmDiDuoc(soKm) {}

float ChuyenXeNoiThanh::tinhDoanhThu() {
    return doanhThu;
}

void ChuyenXeNoiThanh::hienThiThongTin() {
    std::cout << "Chuyen xe noi thanh - Ma so: " << maSoChuyen << ", Tai xe: " << hoTenTaiXe << ", So xe: " << soXe << ", So tuyen: " << soTuyen << ", So km di duoc: " << soKmDiDuoc << ", Doanh thu: " << doanhThu << std::endl;
}