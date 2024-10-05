#pragma once
#include <iostream>
using namespace std;
class Fraction{
private:
	int numerator;	 // Tử số
	int denominator; // Tử số
public:
	Fraction();
	Fraction(int num, int dem);
	void setNumerator(int numerator);				 // Thiết lập tử số
	void setDenominator(int denominator);			 // Thiết lập mẫu số
	int getNumerator();								 // Trả về tử số
	int getDenominator();							 // Trả về mẫu số();
	void show();									 // Xuất phân số ra màn hình theo dạng a/b
	void input();									 // Nhập một phân số từ bàn phím dạng a/b
	void simplify();								 // Tối giản phân số
	const Fraction add(const Fraction &other) const; // Cài đặt phép toán cộng
};