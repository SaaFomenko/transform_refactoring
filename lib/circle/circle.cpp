#include <cmath>
#include "circle.h"


Circle::Circle(const int vertexes, Point center, double radius) :
    Shape(vertexes, Points{center}),
    A(center),
    R(radius)
{}

Circle::Circle(Point center, double radius) :
    Shape(1, Points{center}),
    A(center),
    R(radius)
{}

Circle::~Circle()
{}

const int Circle::getType()
{
    return shape::circle;
}

double Circle::square()
{
    return M_PI * R * R;
}

double Circle::getRadius()
{
    return R;
}