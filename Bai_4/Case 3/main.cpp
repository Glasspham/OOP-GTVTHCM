#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Khai báo lớp cơ sở Chuyến Xe
class ChuyenXe {
protected:
    string maSoChuyen;
    string hoTenTaiXe;
    int soXe;
    float doanhThu;
public:
    // Constructor
    ChuyenXe(string maSo, string tenTaiXe, int soXe, float doanhThu) 
        : maSoChuyen(maSo), hoTenTaiXe(tenTaiXe), soXe(soXe), doanhThu(doanhThu) {}

    // Phương thức tính doanh thu
    virtual float tinhDoanhThu() = 0;

    // Phương thức hiển thị thông tin chuyến xe
    virtual void hienThiThongTin() = 0;
};

// Lớp con Chuyến Xe Nội Thành kế thừa từ ChuyenXe
class ChuyenXeNoiThanh : public ChuyenXe {
private:
    int soTuyen;
    float soKmDiDuoc;
public:
    // Constructor
    ChuyenXeNoiThanh(string maSo, string tenTaiXe, int soXe, float doanhThu, int soTuyen, float soKm) 
        : ChuyenXe(maSo, tenTaiXe, soXe, doanhThu), soTuyen(soTuyen), soKmDiDuoc(soKm) {}

    // Phương thức tính doanh thu
    float tinhDoanhThu() override {
        return doanhThu;
    }

    // Phương thức hiển thị thông tin chuyến xe nội thành
    void hienThiThongTin() override {
        cout << "Chuyen xe noi thanh - Ma so: " << maSoChuyen << ", Tai xe: " << hoTenTaiXe << ", So xe: " << soXe << ", So tuyen: " << soTuyen << ", So km di duoc: " << soKmDiDuoc << ", Doanh thu: " << doanhThu << endl;
    }
};

// Lớp con Chuyến Xe Ngoại Thành kế thừa từ ChuyenXe
class ChuyenXeNgoaiThanh : public ChuyenXe {
private:
    string noiDen;
    int soNgayDiDuoc;
public:
    // Constructor
    ChuyenXeNgoaiThanh(string maSo, string tenTaiXe, int soXe, float doanhThu, string noiDen, int soNgay) 
        : ChuyenXe(maSo, tenTaiXe, soXe, doanhThu), noiDen(noiDen), soNgayDiDuoc(soNgay) {}

    // Phương thức tính doanh thu
    float tinhDoanhThu() override {
        return doanhThu;
    }

    // Phương thức hiển thị thông tin chuyến xe ngoại thành
    void hienThiThongTin() override {
        cout << "Chuyen xe ngoai thanh - Ma so: " << maSoChuyen << ", Tai xe: " << hoTenTaiXe << ", So xe: " << soXe << ", Noi den: " << noiDen << ", So ngay di duoc: " << soNgayDiDuoc << ", Doanh thu: " << doanhThu << endl;
    }
};

int main() {
    // Tạo danh sách chứa các chuyến xe
    vector<ChuyenXe*> danhSachChuyenXe;

    // Tạo 2 chuyến xe nội thành và 2 chuyến xe ngoại thành
    danhSachChuyenXe.push_back(new ChuyenXeNoiThanh("NT001", "Tai xe A", 123, 1000.0, 1, 50));
    danhSachChuyenXe.push_back(new ChuyenXeNoiThanh("NT002", "Tai xe B", 456, 1500.0, 2, 70));
    danhSachChuyenXe.push_back(new ChuyenXeNgoaiThanh("NG001", "Tai xe C", 789, 2000.0, "C1", 3));
    danhSachChuyenXe.push_back(new ChuyenXeNgoaiThanh("NG002", "Tai xe D", 101, 2500.0, "C2", 4));

    // Tính tổng doanh thu của tất cả các chuyến xe và từng loại chuyến xe
    float tongDoanhThu = 0;
    float tongDoanhThuNoiThanh = 0;
    float tongDoanhThuNgoaiThanh = 0;

    for (auto chuyenXe : danhSachChuyenXe) {
        tongDoanhThu += chuyenXe->tinhDoanhThu();
        if (dynamic_cast<ChuyenXeNoiThanh*>(chuyenXe)) {
            tongDoanhThuNoiThanh += chuyenXe->tinhDoanhThu();
        } else if (dynamic_cast<ChuyenXeNgoaiThanh*>(chuyenXe)) {
            tongDoanhThuNgoaiThanh += chuyenXe->tinhDoanhThu();
        }
    }

    // Xuất tổng doanh thu
    cout << "Tong doanh thu cua tat ca cac chuyen xe: " << tongDoanhThu << endl;
    cout << "Tong doanh thu cua cac chuyen xe noi thanh: " << tongDoanhThuNoiThanh << endl;
    cout << "Tong doanh thu cua cac chuyen xe ngoai thanh: " << tongDoanhThuNgoaiThanh << endl;

    // Giải phóng bộ nhớ
    for (auto chuyenXe : danhSachChuyenXe) {
        delete chuyenXe;
    }

    return 0;
}