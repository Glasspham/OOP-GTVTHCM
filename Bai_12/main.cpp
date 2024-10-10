#include"CauhoiTN.h"

void menu() {
    cout << "\n--------------- Menu ---------------\n";
    cout << "1. Nhap de thi va luu file\n";
    cout << "2. Doc file va thi\n";
    cout << "3. Doc file va xoa khoang trang thua\n";
    cout << "0. Thoat\n";
    cout << "Nhap lua chon: ";
}

void StringProcessing(string& s) {
    if (s.empty()) return;
    while (!s.empty() and s[0] == ' ')
        s.erase(0, 1);
    while (!s.empty() and s[s.size() - 1] == ' ')
        s.erase(s.size() - 1, 1);
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            s.erase(i, 1);
            i--;
        }
    }
}

int main() {
    vector<CauhoiTN> list;
    int choice, questionQuantity;
    string filename;
    ifstream ifs;
    ofstream ofs;
    cout << "079205013990 - Pham Ha Vo\n";
    do {
        menu();
        cin >> choice;
        switch (choice) {
        case 0: {
            cout << "Ket thuc chuong trinh!\n";
            break;
        }
        case 1: {
            cout << "Nhap ten file luu de thi: ";
            cin >> filename;
            ofs.open(filename);
            if (!ofs) {
                cout << "Khong mo duoc file!\n";
                continue;
            }
            cout << "Nhap so luong cau hoi: ";
            cin >> questionQuantity;
            ofs << questionQuantity << endl;
            cin.ignore();
            for (int i = 0; i < questionQuantity; ++i) {
                CauhoiTN cau;
                cout << "Nhap du lieu cho cau hoi thu " << i + 1 << endl;
                cau.nhap();
                bool f = true;
                for (const auto it : list)
                    if (giongnhau(cau, it)) f = false;
                if (f) {
                    list.push_back(cau);
                    cau.ghifile(ofs);
                } else {
                    cout << "Cau nay da co roi! Hay nhap lai cau khac!\n";
                    --i;
                }
            }
            ofs.close();
            list.clear();
            break;
        }
        case 2: {
            cout << "Nhap ten file muon thi: ";
            cin >> filename;
            ifs.open(filename);
            if (!ifs) {
                std::cout << "Khong mo duoc file.\n";
                continue;
            }
            ifs >> questionQuantity;
            ifs.ignore();
            CauhoiTN cau;
            for (int i = 0; i < questionQuantity; ++i) {
                cau.docfile(ifs);
                if (i == 0) cin.ignore();
                cau.kiemtra();
            }
            ifs.close();
            break;
        }
        case 3: {
            cout << "Nhap file can chinh sua: ";
            cin >> filename;
            ifs.open(filename);
            if (!ifs) {
                std::cout << "Khong mo duoc file.\n";
                continue;
            }
            ifs >> questionQuantity;
            ifs.ignore();
            CauhoiTN cau;
            int count = 0;
            for (int i = 0; i < questionQuantity; ++i) {
                cau.docfile(ifs);
                string content = cau.getContent();
                StringProcessing(content);
                cau.setContent(content);
                string answerA = cau.getAnswerA();
                StringProcessing(answerA);
                cau.setAnswerA(answerA);
                string answerB = cau.getAnswerB();
                StringProcessing(answerB);
                cau.setAnswerB(answerB);
                bool f = true;
                for (const auto it : list)
                    if (giongnhau(cau, it)) f = false;
                if (f) list.push_back(cau);
                else ++count;
            }
            ifs.close();
            ofs.open(filename);
            ofs << questionQuantity - count << endl;
            if (!ofs) {
                std::cout << "Khong mo duoc file.\n";
                continue;
            }
            for (const auto& cau : list) cau.ghifile(ofs);
            ofs.close();
            list.clear();
            cout << "Da chinh sua file thanh cong!\n";
            break;
        }
        default:
            cout << "Moi ban lua chon khac!\n";
            break;
        }
    } while (choice != 0);
    return 0;
}