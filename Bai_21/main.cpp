#include"Fraction.h"

int main() {
    string filename; cin >> filename;
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "Mo file that bai!\n";
        return 0;
    }
    int n, cnt_max = 0, cnt_min = 0;
    Fraction fmax, fmin;
    ifs >> n;
    for (int i = 0; i < n; ++i) {
        Fraction f; ifs >> f;
        // Tìm max
        if (fmax < f) {
            fmax = f;
            cnt_max = 1;
        } else if (f == fmax) ++cnt_max;
        // Tìm min
        if (fmin > f) {
            fmin = f;
            cnt_min = 1;
        } else if (f == fmin) ++cnt_min;
    }
    cout << cnt_max << ' ' << fmax << endl;
    cout << cnt_min << ' ' << fmin << endl;
    return 0;
}