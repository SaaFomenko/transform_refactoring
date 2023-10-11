#include "rectangle.h"
#include "../line/line.h"


Rectangle::Rectangle(Points points) :
    Shape(4, points)
{
    if (points.size() == vertex)
    {
        A = points.at(0);
        B = points.at(1);
        C = points.at(2);
        D = points.at(3);
    }
    else
        throw MyException(err_vertex);	
}

const int Rectangle::getType()
{
    return shape::rectangle;
}

double Rectangle::square()
{
    Line a(Points{A, B});
    Line b(Points{B, C});

    return a.size() * b.size();
}

Rectangle::~Rectangle()
{}