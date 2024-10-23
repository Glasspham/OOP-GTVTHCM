#include "BieuthucPS.h"

int main() {
    srand(time(0));
    while(1) {
        int level; cin >> level;
        BieuthucPS bt(level);
        cout << bt << " = ?\n";
        cout << bt.giatri() << endl;
    }
}