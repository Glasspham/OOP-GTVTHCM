#pragma once
#include"TienThuong.h"
#include<iostream>
#include<string.h>
using namespace std;
/// <summary>
/// Lop NhanVien chua cac thuoc tinh chung
/// Can cac lop con trien khai lai getTienThuong
/// </summary>
class NhanVien {
protected:
    string maso;
    string hoten;
    double luongCB;
    TienThuong* phuongthucTienThuong;
public:
    NhanVien();
    NhanVien(const string maso, const string hoten, double luongCB);
    virtual string toString() const;

    /// <summary>
    /// Moi lop con se co phuong thuc getTienThuong khac nhau
    /// </summary>
    /// <returns></returns>
    virtual double getTienThuong() const = 0;

    // Getters
    string getMaso() const;
    string getHoten() const;
    double getLuongCB() const;
    TienThuong* getPhuongthucTienThuong() const;

    // Setters
    void setMaso(const string& maso);
    void setHoten(const string& hoten);
    void setLuongCB(double luongCB);
    void setPhuongthucTienThuong(TienThuong* phuongthuc);

    /// <summary>
    /// Toan tu chen cho phep xuat NhanVien
    /// FM: Maso: {maso}, HoTen: {hoten}, LuongCB: {luongCB}
    /// </summary>
    /// <param name="out"></param>
    /// <param name="nv"></param>
    /// <returns>ostream</returns>

    friend ostream& operator<< (ostream& out, const NhanVien& nv);
    /// <summary>
    /// Toan tu tach cho phep nhap mot nhan vien
    ///  Maso: {maso}, HoTen: {hoten}, LuongCB: {luongCB}
    /// </summary>
    /// <param name="in"></param>
    /// <param name="nv"></param>
    /// <returns>istream</returns>
    friend istream& operator>> (istream& in, NhanVien& nv);
};