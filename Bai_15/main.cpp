#include"Menu.h"

int main() {
    Menu menu("Menu chinh");
    menu << "Chuc nang 0";
    menu << "Chuc nang 1" << "Chuc nang 2";
    int luachon = menu.chon();
    cout << luachon << endl;
}