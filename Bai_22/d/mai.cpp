#include <iostream>
#include "Dethi.h"
using namespace std;

int main() {
    srand(time(0));
	int n1, n2, n3, level;

	// Người dùng nhập số lượng biểu thức cho từng loại phép toán
	cout << "Enter the number of addition expressions: "; cin >> n1;
	cout << "Enter the number of subtraction expressions: "; cin >> n2;
	cout << "Enter the number of multiplication expressions: "; cin >> n3;
	cout << "Enter starting level (1 to 5): ";
	cin >> level;

	// Khởi tạo đề thi với các biểu thức cộng, trừ, nhân theo yêu cầu
	Dethi dethi(n1, n2, n3, level);

	// Xuất danh sách câu hỏi
	cout << "\nList of questions:\n";
	dethi.xuat();

	cout << "\nStart the exam!\n";
	// Người dùng trả lời các câu hỏi và chương trình đánh giá kết quả
	int correct = dethi.danhgia();

	// Hiển thị kết quả
	cout << "\nNumber of correct answers: " << correct << " / " << (n1 + n2 + n3) << endl;

	return 0;
}
