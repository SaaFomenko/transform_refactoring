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
}

Parallelepiped::~Parallelepiped()
{
    delete a;
    a = nullptr;
    delete b;
    b = nullptr;
    delete j;
    j = nullptr;
}

const int Parallelepiped::getType()
{
    return shape::parallelepiped;
}

double Parallelepiped::square()
{
    double ab_sqr = a->size() * b->size();
    double aj_sqr = a->size() * j->size();
    double bj_sqr = b->size() * j->size();

    return 2 * ab_sqr + 2 * aj_sqr + 2 * bj_sqr;
}

double Parallelepiped::volume()
{
    return a->size() * b->size() * j->size();
}