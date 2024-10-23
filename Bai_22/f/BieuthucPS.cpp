#include "BieuthucPS.h"

BieuthucPS::BieuthucPS(int level) : Bieuthuc(level) {
    p1 = Fraction(Bieuthuc(level).giatri(), Bieuthuc(level).giatri());
    p2 = Fraction(Bieuthuc(level).giatri(), Bieuthuc(level).giatri());
    if(level == 1) pheptoan = '+';
    else if(level == 2) pheptoan = (rand() % 2 == 0) ? '+' : '-';
    else if(level == 3) {
        int random =  rand() % 3;
        pheptoan = (random == 0) ? '+' : (random == 1) ? '-' : '*';
    } else if(level == 4) pheptoan = (rand() % 2 == 0) ? '+' : '-';
    else {
        int random =  rand() % 3;
        pheptoan = (random == 0) ? '+' : (random == 1) ? '-' : '*';
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
