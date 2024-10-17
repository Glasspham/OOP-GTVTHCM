#pragma once
#ifndef CAUHOITN_H
#define CAUHOITN_H

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class CauhoiTN {
private:
	string content, answerA, answerB;
	char result;
public:
	CauhoiTN();
	string getContent();
	void setContent(string content);
	string getAnswerA();
	void setAnswerA(string answerA);
	string getAnswerB();
	void setAnswerB(string answerB);
	char getResult();
	void nhap();
	void xuat() const;
	void docfile(ifstream& f);
	void ghifile(ofstream& f) const;
	bool kiemtra() const;
	friend bool giongnhau(const CauhoiTN& cau1, const CauhoiTN& cau2);
};

void displayMenu();
void StringProcessing(string& s);
#endif