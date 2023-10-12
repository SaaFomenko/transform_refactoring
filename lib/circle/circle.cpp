#include <cmath>
#include "circle.h"


Circle::Circle(Point center, double radius) :
    Shape(1, Points{center})
{
    if (vertex == points.size())
    {
        A = center;
        R = radius;
    }
    else
        throw MyException(err_vertex);
}

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
