#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../shape/shape.h"


class Rectangle : Shape
{
	protected:
		Point A;
		Point B;
		Point C;
		Point D;
		Rectangle(const int vertexes, Points points);

	public:
		Rectangle(Points points);
		virtual ~Rectangle();

		virtual const int getType() override;
		virtual double square();
};

#endif
