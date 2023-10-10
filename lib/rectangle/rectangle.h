#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../shape/shape.h"


class Rectangle
{
	private:
		Point A;
		Point B;
		Point C;
		Point D;
	public:
		Rectangle(Points& points);

		int getType();
		double square();

		~Rectangle();
}

#endif
