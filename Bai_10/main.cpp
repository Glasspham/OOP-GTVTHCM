#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

int main() {
	ifstream ifile("data.txt");
	if (!ifile.is_open()) {
		cerr << "Khong the mo file." << endl;
		return 1;
	}
	cout << "079205013990 - Pham Ha Vo\n";
	string str;
	vector<string> list;
	int count = 0;
	while (getline(ifile, str)) {
		++count;
		if(!str.empty() and str[0] == '-')
			list.push_back(str);
	}
	ifile.close();
	cout << "So dong trong file: " << count << endl;
	cout << "Nhung dong co '-' dau tien:\n";
	for (string str : list)
		cout << str << endl;
}