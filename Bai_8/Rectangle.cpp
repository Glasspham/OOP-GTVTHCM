#include "Rectangle.h"

void CRectangle::setHeigth(float heigth) { this->heigth = heigth; }
void CRectangle::setWidth(float width) { this->width = width; }
float CRectangle::getHeight() { return this->heigth; }
float CRectangle::getWidth() { return this->width; }
float CRectangle::area() { return heigth * width; }