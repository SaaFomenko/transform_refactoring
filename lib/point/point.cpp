#include "point.h"


Point::Point(const double x, const double y, const double z) :
    x_(x),
    y_(y),
    z_(z)
{}

Point::Point(std::vector<double> p) :
    x_(p.at(0)),
    y_(p.at(1)),
    z_(p.at(2))
{}

Point::Point(Point& other) :
    x_(other.x_),
    y_(other.y_),
    z_(other.z_)
{}

Point& Point::operator=(Point& other)
{
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;

    return *this;
}

Point::Point(Point&& other) noexcept
{
    *this = other;
}

Point Point::operator=(Point&& other) noexcept
{
    return Point(other);
}

Point::~Point()
{}

void Point::set(const double x, const double y, const double z, const bool to_null)
{
    if(to_null)
        x_ = 0;
        y_ = 0;
        z_ = 0;
    if (x != 0)
        x_ = x;
    if (y != 0)
        y_ = y;
    if (z != 0)
        z_ = z;
}

std::vector<double> Point::get()
{
    return std::vector<double>{x_, y_, z_};
}