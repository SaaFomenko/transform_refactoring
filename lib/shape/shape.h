#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

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

	std::vector<double> get();

	virtual ~Point();
};

using Points = std::vector<Point>;

// class ShapeBase
// {
// 	public:
// 		virtual int getType() = 0;
// 		virtual ~ShapeBase();
// };

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

		int getType()
		{
			return figure->getType();
		}
		double size()
		{
			return figure->size();
		}

		~Shape()
		{
			delete figure;
			figure = nullptr;
		}
};

#endif