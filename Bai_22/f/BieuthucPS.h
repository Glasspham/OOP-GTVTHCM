#pragma once
#ifndef BIEUTHUCPS_H
#define BIEUTHUCPS_H
#include "Bieuthuc.h"
#include "Fraction.h"

class BieuthucPS : public Bieuthuc {
protected:
    Fraction p1, p2;
public:
    BieuthucPS(int level);
    friend ostream& operator << (ostream& out, BieuthucPS bt);
    bool kiemtra(float traloi);
    float giatri();
};
#endif