#include "CauhoiTN.h"

CauhoiTN::CauhoiTN() : content(""), answerA(""), answerB(""), result('A') {}

string CauhoiTN::getContent() { return content; }
void CauhoiTN::setContent(string content) { this->content = content; }

string CauhoiTN::getAnswerA() { return answerA; }
void CauhoiTN::setAnswerA(string answerA) { this->answerA = answerA; }

string CauhoiTN::getAnswerB() { return answerB; }
void CauhoiTN::setAnswerB(string answerB) { this->answerB = answerB; }

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

void CauhoiTN::docfile(ifstream &f) {
    getline(f, content);
    getline(f, answerA);
    getline(f, answerB);
    f.get(result);
    f.ignore();
}

void CauhoiTN::ghifile(ofstream &f) const {
    f << content << endl;
    f << answerA << endl;
    f << answerB << endl;
    f << result << endl;
}

void CauhoiTN::kiemtra() const {
    cout << "Cau hoi: " << content << endl;
    cout << "A. " << answerA << endl;
    cout << "B. " << answerB << endl;
    char answer = nhapDapAn();
    if(answer == result) cout << "Dung!\n";
    else cout << "Sai!\n";
    cout << "Dap an de: " << result << endl;
}

bool giongnhau(const CauhoiTN &cau1, const CauhoiTN &cau2) {
    return (cau1.content == cau1.content) and
           (cau1.answerA == cau2.answerA) and
           (cau1.answerB == cau2.answerB) and
           (cau1.result == cau2.result);
}