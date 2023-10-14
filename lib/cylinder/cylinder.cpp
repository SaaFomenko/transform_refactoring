#include <cmath>
#include "../cylinder/cylinder.h"


Cylinder::Cylinder(Point center, const double radius, const double hight) :
    Circle(1, center, radius),
    H(hight)
{}

Cylinder::~Cylinder()
{}

const int Cylinder::getType()
{
    return shape::cylinder;
}

double Cylinder::square()
{
    return M_PI * R * R * 2 + M_PI * H * R * 2;
}

double Cylinder::volume()
{
    return M_PI * R * R * H;
}