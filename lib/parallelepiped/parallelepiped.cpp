#include "../parallelepiped/parallelepiped.h"
#include "../line/line.h"


Parallelepiped::Parallelepiped(Points points) :
    Rectangle(8, points),
    E(points.at(4)),
    F(points.at(5)),
    G(points.at(6)),
    H(points.at(7))
{
    a = new Line(Points{A, B});
    b = new Line(Points{B, C});
    j = new Line(Points{B, F});
    width = a->size();
    hight = b->size();
    depth = j->size();
}

Parallelepiped::~Parallelepiped()
{
    delete j;
    j = nullptr;
}

const int Parallelepiped::getType()
{
    return shape::parallelepiped;
}

double Parallelepiped::getSquare()
{
    double ab_sqr = width * hight;
    double aj_sqr = width * depth;
    double bj_sqr = hight * depth;

    return 2 * ab_sqr + 2 * aj_sqr + 2 * bj_sqr;
}