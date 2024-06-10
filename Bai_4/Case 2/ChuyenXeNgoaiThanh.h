#ifndef CHUYENXENGOAITHANH_H
#define CHUYENXENGOAITHANH_H

#include "ChuyenXe.h"

class ChuyenXeNgoaiThanh : public ChuyenXe {
private:
    std::string noiDen;
    int soNgayDiDuoc;
public:
    ChuyenXeNgoaiThanh(std::string maSo, std::string tenTaiXe, int soXe, float doanhThu, std::string noiDen, int soNgay);
    float tinhDoanhThu() override;
    void hienThiThongTin() override;
};

#endif