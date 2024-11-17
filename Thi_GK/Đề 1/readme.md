Công ty XYZ chuyên về lĩnh vực phần mềm máy tính.

Ngoài việc trả tiền lương theo hợp đồng cho nhân viên, hàng tháng công ty còn trả tiền thưởng cho nhân viên dựa trên kết quả làm việc hoặc các đóng góp của nhân viên cho công ty trong tháng đó.

Mỗi nhân viên cần lưu trữ các thông tin gồm: mã số, họ tên và tiền lương căn bản. Nhân viên trong công ty có thể là: lập trình viên, nhân viên kiểm thử, chuyên viên phân tích dữ liệu, nhân viên kế toán… Yêu cầu chương trình quản lý có tính độc lập cao với các đối tượng nhân viên cụ thể trong chương trình và có thể dễ dàng mở rộng thêm cho nhiều loại nhân viên nữa.

Ngoài ra, để linh hoạt trong việc áp dụng chế độ tiền thưởng, công ty đưa ra nhiều cách tính tiền thưởng khác nhau để áp dụng cho từng nhân viên trong từng tình huống cụ thể.

Câu a:

**Các tệp được yêu cầu**

TienThuong.h

```bash
#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class TienThuong {
public:
	/// <summary>
	/// Phuong thuc Ao moi lop con se trien khai va override lai
	/// TienThuongNgoaiGio = luongCB* 0.15
    /// TienThuongNgoaiTinh = luongCB * 0.3
    /// TienThuongThongThuong = luongCB * 0.05
	/// </summary>
	/// <param name="luongCB"></param>
	/// <returns></returns>
	virtual double tinhTienThuong(double luongCB) = 0;
};
```

TienThuongNgoaiGio.h

```bash
#pragma once
#include "TienThuong.h"
class TienThuongNgoaiGio : public TienThuong {
public:
    // TODO: insert return statement here
};
```

TienThuongNgoaiTinh.h

```bash
#pragma once
#include "TienThuong.h"
class TienThuongNgoaiTinh : public TienThuong {
public:
    // TODO: insert return statement here
};
```

TienThuongThongThuong.h

```bash
#pragma once
#include "TienThuong.h"
class TienThuongThongThuong : public TienThuong {
    // TODO: insert return statement here
};
```

TienThuongNgoaiGio.cpp

```bash
#include "TienThuongNgoaiGio.h"
// TODO: insert return statement here
```

TienThuongNgoaiTinh.cpp

```bash
#include "TienThuongNgoaiTinh.h"
// TODO: insert return statement here
```

TienThuongThongThuong.cpp

```bash
#include "TienThuongThongThuong.h"
// TODO: insert return statement here
```

Câu b

**Các tệp được yêu cầu**

NhanVien.h

```bash
#pragma once
#include "TienThuong.h"
#include<iostream>
#include<string.h>
using namespace std;
/// <summary>
/// Lop NhanVien chua cac thuoc tinh chung
/// Can cac lop con trien khai lai getTienThuong
/// </summary>
class NhanVien {
protected:
    string maso;
    string hoten;
    double luongCB;
    TienThuong* phuongthucTienThuong;

public:
    NhanVien();
    NhanVien(const string maso, const string hoten, double luongCB);
    virtual string toString() const;

    /// <summary>
    /// Moi lop con se co phuong thuc getTienThuong khac nhau
    /// </summary>
    /// <returns></returns>
    virtual double getTienThuong() const = 0;

    // Getters
    string getMaso() const;
    string getHoten() const;
    double getLuongCB() const;
    TienThuong* getPhuongthucTienThuong() const;

    // Setters
    void setMaso(const string& maso);
    void setHoten(const string& hoten);
    void setLuongCB(double luongCB);
    void setPhuongthucTienThuong(TienThuong* phuongthuc);

    /// <summary>
    /// Toan tu chen cho phep xuat NhanVien
    /// FM: Maso: {maso}, HoTen: {hoten}, LuongCB: {luongCB}
    /// </summary>
    /// <param name="out"></param>
    /// <param name="nv"></param>
    /// <returns>ostream</returns>
    friend ostream& operator<< (ostream& out, const NhanVien& nv);

    /// <summary>
    /// Toan tu tach cho phep nhap mot nhan vien
    ///  Maso: {maso}, HoTen: {hoten}, LuongCB: {luongCB}
    /// </summary>
    /// <param name="in"></param>
    /// <param name="nv"></param>
    /// <returns>istream</returns>
    friend istream& operator>> (istream& in, NhanVien& nv);
};
```

KeToanVien.h

```bash
// Kế thừa lại lớp NhanVien
#pragma once
#include "NhanVien.h"
class KeToanVien : public NhanVien {
public:
    KeToanVien(const string maso, const string hoten, double luongCB);
    KeToanVien();
    double getTienThuong() const override;
    string toString() const override;
    //trien khai lại cac operactor lớp cha
};
```

LapTrinhVien.h

```bash
#pragma once
#include "NhanVien.h"
class LapTrinhVien : public NhanVien {
public:
    LapTrinhVien(const string maso, const string hoten, double luongCB);
    LapTrinhVien();
    double getTienThuong() const override;
    string toString() const override;
    //trien khai lại cac operactor lớp cha
};
```

NhanVienKiemThu.h

```bash
#pragma once
#include "NhanVien.h"
class NhanVienKiemThu : public NhanVien {
public:
    NhanVienKiemThu(const string maso, const string hoten, double luongCB);
    NhanVienKiemThu();
    double getTienThuong() const override;
    string toString() const override;
    //trien khai lại cac operactor lớp cha
};
```

ChuyenVienPhanTich.h

```bash
#pragma once
#include "NhanVien.h"
class ChuyenVienPhanTich : public NhanVien {
public:
    ChuyenVienPhanTich(const string maso, const string hoten, double luongCB);
    ChuyenVienPhanTich();
    double getTienThuong() const override;
    string toString() const override;
    //trien khai lại cac operactor lớp cha
};
```

NhanVien.cpp

```bash
#include "NhanVien.h"
// TODO: insert return statement here
```

KeToanVien.cpp

```bash
#include "KeToanVien.h"
// TODO: insert return statement here
```

LapTrinhVien.cpp

```bash
#include "LapTrinhVien.h"
// TODO: insert return statement here
```

NhanVienKiemThu.cpp

```bash
#include "NhanVienKiemThu.h"
// TODO: insert return statement here
```

ChuyenVienPhanTich.cpp

```bash
#include "ChuyenVienPhanTich.h"
// TODO: insert return statement here
```

Câu c

**Các tệp được yêu cầu**

INhanVienFactory.h

```bash
#pragma once
#pragma once
#include "NhanVien.h"
/// <summary>
/// INhanVienFactory la mot lop ao thuan tuy nhu mot inetrface
/// Nhiem vu cung cap nguoi dung giao dien factory NhanVien theo loai
/// loaiNV = [1 : NhanVienKiemThu, 2: LapTrinhVien, 3 :ChuyenVienPhanTich, 4: KeToanVien]
/// NhanVienKiemThu được tính tiền thưởng theo TienThuongNgoaiGio
/// LapTrinhVien được tính tiền thưởng theo TienThuongNgoaiGio
/// ChuyenVienPhanTich  được tính tiền thưởng theo TienThuongNgoaiTinh
/// KeToanVien được tính tiền thưởng theo TienThuongThongThuong
/// </summary>
class INhanVienFactory {
public:
    /// <summary>
    /// Method ao thuan tuy cac lop con ke thua can trien khai day du
    /// Voi 4 tham so bat buoc
    /// </summary>
    /// <param name="loaiNV"></param>
    /// <param name="maso"></param>
    /// <param name="hoten"></param>
    /// <param name="luongCB"></param>
    /// <returns></returns>
    virtual NhanVien* createNhanVien(const int loaiNV, const string maso, const string hoten, double luongCB) = 0 ;
    /// <summary>
    /// Method ao thuan tuy cac lop con ke thua can trien khai day du
    /// Moi 1 tham so loaiNV
    /// </summary>
    /// <param name="loaiNV"></param>
    /// <returns></returns>
    virtual NhanVien* createNhanVien(const int loaiNV) = 0;
};
```

NhanVienFactory.h

```bash
#pragma once
#include "NhanVien.h"
#include "INhanVienFactory.h"
/// <summary>
/// Ke thua va override INhanVienFactory
/// Factory NhanVien theo loai
/// </summary>
class NhanVienFactory : public INhanVienFactory {
public:
     NhanVienFactory();
     /// <summary>
     /// override INhanVienFactory
     /// </summary>
     /// <param name="loaiNV"></param>
     /// <param name="maso"></param>
     /// <param name="hoten"></param>
     /// <param name="luongCB"></param>
     /// <returns></returns>

     NhanVien* createNhanVien(const int loaiNV, const string maso, const string hoten, double luongCB)override;
     /// <summary>
     /// override INhanVienFactory
     /// </summary>
     /// <param name="loaiNV"></param>
     /// <returns></returns>

     NhanVien* createNhanVien(const int loaiNV) override;
};
```

NhanVienFactory.cpp

```bash
#include "NhanVienFactory.h"
// TODO: insert return statement here
```