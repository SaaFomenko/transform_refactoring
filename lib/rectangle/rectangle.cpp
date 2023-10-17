#include "rectangle.h"
#include "../line/line.h"


Rectangle::Rectangle(const int vertexes, Points points) :
    Shape(vertexes, points),
    A(points.at(0)),
    B(points.at(1)),
    C(points.at(2)),
    D(points.at(3))
{
    a = new Line(Points{A, B});
    b = new Line(Points{B, C});
}

Rectangle::~Rectangle()
{
    delete a;
    a = nullptr;
    delete b;
    b = nullptr;
}

Rectangle::Rectangle(Points points) :
    Shape(4, points),
    A(points.at(0)),
    B(points.at(1)),
    C(points.at(2)),
    D(points.at(3))
{
    Line a(Points{A, B});
    Line b(Points{B, C});

    width = a.size();
    hight = b.size();
}

const int Rectangle::getType()
{
    return shape::rectangle;
}