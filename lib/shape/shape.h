#ifndef SHAPE_H
#define SHAPE_H

#include "../point/point.h"

enum figure
{
	point,
	line,
	rectangle,
	parallelepiped,
	circle,
	cylinder
};

template <class T = Point>
class Shape
{
	private:
		T shape;
		int type;
		// double volume;
		// double square;
		// double height;
		// double radius;

	public:
		Shape();
		virtual ~Shape();
		//Shape() = delete;
		//Shape(Line& l);
	//Shape(int type, int _x1, int _y1, double R, double H);
		int getType();
		//T& get();
		double volume();
		double square();
		double height();
		double radius();
};

#endif