#pragma once
#ifndef POINTMANAGEMENT_H
#define POINTMANAGEMENT_H
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

class pointManagement {
private:
    string MSSV, name;
    int sbv;
    float DiemTH, DiemGK, DiemQT;

public:
    pointManagement();
    pointManagement(string MSSV, string name, int sbv, float DiemTH, float DiemGK, float DiemQT);

    void setMSSV(string MSSV);
    string getMSSV();

    void setName(string name);
    string getName();

    void setSBV(int sbv);
    int getSBV();

    void setDiemTH(float DiemTH);
    float getDiemTH();

    void setDiemGK(float DiemGK);
    float getDiemGK();

    float getDiemQT();

    friend istream& operator >> (istream& in, pointManagement& sv);
    friend ostream& operator << (ostream& out, pointManagement sv);
};

void printMenu();
void printLine(char c);
void printTitle();
void nhapDanhSach(vector<pointManagement>& ds);
void xuatDanhSach(const vector<pointManagement>& ds);
void ghiFile(ofstream& f, vector<pointManagement> ds);
void docFile(ifstream& f, vector<pointManagement>& ds);
void inSinhVienDuDieuKien(vector<pointManagement> ds);
void inSinhVienHoNguyen(vector<pointManagement> ds);
void inSinhVienTrungTen(vector<pointManagement> ds);
#endif