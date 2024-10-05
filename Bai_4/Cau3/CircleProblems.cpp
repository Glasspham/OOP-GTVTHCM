/*
a) Đọc một file theo định dạng mô tả ở trên, xuất ra màn hình các đường tròn đọc được, mỗi đường tròn trên một dòng và sắp xếp theo bán kính tăng dần.
b) Xuất ra màn hình các đường tròn chứa trong file có tiếp xúc với ít nhất một đường tròn khác
c) Xuất ra màn hình tổng số Ring tạo được từ các đường tròn trong file, biết rằng hai đường tròn tạo được thành Ring nếu chúng có cùng tâm và khác bán kính.
d) Xuất ra màn hình (các) Ring có độ dày lớn nhất
*/

#include "CircleProblems.h"
#include "Circle.h"
#include "Ring.h"
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void CircleProblems::ProblemA(const string filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }

    vector<Circle> circles;
    Circle circle;
    while (inFile >> circle) {
        circles.push_back(circle);
    }
    inFile.close();

    // Sắp xếp các đường tròn theo bán kính tăng dần
    sort(circles.begin(), circles.end(), [](const Circle& c1, const Circle& c2) {
        return c1.getR() < c2.getR();
    });

    // Xuất các đường tròn đã đọc được
    for (const auto& c : circles) {
        cout << c << endl;
    }
}

void CircleProblems::ProblemB(const string filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }

    vector<Circle> circles;
    Circle circle;
    while (inFile >> circle) {
        circles.push_back(circle);
    }
    inFile.close();

    cout << "Circles with at least one tangent circle:" << endl;
    for (size_t i = 0; i < circles.size(); ++i) {
        for (size_t j = i + 1; j < circles.size(); ++j) {
            if (circles[i] ^ circles[j]) {
                cout << circles[i] << " and " << circles[j] << " are tangent circles." << endl;
            }
        }
    }
}

void CircleProblems::ProblemC(const string filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }

    vector<Circle> circles;
    Circle circle;
    while (inFile >> circle) {
        circles.push_back(circle);
    }
    inFile.close();

    int ringCount = 0;
    for (size_t i = 0; i < circles.size(); ++i) {
        for (size_t j = i + 1; j < circles.size(); ++j) {
            if (circles[i].getX() == circles[j].getX() && circles[i].getY() == circles[j].getY() &&
                circles[i].getR() != circles[j].getR()) {
                ringCount++;
            }
        }
    }

    cout << "Total number of Rings: " << ringCount << endl;
}

void CircleProblems::ProblemD(const string filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }

    vector<Circle> circles;
    Circle circle;
    while (inFile >> circle) {
        circles.push_back(circle);
    }
    inFile.close();

    int maxThickness = 0;
    vector<Ring> maxThicknessRings;

    for (size_t i = 0; i < circles.size(); ++i) {
        for (size_t j = i + 1; j < circles.size(); ++j) {
            if (circles[i].getX() == circles[j].getX() && circles[i].getY() == circles[j].getY() &&
                circles[i].getR() != circles[j].getR()) {
                int thickness = abs(circles[i].getR() - circles[j].getR());
                if (thickness > maxThickness) {
                    maxThickness = thickness;
                    maxThicknessRings.clear();
                    maxThicknessRings.emplace_back(circles[i], circles[j].getR());
                } else if (thickness == maxThickness) {
                    maxThicknessRings.emplace_back(circles[i], circles[j].getR());
                }
            }
        }
    }

    cout << "Max Thickness Rings:" << endl;
    for (const auto& ring : maxThicknessRings) {
        cout << ring << endl;
    }
}
