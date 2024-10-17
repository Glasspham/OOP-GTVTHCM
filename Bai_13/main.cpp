#include "CauhoiTN.h"

int main() {
    vector<CauhoiTN> deThi;
    int choice, questionQuantity;
    string filename;
    ifstream ifs;
    ofstream ofs;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: {
            cout << "Nhap so luong cau hoi: ";
            cin >> questionQuantity;
            cin.ignore();
            for (int i = 0; i < questionQuantity; ++i) {
                cout << "Nhap cau hoi thu " << i + 1 << endl;
                CauhoiTN cau; cau.nhap();
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
                for (const auto it : deThi) if (giongnhau(cau, it)) f = false;
                if (f) deThi.push_back(cau);
                else {
                    cout << "Cau nay da co roi! Hay nhap lai cau khac!\n";
                    --i;
                }
            }
            break;
        }
        case 2: {
            cout << "Nhap them cau hoi moi vao de thi!" << endl;
            ++questionQuantity;
            CauhoiTN cau;
            bool f = true;
            do {
                cau.nhap();
                for (const auto it : deThi) if (giongnhau(cau, it)) f = false;
                if (!f)cout << "Cau nay da co roi! Hay nhap lai cau khac!\n";
            } while (!f);
            deThi.push_back(cau);
            break;
        }
        case 3: {
            if (deThi.empty()) {
                cout << "Trong bo nho khong co de thi!\n";
                continue;
            }
            cout << "Co tat ca " << questionQuantity << " cau hoi.\n";
            cout << "Danh sach cau hoi co trong de thi:\n";
            for (const auto it : deThi)
                it.xuat();
            break;
        }
        case 4: {
            cout << "Nhap ten file luu de thi: ";
            cin >> filename;
            ofs.open(filename);
            if (!ofs) {
                cout << "Khong mo duoc file!\n";
                continue;
            }
            ofs << questionQuantity << endl;
            for (const auto it : deThi)
                it.ghifile(ofs);
            ofs.close();
            cout << "Ghi File thanh cong!\n";
            break;
        }
        case 5: {
            cout << "Nhap ten file de thi: ";
            cin >> filename;
            ifs.open(filename);
            if (!ifs) {
                std::cout << "Khong mo duoc file.\n";
                continue;
            }
            ifs >> questionQuantity;
            ifs.ignore();
            deThi.clear();
            CauhoiTN cau;
            for (int i = 0; i < questionQuantity; ++i) {
                cau.docfile(ifs);
                if (i == 0) cin.ignore();
                deThi.push_back(cau);
            }
            ifs.close();
            cout << "Da luu vao bo nho thanh cong!\n";
            break;
        }
        case 6: {
            cout << "Bat dau thi (dung: +1 / sai: +0)\n";
            int diem = 0;
            for (int i = 0; i < questionQuantity; ++i) {
                cout << "Cau hoi " << i + 1 << ": ";
                if (deThi[i].kiemtra()) {
                    cout << "Dung duoc + 1 diem!\n";
                    ++diem;
                }
                else cout << "Dap an dung la: " << deThi[i].getResult() << endl;
            }
            cout << "Tong so cau dung la: " << diem << endl;
            break;
        }
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le, vui long chon lai.\n";
        }
    } while (choice != 0);
    return 0;
}
