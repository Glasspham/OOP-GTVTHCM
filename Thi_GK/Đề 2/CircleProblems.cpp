#include "CircleProblems.h"
#include "Circle.h"
#include "Ring.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

// Hàm a) Đọc file và hiển thị các đường tròn theo bán kính tăng dần
void CircleProblems::ProblemA(const std::string filename) {
    std::ifstream file(filename);
    if(!file) {
        std::cerr << "Khong the mo file " << filename << std::endl;
        return;
    }

    int n; file >> n; // Đọc số lượng đường tròn
    std::vector<Circle> circles;

    // Đọc dữ liệu đường tròn từ file
    for(int i = 0; i < n; i++) {
        Circle c; file >> c;
        circles.push_back(c);
    }

    file.close();

    // Hiển thị các đường tròn vừa đọc từ file
    std::cout << "Danh sach cac duong tron doc duoc tu file:\n";
    for(const auto& c : circles) std::cout << c << std::endl;

    // Sắp xếp các đường tròn theo bán kính tăng dần
    std::sort(circles.begin(), circles.end());

    // Xuất ra màn hình danh sách đường tròn đã sắp xếp theo bán kính tăng dần
    std::cout << "\nDanh sach cac duong tron da sap xep theo ban kinh tang dan:\n";
    for(const auto& c : circles) std::cout << c << std::endl;
}

// Hàm b) Xuất ra các đường tròn có tiếp xúc với ít nhất một đường tròn khác
void CircleProblems::ProblemB(const std::string filename) {
    std::ifstream file(filename);
    if(!file) {
        std::cerr << "Khong the mo file " << filename << std::endl;
        return;
    }

    int n; file >> n;
    std::vector<Circle> circles;

    for(int i = 0; i < n; i++) {
        Circle c; file >> c;
        circles.push_back(c);
    }

    file.close();

    std::cout << "\nCac duong tron co tiep xuc voi it nhat mot duong tron khac:\n";
    for(size_t i = 0; i < circles.size(); i++)
        for(size_t j = i + 1; j < circles.size(); j++)
            if(circles[i] ^ circles[j]) // Kiểm tra tiếp xúc
                std::cout << circles[i] << " tiep xuc voi " << circles[j] << std::endl;
}

// Hàm c) Xuất ra tổng số Ring tạo được từ các đường tròn có cùng tâm và khác bán kính
void CircleProblems::ProblemC(const std::string filename) {
    std::ifstream file(filename);
    if(!file) {
        std::cerr << "Khong the mo file " << filename << std::endl;
        return;
    }

    int n; file >> n;
    std::vector<Circle> circles;

    for(int i = 0; i < n; i++) {
        Circle c;
        file >> c;
        circles.push_back(c);
    }

    file.close();

    int ringCount = 0;
    for(size_t i = 0; i < circles.size(); i++) 
        for(size_t j = i + 1; j < circles.size(); j++) 
            if(circles[i] == circles[j] && circles[i].getR() != circles[j].getR()) 
                ringCount++;
    std::cout << "\nTong so Ring co the tao duoc: " << ringCount << std::endl;
}

// Hàm d) Xuất ra các Ring có độ dày lớn nhất
void CircleProblems::ProblemD(const std::string filename) {
    std::ifstream file(filename);
    if(!file) {
        std::cerr << "Khong the mo file " << filename << std::endl;
        return;
    }

    int n; file >> n;
    std::vector<Ring> rings;

    // Tạo Ring từ các đường tròn trong file (các cặp có cùng tâm và khác bán kính)
    std::vector<Circle> circles;
    for(int i = 0; i < n; i++) {
        Circle c;
        file >> c;
        circles.push_back(c);
    }

    file.close();

    for(size_t i = 0; i < circles.size(); i++)
        for(size_t j = i + 1; j < circles.size(); j++)
            if(circles[i] == circles[j] && circles[i].getR() != circles[j].getR())
                rings.emplace_back(circles[i], circles[j].getR());

    // Tìm Ring có độ dày lớn nhất
    if(rings.empty()) {
        std::cout << "\nKhong co Ring nao duoc tao ra.\n";
        return;
    }

    int maxWidth = rings[0].width();
    for(const auto& ring : rings)
        if(ring.width() > maxWidth) 
            maxWidth = ring.width();

    // Xuất các Ring có độ dày lớn nhất
    std::cout << "\nCac Ring co do day lon nhat (" << maxWidth << "):\n";
    for(const auto& ring : rings) 
        if(ring.width() == maxWidth)
            std::cout << ring << std::endl;
}