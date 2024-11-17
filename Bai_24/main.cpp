#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main() {
    int n; cin >> n;
    map<int,vector<int>> mp;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        mp[x].push_back(i);
    }
    cout << "a) So gia tri khac nhau trong mang: " << mp.size() << endl;
    cout << "b) In ra man hinh so lan xuat hien gia tri cua cac phan tu trong mang:\n";
    for(auto it : mp) 
        cout << it.first << " : " << it.second.size() << endl;
    cout << "c) In ra danh sach cac gia tri khac nhau trong mang, va cac vi tri xuat hien cua chung:\n";
    for(auto it : mp) {
        cout << it.first << " : ";
        for(int i : it.second)
            cout << i << ' ';
        cout << endl;
    }
}