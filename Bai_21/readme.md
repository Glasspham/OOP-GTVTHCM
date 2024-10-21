Cài đặt các toán tử tách >> và viết chương trình chính main() có nhiệm vụ đọc một file dữ liệu gồm N số nguyên từ một file có tên nhập từ bàn phím.

Đếm và in ra màn hình phân số có giá trị lớn nhất, giá trị nhỏ nhất trong file.

Định dạng file qui ước như sau:

Dòng 1: chứa một số nguyên là tổng số phần tử trong file

Các dòng tiếp theo chứa các tử số và mẫu số của phân số

Ví dụ: File sau chứa 5 phân số 1/2, -3/2, 1/2, 10/1 và 7/9

```bash
5
1 2
-3 2
1 2
10 1
7 9
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

**main.cpp**

```bash
#include <iostream>
#include <string>
using namespace std;

int main() {
    string filename;
    cin >> filename;

    return 0;
}
```
