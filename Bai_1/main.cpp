#include"Fraction.h"

#if 0 // !Để test class Phần I xây xong đúng chưa. Không cần quan tâm
int main() {
    Fraction a, b;
    cout << "Enter fraction a: ";
    cin >> a;
    cout << "Enter fraction a: ";
    cin >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    return 0;
}
#endif

#if 1 // !Phần B
int main() {
    // !a
    cout << "Enter n: ";
    int n; cin >> n;
    Fraction fractions[100];
    for (int i = 0; i < 100; ++i)
        fractions[i] = Fraction(n);

    // !b
    cout << "All fractions less than or equal to 1/2: ";
    Fraction half(1, 2); // Khởi tạo phân số 1/2
    for (int i = 0; i < 100; ++i)
        if (fractions[i] <= half)
            cout << fractions[i] << " ";
    cout << endl;

    // !c
    cout << "All unique fractions:";
    for (int i = 0; i < 100; ++i) {
        bool isUnique = true;
        for (int j = i + 1; j < 100; ++j) {
            if (fractions[i] == fractions[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) cout << fractions[i] << " ";
    }

    return 0;
}
#endif