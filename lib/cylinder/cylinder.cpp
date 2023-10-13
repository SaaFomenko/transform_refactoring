#include <cmath>
#include "../cylinder/cylinder.h"


Cylinder::Cylinder(Point center, const double radius, const double hight) :
    Circle(1, center, radius),
    H(hight)
{}

Cylinder::~Cylinder()
{}

double Cylinder::square()
{
    return M_PI * R * R + 2 * R * H;
}

double Cylinder::volume()
{
    return M_PI * R * R * H;
}