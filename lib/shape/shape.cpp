#include "shape.h"


MyException::MyException(const char* msg_) : msg(msg_)
{}

MyException::~MyException()
{}

const char* MyException::what() const noexcept
{
    return msg;
}

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

Point::~Point()
{}

Shape::Shape(int vertexes, Points points) :
	vertexes(vertexes),
	points(points)
{
	if (vertexes != points.size())
		throw MyException(err_vertexes);
}

Shape::~Shape()
{}