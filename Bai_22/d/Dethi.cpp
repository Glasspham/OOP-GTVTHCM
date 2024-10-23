#include"Dethi.h"

Dethi::Dethi(int n1, int n2, int n3, int level) {
    for(int i = 0; i < n1; ++i) ds.push_back(BieuthucCong(level));
    for(int i = 0; i < n2; ++i) ds.push_back(BieuthucTru(level));
    for(int i = 0; i < n3; ++i) ds.push_back(BieuthucNhan(level));
}

void Dethi::xuat(ostream& output) {
    for(auto it : ds)
        output << it << " = ?\n";
}

int Dethi::danhgia(istream& input) {
    int correct = 0;
    for(auto it : ds){
        cout << it << " = ?\n";
        float answer; input >> answer;
        if(it.kiemtra(answer)) ++correct;
    }
    return correct;
}