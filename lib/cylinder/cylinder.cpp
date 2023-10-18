#include <iostream>
#include <cmath>
#include "../cylinder/cylinder.h"


Cylinder::Cylinder(Point center, const double radius_, const double hight_) :
    Circle(1, center, radius_)
{
    hight = hight_;
    std::cout << "Radius: " << radius << '\n';
}

Cylinder::~Cylinder()
{}

const int Cylinder::getType()
{
    return shape::cylinder;
}

double Cylinder::getSquare()
{
    return M_PI * radius * radius * 2 + M_PI * hight * radius * 2;
}

double Cylinder::getVolume()
{
    std::cout << "Hight: " << hight << '\n';
    return M_PI * radius * radius * hight;
}