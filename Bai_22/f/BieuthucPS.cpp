#include "BieuthucPS.h"

BieuthucPS::BieuthucPS(int level) : Bieuthuc(level) {
    if(level == 1) {
        p1 = Fraction(rand() % 11, rand() % 11);
        p2 = Fraction(rand() % 11, rand() % 11);
        pheptoan = '+';
    } else if(level == 2) {
        p1 = Fraction(rand() % 11, rand() % 11);
        p2 = Fraction(rand() % 11, rand() % 11);
        pheptoan = (rand() % 2 + 1 == 1) ? '+' : '-';
    } else if(level == 3) {
        p1 = Fraction(rand() % 11, rand() % 11);
        p2 = Fraction(rand() % 11, rand() % 11);
        int random =  rand() % 3 + 1;
        pheptoan = (random == 1) ? '+' : (random == 2) ? '-' : '*';
    } else if(level == 4) {
        p1 = Fraction(rand() % 101, rand() % 101);
        p2 = Fraction(rand() % 101, rand() % 101);
        pheptoan = (rand() % 2 + 1 == 1) ? '+' : '-';
    } else {
        p1 = Fraction(rand() % 101, rand() % 101);
        p2 = Fraction(rand() % 101, rand() % 101);
        int random =  rand() % 3 + 1;
        pheptoan = (random == 1) ? '+' : (random == 2) ? '-' : '*';
    }
}

ostream& operator << (ostream& out, BieuthucPS bt) {
    out << bt.p1 << ' ' << bt.pheptoan << ' ' << bt.p2;
    return out;
}

bool BieuthucPS::kiemtra(float traloi) {
    return traloi == giatri();
}

float BieuthucPS::giatri() {
    if(pheptoan == '+')
        return (p1 + p2).toFloat();
    else if(pheptoan == '-')
        return (p1 - p2).toFloat();
    else return (p1 * p2).toFloat();
}
