#pragma once
#ifndef BIEUTHUCPT_H
#define BIEUTHUCPT_H
#include "Bieuthuc.h"
#include <iostream>
using namespace std;

class BieuthucPT : public Bieuthuc {
private:
    //..Bổ sung thêm dữ liệu để lưu trữ được (a # b) # (c # d)
    Bieuthuc *bt1, *bt2;
public:
    BieuthucPT(int level); // overide để sinh ngẫu nhiên được dạng biểu thức mới, quy luật sinh như sinh lớp Bieuthuc
    ~BieuthucPT();
    friend ostream& operator<<(ostream& out, BieuthucPT bt); // overide để xuất dạng biểu thức mới
    bool kiemtra(float traloi); // overide...
    float giatri(); // overide...
};
#endif