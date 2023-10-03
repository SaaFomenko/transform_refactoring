#include <math.h>
#include "line.h"


Line::Line(int type, Point A, Point B) :
    Shape(type, std::vector<Point>{A, B}),
    A(A),
    B(B)
{}

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