# Lab 3.b - Cài đặt thêm các toán tử một ngôi ++, --

Cài đặt các toán tử một toán hạng ++, --

Thử nghiệm với hàm main sau:

```bash
int main() {
    int test_op;
    cin >> test_op;
    Fraction f1(1,2), f2(2,3), f3(-1,1);
    switch (test_op) {
    case 1:
        cout << f1++ << endl << f2++ << endl << f3++ << endl;
        cout << f1++ << endl << f2++ << endl << f3++ << endl;
        break;
    case 2:
        cout << f1-- << endl << f2-- << endl << f3-- << endl;
        cout << f1-- << endl << f2-- << endl << f3-- << endl;
        break;
    case 3:
        cout << ++f1 << endl << ++f2 << endl << ++f3 << endl;
        cout << ++f1 << endl << ++f2 << endl << ++f3 << endl;
        break;
    case 4:
        cout << --f1 << endl << --f2 << endl << --f3 << endl;
        cout << --f1 << endl << --f2 << endl << --f3 << endl;
        break;
    }
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
