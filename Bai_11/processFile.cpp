#include"processFile.h"

int CountSymbolInstring(const string& filename, char symBoll) {
    ifstream ifile(filename);
	string str;
	int count = 0;
	while(getline(ifile, str)) {
		if(!str.empty() and str[0] == '-')
			++count;
	}
	ifile.close();
	return count;
}

double SumNum(const string& filename) {
	ifstream ifile(filename);
	char c;
	double sum = 0.0;
	while (ifile.get(c))
		if (isdigit(c))
			sum += c - '0';
	ifile.close();
	return sum;
}