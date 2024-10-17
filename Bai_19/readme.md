# Lab 3.c - Cài đặt thêm các toán tử hai ngôi +, -, \*, /

Cài đặt các toán tử hai toán hạng +, -, \*, /

Thử nghiệm với hàm main sau:

```bash
int main() {
    char test_op = '+';
    cin >> test_op;
    Fraction f1(1,2), f2(2,3), f3(-1,1);
    switch (test_op) {
    case '+':
        cout << f1 << " + " << f2 << "=" << f1 + f2 << endl;
        cout << f1 << " + " << f3 << "=" << f1 + f3 << endl;
        break;
    case '-':
        cout << f1 << " - " << f2 << "=" << f1 - f2 << endl;
        cout << f1 << " - " << f3 << "=" << f1 - f3 << endl;
        break;
    case '*':
        cout << f1 << " * " << f2 << "=" << f1 * f2 << endl;
        cout << f1 << " * " << f3 << "=" << f1 * f3 << endl;
        break;
    case '/':
        cout << f1 << " / " << f2 << "=" << f1 / f2 << endl;
        cout << f1 << " / " << f3 << "=" << f1 / f3 << endl;
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
