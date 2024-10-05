#include"Fraction.h"
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
