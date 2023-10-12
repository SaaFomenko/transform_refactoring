#include "../parallelepiped/parallelepiped.h"
#include "../line/line.h"


Parallelepiped::Parallelepiped(Points points) :
    Shape(8, points)
{
    if (vertex == points.size())
    {
        A = points.at(0);
        B = points.at(1);
        C = points.at(2);
        D = points.at(3);
        E = points.at(4);
        F = points.at(5);
        G = points.at(6);
        H = points.at(7);
    }
    else
        throw MyException(err_vertex);
}

Parallelepiped::~Parallelepiped()
{}

const int Parallelepiped::getType()
{
    return shape::parallelepiped;
}

double Parallelepiped::volume()
{
    Line a(Points{A, B});
    Line b(Points{B, C});
    Line j(Points{B, F});

    return a.size() * b.size() * j.size();
}