#include "CauhoiTN.h"

CauhoiTN::CauhoiTN() : content(""), answerA(""), answerB(""), result('A') {}

string CauhoiTN::getContent() { return content; }
void CauhoiTN::setContent(string content) { this->content = content; }

string CauhoiTN::getAnswerA() { return answerA; }
void CauhoiTN::setAnswerA(string answerA) { this->answerA = answerA; }

string CauhoiTN::getAnswerB() { return answerB; }
void CauhoiTN::setAnswerB(string answerB) { this->answerB = answerB; }

char CauhoiTN::getResult() { return result; }

char nhapDapAn() {
    string res;
    do {
        cout << "Nhap dap dung (A/B): ";
        getline(cin, res);
        if ((res != "A" and res != "B") or res.size() > 1)
            cout << "Chi duoc nhap 1 ky tu A hoac B\n";
    } while ((res != "A" and res != "B") or res.size() > 1);
    return res[0];
}

void CauhoiTN::nhap() {
    cout << "Nhap noi dung cau hoi: ";
    getline(cin, content);
    cout << "Nhap dap an A: ";
    getline(cin, answerA);
    cout << "Nhap dap an B: ";
    getline(cin, answerB);
    result = nhapDapAn();
}

void CauhoiTN::xuat() const {
    cout << "Cau hoi: " << content << endl;
    cout << "A. " << answerA << endl;
    cout << "B. " << answerB << endl;
    cout << "Dap an de: " << result << endl;
}

void CauhoiTN::docfile(ifstream& f) {
    getline(f, content);
    getline(f, answerA);
    getline(f, answerB);
    f.get(result);
    f.ignore();
}

void CauhoiTN::ghifile(ofstream& f) const {
    f << content << endl;
    f << answerA << endl;
    f << answerB << endl;
    f << result << endl;
}

bool CauhoiTN::kiemtra() const {
    cout << content << endl;
    cout << "A. " << answerA << endl;
    cout << "B. " << answerB << endl;
    char answer = nhapDapAn();
    return answer == result;
}

bool giongnhau(const CauhoiTN& cau1, const CauhoiTN& cau2) {
    return (cau1.content == cau1.content) and
        (cau1.answerA == cau2.answerA) and
        (cau1.answerB == cau2.answerB) and
        (cau1.result == cau2.result);
}

void displayMenu() {
    cout << "\n--------------- Menu ---------------\n";
    cout << "1. Tao de thi moi\n";
    cout << "2. Them cau hoi vao de thi\n";
    cout << "3. In danh sach cau hoi\n";
    cout << "4. Luu danh sach cau hoi ra file\n";
    cout << "5. Doc de thi tu file\n";
    cout << "6. Cho thi va tinh ket qua\n";
    cout << "0. Thoat\n";
    cout << "--------------------------------\n";
    cout << "Moi ban chon: ";
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