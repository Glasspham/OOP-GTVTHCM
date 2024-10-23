#include "Bieuthuc.h"

Bieuthuc::Bieuthuc(int level) {
    if(level == 1) {
        a = rand() % 11;
        b = rand() % 11;
        pheptoan = '+';
    } else if(level == 2) {
        a = rand() % 11;
        b = rand() % 11;
        pheptoan = (rand() % 2 == 0) ? '+' : '-';
    } else if(level == 3) {
        a = rand() % 11;
        b = rand() % 11;
        int random =  rand() % 3;
        pheptoan = (random == 0) ? '+' : (random == 1) ? '-' : '*';
    } else if(level == 4) {
        a = rand() % 101;
        b = rand() % 101;
        pheptoan = (rand() % 2 == 0) ? '+' : '-';
    } else {
        a = rand() % 101;
        b = rand() % 101;
        int random =  rand() % 3;
        pheptoan = (random == 0) ? '+' : (random == 1) ? '-' : '*';
    }
}

ostream& operator << (ostream& out, Bieuthuc bt) {
    out << bt.a << ' ' << bt.pheptoan << ' ' << bt.b; 
	return out;
}

bool Bieuthuc::kiemtra(float traloi) { return traloi == giatri(); }

float Bieuthuc::giatri() {
    if(pheptoan == '+')
        return a + b;
    else if(pheptoan == '-')
        return a - b;
    else return a * b;
}