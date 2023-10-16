#include <math.h>
#include "line.h"


Line::Line(Points points) :
    Shape(2, points),
    A(points.at(0)),
    B(points.at(1))
{
    width = size();
}

Line::~Line()
{}

double Line::size()
{

    return std::sqrt(
        pow(abs(A.x - B.x), 2) +
        pow(abs(A.y - B.y), 2) +
        pow(abs(A.z - B.z), 2) 
    );
}

const int Line::getType()
{
    return shape::line;
}

double Line::getWidth()
{
    return width;
}

double Line::getHight()
{
    return hight;
}