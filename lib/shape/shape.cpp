#include "shape.h"


using It = std::vector<Point>::iterator;

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
	points(points),
	width(0),
	hight(0),
	depth(0),
	radius(0)
{
	if (vertexes != points.size())
		throw MyException(err_vertexes);
}

Shape::~Shape()
{}

void Shape::shift(const int m, const int n, const int k)
{
	for (It i = points.begin(); i != points.end(); ++i)
	{
		i->x += m;
		i->y += n;
		i->z += n;
	}
}

void Shape::scale(const int a, const int coord)
{
	for (It i = points.begin(); i != points.end(); ++i)
	{
		if (coord == scale::all)
		{
			i->x *= a;
			i->y *= a;
			i->z *= a;
		}
		else
		{
			switch (coord)
			{
				case scale::x:
					i->x *= a;
					break;
				case scale::y:
					i->y *= a;
					break;
				case scale::z:
					i->z *= a;
					break;
				default:
					break;
			}
		}
	}
}

double Shape::getSquare()
{
	return width * hight;
}

double Shape::getVolume()
{
	return width * hight * depth;
}

double Shape::getHight()
{
	return hight;
}

double Shape::getWidth()
{
    return width;
}

double Shape::getDepth()
{
    return depth;
}
double Shape::getRadius()
{
	return radius;
}

Points Shape::getPoints()
{
	return points;
}