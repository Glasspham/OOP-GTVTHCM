Cài đặt thêm toán tử chèn cho lớp Menu có trong source code đính kèm và thay các lệnh thêm lựa chọn cho menu ở chương trình main() bằng cách dùng toán tử chèn.

**Ví dụ:**

menu << "Chuc nang 0";

menu << "Chuc nang 1" << "Chuc nang 2";

Lưu ý chỉ upload hai file Menu.h và Menu.cpp

**Các tệp được yêu cầu**

Menu.h
```bash
#pragma once
#include <vector>
#include <string>

using namespace std;

class Menu
{
private:
	string tieude;
	vector<string> dsLuachon; //danh sach cac lua chon
public:
	Menu(string tieude);
	void themLuachon(string luachon);//them mot chuc nang cho thuc don
	void xuat();//xuat danh sach cac lua chon
	int chon();// xuat danh sach cac muc va cho nguoi dung nhap lua chon
};
```
Menu.cpp
```bash
#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(string tieude)
{
    this->tieude = tieude;
}

void Menu::themLuachon(string luachon)
{
    dsLuachon.push_back(luachon);
}

void Menu::xuat()
{
    cout << "\n-----"<< tieude <<"-----\n";
    for (int i = 0; i < dsLuachon.size(); i++)
        cout << i << ". " << dsLuachon[i] << endl;
}

int Menu::chon()
{
    int ch;
    do {
        xuat();
        cout << "Moi chon?";
        cin >> ch;
        //xoa ky tu xuong dong de cac lenh getline sau nay khong bi anh huong
        string tmp;
        getline(cin, tmp);
        if (ch < 0 || ch >= dsLuachon.size())
            cout << "Chon sai, moi chon lai!!!\n";
    } while (ch<0 || ch>=dsLuachon.size());//Lap lai neu user chon sai
    return ch;
}
```