#include "BieuthucPT.h"

BieuthucPT::BieuthucPT(int level) : Bieuthuc(level) {
    bt1 = new Bieuthuc(level);
    bt2 = new Bieuthuc(level);
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

BieuthucPT::~BieuthucPT() {
    delete bt1, bt2;
}

ostream& operator << (ostream& out, BieuthucPT bt) {
    out << "(" << *bt.bt1 << ") " << bt.pheptoan << " (" << *bt.bt2 << ')';
    return out;
}

bool BieuthucPT::kiemtra(float traloi) {
    return traloi == giatri();
}

float BieuthucPT::giatri() {
    if(pheptoan == '+')
        return bt1->giatri() + bt2->giatri();
    else if(pheptoan == '-')
        return bt1->giatri() - bt2->giatri();
    else return bt1->giatri() * bt2->giatri();
}