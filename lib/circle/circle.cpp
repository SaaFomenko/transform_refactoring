#include <cmath>
#include "circle.h"


Circle::Circle(const int vertexes, Point center, const double radius_) :
    Shape(vertexes, Points{center}),
    A(center)
{
    radius = radius_;
}

Circle::Circle(Point center, const double radius_) :
    Shape(1, Points{center}),
    A(center)
{
    radius = radius_;
}

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

void Circle::scale(const int a, const int coord)
{
    radius *= a;
}