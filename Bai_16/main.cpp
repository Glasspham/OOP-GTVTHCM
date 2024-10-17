#include <iostream>
#include <fstream>
#include "Point.h"
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    //Doc file data.txt
    ifstream fi("data.txt");
    int n;
    fi >> n; //doc so luong diem
    vector<Point> lstPoint;
    for (int i = 0; i < n; i++)
    {
        Point* ptr=new Point(0,0);
        fi >> *ptr;
        lstPoint.push_back(*ptr);
    }
    fi.close();
    //Sap xep theo khoang cach den goc toa do O(0,0)
    sort(lstPoint.begin(), lstPoint.end());
    //In ra các diem theo dinh dang (x1,y) (x2,y2)... (xn,yn)
    for (int i = 0; i < n; i++)
        cout << lstPoint[i] << " ";
    return 0;
}