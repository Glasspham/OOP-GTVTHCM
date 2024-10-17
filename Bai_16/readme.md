C++ có cài đặt sẵn giải thuật sắp xếp, tuy nhiên muốn dùng được trên các đối tượng tự định nghĩa thì cần phải cài đặt toán tử so sánh <. Yêu cầu bài này là thiết kế lớp Point (x,y) và cài đặt toán tử so sánh các khoảng cách đến gốc tọa độ (0,0).

Viết chương trình đọc các điểm có tọa độ (x,y) với (x, y là các số thực) từ một file văn bản và in ra màn hình thứ tự các điểm đã được sắp xếp tăng dần theo khoảng cách đến gốc tọa độ.

Định dạng file nhập như sau:

1. Dòng đầu tiên: số điểm có trong file

2. Các dòng tiếp theo là các điểm với tọa độ x, y (giá trị x, y cách nhau bởi khoảng trắng)

Ví dụ file sau chứa thông tin 3 điểm

3

0.5   0.5

1.2   4.2

10   5

Lưu ý: Cho trước chương trình chính trong file Main.cpp, chỉ cài đặt hai file Point.h và Point.cpp để thực thi được yêu cầu trên.
File main.cpp có nội dung như sau:
```
#include <iostream>
#include <fstream>
#include "Point.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //Doc file data.txt
    ifstream fi("data.txt");
    int n;
    fi >> n; //doc so luong diem
    vector<Point> lstPoint;
    for (int i = 0; i < n; i++)
    {
        Point* ptr=new Point(0,0);
        fi >> *ptr;
        lstPoint.push_back(*ptr);
    }
    fi.close();
    //Sap xep theo khoang cach den goc toa do O(0,0)
    sort(lstPoint.begin(), lstPoint.end());
    //In ra các diem theo dinh dang (x1,y) (x2,y2)... (xn,yn)
    for (int i = 0; i < n; i++)
        cout << lstPoint[i] << " ";
    return 0;
}
```
**Các tệp được yêu cầu**
Point.h
```bash
#pragma once
class Point
{
    
};
```
Point.cpp
```bash
#include "Point.h"
```