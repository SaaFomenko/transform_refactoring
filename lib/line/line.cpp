#include <math.h>
#include "line.h"


Line::Line() :
    a_(Point()),
    b_(Point())
{}

Line::Line(Point a, Point b) :
    a_(a),
    b_(b)
{}

Line::Line(Line& other) :
    a_(other.a_),
    b_(other.b_)
{}

Line& Line::operator=(Line& other)
{
    a_ = other.a_;
    b_ = other.b_;

    return *this;
}

Line::Line(Line&& other) noexcept
{
    *this = other;
}

Line Line::operator=(Line&& other) noexcept
{
    return *this = other;
}

Line::~Line()
{}

double Line::size()
{
    std::vector<double> a = a_.get();
    std::vector<double> b = b_.get();

    return std::sqrt(
        pow(abs(a.at(ord::x) - b.at(ord::x)), 2) +
        pow(abs(a.at(ord::y) - b.at(ord::y)), 2) +
        pow(abs(a.at(ord::z) - b.at(ord::z)), 2) 
    );
}