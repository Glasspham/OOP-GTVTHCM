#include <iostream>
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"
using namespace std;

void Result(bool res, float ans) {
	if (res) cout << "Correct!" << endl;
    else cout << "Wrong! The correct answer was: " << ans << endl;
	cout << "--------------------" << endl;
}

int main() {
	srand(time(0));
	while(1) {
		int level; 
		cout << "Nhap vao level: " << endl;
		// Test BieuthucCong
		cout << "Test BieuthucCong:" << endl;
		BieuthucCong btCong(level);
		cout << btCong << " = ?\n";
		float answer;
		cin >> answer;
		Result(btCong.kiemtra(answer), btCong.giatri());

		// Test BieuthucTru
		cout << "Test BieuthucTru:" << endl;
		BieuthucTru btTru(level);
		cout << btTru << " = ?\n";
		cin >> answer;
		Result(btTru.kiemtra(answer), btTru.giatri());

		// Test BieuthucNhan
		cout << "Test BieuthucNhan:" << endl;
		BieuthucNhan btNhan(level);
		cout << btNhan << " = ?\n";
		cin >> answer;
		Result(btNhan.kiemtra(answer), btNhan.giatri());
	}
    return 0;
}