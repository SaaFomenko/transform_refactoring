#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../shape/shape.h"


class Rectangle : Shape
{
	private:
		Point A;
		Point B;
		Point C;
		Point D;
	public:
		Rectangle(Points points);

		const int getType() override;
		double square();

		~Rectangle();
};

#endif
