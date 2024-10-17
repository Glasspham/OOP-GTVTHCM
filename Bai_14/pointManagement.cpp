#include"pointManagement.h"

pointManagement::pointManagement() : MSSV(""), name(""), sbv(0), DiemTH(0.0), DiemGK(0.0), DiemQT(0.0) {};

pointManagement::pointManagement(string MSSV, string name, int sbv, float DiemTH, float DiemGK, float DiemQT) :
    MSSV(MSSV), name(name), sbv(sbv), DiemTH(DiemTH), DiemGK(DiemGK), DiemQT(DiemQT) {};

void pointManagement::setMSSV(string MSSV) { this->MSSV = MSSV; }
string pointManagement::getMSSV() { return this->MSSV; }

void pointManagement::setName(string name) { this->name = name; }
string pointManagement::getName() { return this->name; }

void pointManagement::setSBV(int sbv) { this->sbv = sbv; }
int pointManagement::getSBV() { return this->sbv; }

void pointManagement::setDiemTH(float DiemTH) { this->DiemTH = DiemTH; }
float pointManagement::getDiemTH() { return this->DiemTH; }

void pointManagement::setDiemGK(float DiemGK) { this->DiemGK = DiemGK; }
float pointManagement::getDiemGK() { return this->DiemGK; }

float pointManagement::getDiemQT() { return this->DiemQT; }

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
    if (islower(s[0]))
        s[0] = toupper(s[0]);
    for (size_t i = 1; i <= s.size(); ++i) {
        if (s[i - 1] == ' ')
            s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
}

float nhapDiem() {
    float diem;
    do {
        cin >> diem;
        if (0 < diem and diem > 10)
            cout << "Nhap sai, chi duoc trong doan [0,10]!\nHay nhap lai o day: ";
    } while (0 < diem and diem > 10);
    return diem;
}

float tinhDiemQT(const int sbv, const float DiemTH, const float DiemGK) {
    if (sbv > 5) return 0.0;
    return (10 - sbv * 2) * 0.2 + DiemTH * 0.3 + DiemGK * 0.5;
}

istream& operator >> (istream& in, pointManagement& sv) {
    if (&in == &cin) {
        in.ignore();
        cout << "Nhap ma sinh vien: ";
        getline(in, sv.MSSV);
        cout << "Nhap ten sinh vien: ";
        getline(in, sv.name);
        cout << "So luong buoi vang hoc: ";
        in >> sv.sbv;
        cout << "Nhap diem thuc hanh: ";
        sv.DiemTH = nhapDiem();
        cout << "Nhap diem thuc giua ki: ";
        sv.DiemGK = nhapDiem();
    } else {
        in >> sv.MSSV;
        in.ignore();
        getline(in, sv.name);
        in >> sv.sbv >> sv.DiemTH >> sv.DiemGK;
    }
    StringProcessing(sv.name);
    sv.DiemQT = tinhDiemQT(sv.sbv, sv.DiemTH, sv.DiemGK);
    return in;
}

ostream& operator << (ostream& out, pointManagement sv) {
    if (&out == &cout) {
        out << left << setw(14) << sv.MSSV
            << setw(20) << sv.name
            << setw(5) << sv.sbv
            << fixed << setprecision(2)
            << setw(9) << sv.DiemTH
            << setw(9) << sv.DiemGK
            << setw(9) << sv.DiemQT << endl;
    }
    else {
        out << sv.MSSV << endl
            << sv.name << endl
            << sv.sbv << endl
            << sv.DiemTH << endl
            << sv.DiemGK << endl;
    }
    return out;
}

void printMenu() {
    cout << "\n==================== MENU ====================\n";
    cout << "1. Nhap danh sach sinh vien\n";
    cout << "2. Xuat danh sach sinh vien\n";
    cout << "3. Ghi danh sach sinh vien vao file\n";
    cout << "4. Doc danh sach sinh vien tu file\n";
    cout << "5. In danh sach sinh vien du dieu kien du thi\n";
    cout << "6. In danh sach sinh vien co ho 'Nguyen'\n";
    cout << "7. In danh sach sinh vien co ten trung nhau\n";
    cout << "0. Thoat\n";
    printLine('=');
    cout << "Nhap lua chon: ";
}

void printLine(char c) {
    cout << string(46, c) << endl;
}

void printTitle() {
    cout << left << setw(14) << "MSSV"
        << setw(20) << "Ho ten"
        << setw(5) << "SBV"
        << setw(9) << "DiemTH"
        << setw(9) << "DiemGK"
        << setw(9) << "DiemQT" << endl;  // Thêm cột DiemQT
}

void nhapDanhSach(vector<pointManagement>& ds) {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    ds.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        cin >> ds[i];
    }
}

void xuatDanhSach(const vector<pointManagement>& ds) {
    for (const auto& sv : ds)
        cout << sv;
}

void ghiFile(ofstream& f, vector<pointManagement> ds) {
    f << ds.size() << endl;
    for (auto sv : ds)
        f << sv;
}

void docFile(ifstream& f, vector<pointManagement>& ds) {
    int soluong; f >> soluong;
    for (int i = 0; i < soluong; ++i) {
        pointManagement sv; f >> sv;
        ds.push_back(sv);
    }
}

void inSinhVienDuDieuKien(vector<pointManagement> ds) {
    cout << "Danh sach sinh vien du dieu kien du thi (DiemQT >= 3):\n";
    vector<pointManagement> list;
    for (auto sv : ds)
        if (sv.getDiemQT() >= 3)
            list.push_back(sv);
    printTitle();
    xuatDanhSach(list);
}

void inSinhVienHoNguyen(vector<pointManagement> ds) {
    cout << "Danh sach sinh vien co ho 'Nguyen':\n";
    vector<pointManagement> list;
    for (auto sv : ds) {
        string fullName = sv.getName();
        string ho = fullName.substr(0, fullName.find(' '));
        if (ho == "Nguyen")
            list.push_back(sv);
    }
    printTitle();
    xuatDanhSach(list);
}

void inSinhVienTrungTen(vector<pointManagement> ds) {
    cout << "Danh sach sinh vien co ten trung nhau:\n";
    vector<pair<string,vector<pointManagement>>> list;
    for (size_t i = 0; i < ds.size(); ++i) {
        string fullName = ds[i].getName();
        string ten = fullName.substr(fullName.rfind(' ') + 1);
        bool f = true;
        for (auto &it : list) {
            if (ten == it.first) {
                it.second.push_back(ds[i]);
                f = false;
                break;
            }
        }
        if (f) {
            vector<pointManagement> temp = {ds[i]};
            list.push_back({ten, temp});
        }
    }
    printTitle();
    for (const auto &it : list) {
        if (it.second.size() > 1) {
            cout << "Nhung ban co cung ten: " << it.first << endl;
            xuatDanhSach(it.second);
        }
    }
}