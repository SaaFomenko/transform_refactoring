#ifndef SHAPE_H
#define SHAPE_H

#include <exception>
#include <vector>


static const char* err_vertex = "Number vertex do not respond this shape";
static const char* err_not_method = "This method do not exist for current shape.";

class MyException : public std::exception
{
    private:
    const char* msg;

    public:
        MyException(const char* msg_);
        virtual ~MyException();

        const char* what() const noexcept override;
};

enum shape
{
	line,
	rectangle,
	parallelepiped,
	circle,
	cylinder,
};

struct Point
{
	double x;
	double y;
	double z;

	Point();
	Point(double x, double y, double z);
	virtual ~Point();

	std::vector<double> get();
};

using Points = std::vector<Point>;

class ShapeBase
{
	protected:
		int vertex;
		Points points;

	public:
		ShapeBase(int vertex, Points Points);
		virtual ~ShapeBase();

		virtual const int getType() = 0;
};

template <class T>
class Shape
{
	private:
		T* figure;

	public:
		Shape(Points points)
		{
			figure = new T(points);
		}

		~Shape()
		{
			delete figure;
			figure = nullptr;
		}

		int getType()
		{
			return figure->getType();
		}
		double size()
		{
			if (figure->getType() != shape::line)
				throw MyException(err_not_method);

			return figure->size();
		}
		double square()
		{
			if (figure->getType() != shape::rectangle)
				throw MyException(err_not_method);

			return figure->square();
		}
};

#endif