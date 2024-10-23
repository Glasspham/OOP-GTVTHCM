#pragma once
#ifndef BIEUTHUC_H
#define BIEUTHUC_H
#include <iostream>
using namespace std;

class Bieuthuc {
protected:
	int a, b;
	char pheptoan; // +, -, *
public:
	Bieuthuc(int level);
	friend ostream& operator << (ostream& out, Bieuthuc bt);
	bool kiemtra(float traloi);
	float giatri();
};
#endif