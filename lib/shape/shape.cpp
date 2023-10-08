#include <iostream>
#include "shape.h"
#include "../line/line.h"


static const char* non_shape = "This the a shape do not realise.";

class MyException : public std::exception
{
	private:
	const char* msg;

	public:
		MyException(const char* msg_) : msg(msg_){}
		virtual ~MyException(){}

		const char* what() const noexcept override
		{
			return msg;
		}
};

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

Shape::Shape(const int type, Points points) :
	type(type),
	points(points)
{
    std::cout << "Start shape init.\n";
	if (type == line)
		figure = new Line(points.at(0), points.at(1));
	else
		throw MyException(non_shape);
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

double Shape::size()
{
	return figure->size();
}

Shape::~Shape()
{
	delete figure;
	figure = nullptr;
}