#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../shape/shape.h"


class transform
{

	private:
		Shape* shape;

	public:
		transform(Shape& sh);
		virtual ~transform();

		Shape& shift(int m, int n, int k);
		Shape& scaleX(int a);
		Shape& scaleY(int d);
		Shape& scaleZ(int e);
		Shape& scale(int s);
};

#endif