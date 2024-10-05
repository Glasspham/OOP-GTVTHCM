#include "ChuyenXeNgoaiThanh.h"

ChuyenXeNgoaiThanh::ChuyenXeNgoaiThanh(std::string maSo, std::string tenTaiXe, int soXe, float doanhThu, std::string noiDen, int soNgay)
    : ChuyenXe(maSo, tenTaiXe, soXe, doanhThu), noiDen(noiDen), soNgayDiDuoc(soNgay) {}

float ChuyenXeNgoaiThanh::tinhDoanhThu() {
    return doanhThu;
}

void ChuyenXeNgoaiThanh::hienThiThongTin() {
    std::cout << "Chuyen xe ngoai thanh - Ma so: " << maSoChuyen << ", Tai xe: " << hoTenTaiXe << ", So xe: " << soXe << ", Noi den: " << noiDen << ", So ngay di duoc: " << soNgayDiDuoc << ", Doanh thu: " << doanhThu << std::endl;
}