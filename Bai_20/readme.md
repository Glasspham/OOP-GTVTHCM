# Lab 3.d - Cài đặt thêm các toán tử so sánh

Cài đặt các toán tử hai toán hạng ==, !=, <, >/

Thử nghiệm với hàm main sau:

```bash
int main() {
    int test_op;
    cin >> test_op;
    switch (test_op) {
    case 1:
        cout << (Fraction(1, 2) == Fraction(1, 3)) << endl;
        cout << (Fraction(1, 2) == Fraction(2, 4)) << endl;
        break;
    case 2:
        cout << (Fraction(1, 2) != Fraction(1, 3)) << endl;
        cout << (Fraction(1, 2) != Fraction(2, 4)) << endl;
        break;
    case 3:
        cout << (Fraction(1, 2) > Fraction(1, 3)) << endl;
        cout << (Fraction(1, 2) > Fraction(2, 4)) << endl;
        break;
    case 4:
        cout << (Fraction(1, 2) < Fraction(1, 3)) << endl;
        cout << (Fraction(1, 2) < Fraction(2, 4)) << endl;
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
