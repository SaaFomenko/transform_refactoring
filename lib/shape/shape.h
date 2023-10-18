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

enum scale
{
	x,
	y,
	z,
	all,
};

enum shape
{
	line,
	rectangle,
	parallelepiped,
	circle,
	cylinder,
};

struct Point final
{
	double x;
	double y;
	double z;

	Point();
	Point(double x, double y, double z);
	~Point();
	bool operator==(Point& other)
	{
		bool equal_x = x == other.x;
		bool equal_y = y == other.y;
		bool equal_z = z == other.z;

		if (equal_x && equal_y && equal_z)
			return true;
		
		return false;
	}

	std::vector<double> get();
};

using Points = std::vector<Point>;

class Shape
{
	protected:
		int vertexes;
		Points points;
		double width;
		double hight;
		double depth;
		double radius;

	public:
		Shape(int vertex, Points Points, double radius = 0, double hight = 0);
		virtual ~Shape();

		virtual const int getType() = 0;

		virtual Points getPoints();
		virtual double getWidth();
		virtual double getHight();
		virtual double getDepth();
		virtual double getRadius();
		virtual double getSquare();
		virtual double getVolume();
		
		virtual void shift(const int m, const int n, const int k);
		virtual void scale(const int a, const int coord = scale::all);
};

#endif