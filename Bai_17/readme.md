# Lab 3.a - Xây dựng lớp phân số Fraction có các hàm khởi tạo và toán tử xuất.

Cài đặt hàm khởi tạo và toán tử chèn như sau:

Fraction(int num, int den);// khởi tạo phân số num/den; lưu ý nếu giá trị không hợp lệ (ví dụ 5/0) thì phân số sẽ khởi tạo thành 0/1

Fraction(int random);// khởi tạo phân số với giá trị ngẫu nhiên của tử và mẫu không vượt quá giá trị random

operator<<;// xuất phân số theo dạng num/den với đối tượng ostream

```bash
#include <iostream>
#include <fstream>
#include <vector>
#include "Fraction.h"
using namespace std;

int main() {
    srand(time(0));
    Fraction f1(1, 2), f2(100, 0);
    int n; cin >> n;
    Fraction f3(n);
    cout << f1 << endl << f2 << endl << f3;
    return 0;
}
```

## Các tệp được yêu cầu

**Fraction.h**

```bash
#pragma once
#include <iostream>
using namespace std;
class Fraction {
private:
	// Tu so
	int numerator;
	// Mau so
	int denominator;
public:

};
```

**Fraction.cpp**

```bash
#include "Fraction.h"
```
