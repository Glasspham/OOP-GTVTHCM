#include "BieuthucPT.h"

int main() {
    srand(time(0));
    while(1) {
        int level; cin >> level;
        BieuthucPT bt(level);
        cout << bt << " = ?\n";
        float answer; cin >> answer;
        cout << bt.kiemtra(answer) << endl;
    }
}