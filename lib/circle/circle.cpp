#include <cmath>
#include "circle.h"


Circle::Circle(const int vertexes, Point center, const double radius) :
    Shape(vertexes, Points{center}, radius),
    A(center)
{}

Circle::Circle(Point center, const double radius) :
    Shape(1, Points{center}, radius),
    A(center)
{}

Circle::~Circle()
{}

const int Circle::getType()
{
    return shape::circle;
}

double Circle::getSquare()
{
    return M_PI * radius * radius;
}

double Circle::getVolume()
{
    return hight;
}

void Circle::scale(const int a, const int coord)
{
    radius *= a;
}

double Circle::getRadius()
{
    return radius;
}