#include "shape.h"


Point::Point() :
	x(0),
	y(0),
	z(0)
{}

Point::Point(double x, double y, double z) :
	x(x),
	y(y),
	z(z)
{}

std::vector<double> Point::get()
{
	return std::vector<double>{x, y, z};
}

Shape::Shape(const int type, Points points) :
	type(type),
	points(points)
{
	if (type == line)
		this* = Line();
}

Shape::Shape(Shape& other) :
    type(other.type),
    points(other.points)
{}

Shape& Shape::operator=(Shape& other)
{
    type = other.type;
    points = other.points;

    return *this;
}

Shape::Shape(Shape&& other) noexcept
{
    *this = other;
}

Shape Shape::operator=(Shape&& other) noexcept
{
    return *this = other;
}

//Shape Shape::