/*
Sử dụng kiểu dữ liệu vector và map, giải quyết bài toán sau.
Nhập vào một mảng các số nguyên
a) Đếm xem có bao nhiêu giá trị nguyên khác nhau trong mảng
b) In ra màn hình số lần xuất hiện giá trị của các phần tử trong mảng
c) In ra danh sách các giá trị khác nhau trong mảng, và các vị trí xuất hiện của chúng
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Nhập mảng các số nguyên
    vector<int> arr = { 1, 2, 3, 1, 2, 4, 5, 3, 6 };

    // Map để lưu số lần xuất hiện của mỗi giá trị
    map<int, int> value_counts;

    // Duyệt qua mảng và cập nhật map value_counts
    for (int value : arr) {
        value_counts[value]++;
    }

    // Đếm số lượng giá trị nguyên khác nhau
    cout << "So luong gia tri khac nhau: " << value_counts.size();

    // In số lần xuất hiện của giá trị các phần tử
    cout << "so lan xuat hien cac gia tri cua phan tu:\n";
    for (auto pair : value_counts) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // In danh sách các giá trị khác nhau và vị trí xuất hiện
    cout << "\ndanh sach cac gia tri khac nhau va vi tri xuat hien:\n";
    vector<int> distinct_values;
    for (auto pair : value_counts) {
        distinct_values.push_back(pair.first);
    }

    for (int value : distinct_values) {
        cout << value << ": ";
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == value) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}