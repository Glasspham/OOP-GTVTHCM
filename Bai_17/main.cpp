#include"Fraction.h"

int main() {
    srand(time(0));
    Fraction f1(8, 2), f2(100, 0);
    int n; cin >> n;
    Fraction f3(n);
    cout << f1 << endl << f2 << endl << f3;
    return 0;
}