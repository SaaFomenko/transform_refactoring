#include "rectangle.h"
#include "../line/line.h"


Rectangle::Rectangle(const int vertexes, Points points) :
    Shape(vertexes, points),
    A(points.at(0)),
    B(points.at(1)),
    C(points.at(2)),
    D(points.at(3))
{}

Rectangle::Rectangle(Points points) :
    Shape(4, points),
    A(points.at(0)),
    B(points.at(1)),
    C(points.at(2)),
    D(points.at(3))
{}

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