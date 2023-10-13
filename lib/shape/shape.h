#ifndef SHAPE_H
#define SHAPE_H

#include <exception>
#include <vector>


static const char* err_vertexes = "Number vertex do not respond this shape";
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

class Shape
{
	protected:
		int vertexes;
		Points points;

	public:
		Shape(int vertex, Points Points);
		virtual ~Shape();

		virtual const int getType() = 0;
};

#endif