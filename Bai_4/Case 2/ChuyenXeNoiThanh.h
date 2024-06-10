#ifndef CHUYENXENOITHANH_H
#define CHUYENXENOITHANH_H

#include "ChuyenXe.h"

class ChuyenXeNoiThanh : public ChuyenXe {
private:
    int soTuyen;
    float soKmDiDuoc;
public:
    ChuyenXeNoiThanh(std::string maSo, std::string tenTaiXe, int soXe, float doanhThu, int soTuyen, float soKm);
    float tinhDoanhThu() override;
    void hienThiThongTin() override;
};

#endif