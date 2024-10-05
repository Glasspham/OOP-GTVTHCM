```
class Fraction
{
    private:
    int numerator; // Tử số
    int denominator; // Tử số
    public:
    Fraction();
    Fraction(int num, int dem);
    void setNumerator(int numerator); // Thiết lập tử số
    void setDenominator(int denominator); // Thiết lập mẫu số
    int getNumerator(); // Trả về tử số
    int getDenominator(); // Trả về mẫu số();
    void show(); // Xuất phân số ra màn hình theo dạng a/b
    void input(); // Nhập một phân số từ bàn phím dạng a/b
    void simplify(); // Tối giản phân số
    const Fraction add(const Fraction &other) const; // Cài đặt phép toán cộng
};
```

**Thử nghiệm với hàm main sau:**

```
int main(){
    //Yêu cầu: Nhập 2 phân số, tính tổng, và xuất ra màn hình
    Fraction f1, f2;
    cout << "Nhap phan so f1: ";
    f1.input();
    cout << "Nhap phan so f2: ";
    f2.input();
    Fraction tong = f1.add(f2);//f1+f2
    tong.simplify();
    cout << "Tong cua f1 va f2 la: ";
    tong.show();
}
```

**Lưu ý, khi nộp chỉ upload các file Fraction.h và Fraction.cpp, hàm main() đã có sẵn trên hệ thống**

**Các tệp được yêu cầu**
_File Fraction.h_

```
#pragma once
class Fraction
{
private:
	// Tử số
	int numerator;
	// Mẫu số
	int denominator;
public:
	Fraction();
	Fraction(int num, int dem);
	// Thiết lập tử số
	void setNumerator(int numerator);
	// Thiết lập mẫu số
	void setDenominator(int denominator);
	// Trả về tử số
	int getNumerator();
	// Trả về mẫu số();
	int getDenominator();
	// Xuất phân số
	void show();
	// Nhập một phân số
	void input();
	// Tối giản phân số
	void simplify();
	// Cài đặt phép toán trên phân số
	const Fraction add(const Fraction &other) const;
};
```

_File Fraction.cpp_

```
#include "Fraction.h"
#include <iostream>

using namespace std;
```
