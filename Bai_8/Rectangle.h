#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<iostream>
using namespace std;

class CRectangle{
private:
    float heigth, width;
public:
    void setHeigth(float heigth);
    void setWidth(float width);
    float getHeight();
    float getWidth();
    float area();
};
#endif