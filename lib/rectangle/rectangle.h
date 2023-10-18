#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../shape/shape.h"
#include "../line/line.h"


class Rectangle : public Shape
{
	protected:
		Point A;
		Point B;
		Point C;
		Point D;
		Line* a;
		Line* b;

		Rectangle(const int vertexes, Points points);

	public:
		Rectangle(Points points);
		virtual ~Rectangle();

		virtual const int getType() override;
};

#endif
