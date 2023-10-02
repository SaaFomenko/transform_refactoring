#include <math.h>
#include "line.h"


Line::Line(int type, Point A, Point B) :
    type(type),
    A(A),
    B(B)
{}

Line::Line(Line& other) :
    A(other.A),
    B(other.B)
{}

Line& Line::operator=(Line& other)
{
    A = other.A;
    B = other.B;

    return *this;
}

Line::Line(Line&& other) noexcept
{
    *this = other;
}

// Line Line::operator=(Line&& other) noexcept
// {
//     return *this = other;
// }

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