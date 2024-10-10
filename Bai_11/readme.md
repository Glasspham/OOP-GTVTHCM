# Bài tập 1- Chấm tự động

Đọc dữ liệu từ 1 file data.txt.

-   Kiểm tra có bao nhiêu row tồn tại '-' ở đầu.

int CountSymbolInstring(const string& filename, char symBoll);

-   Tính tổng các ký tự là số trong file.

double SumNum(const string& filename);

(gợi ý: sử dụng kiểu string, hàm so sánh string::compare())

**Các tệp được yêu cầu**

*processFile.h*

```bash
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int CountSymbolInstring(const string& filename, char symBoll);

double SumNum(const string& filename);
```
*processFile.cpp*

```bash
#include "processFile.h"
```
