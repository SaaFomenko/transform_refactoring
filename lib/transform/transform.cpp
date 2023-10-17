#include "transform.h"
#include "../line/line.h"
#include "../rectangle/rectangle.h"
#include "../parallelepiped/parallelepiped.h"
#include "../circle/circle.h"
#include "../cylinder/cylinder.h"


transform::transform(Shape& sh)
{
	switch (sh.getType())
	{
		case shape::line:
			shape = new Line(sh.getPoints());
			break;
		case shape::rectangle:
			shape = new Rectangle(sh.getPoints());
			break;
		case shape::parallelepiped:
			shape = new Parallelepiped(sh.getPoints());
			break;
		case shape::circle:
			shape = new Circle(sh.getPoints().at(0), sh.getWidth()/2);
			break;
		case shape::cylinder:
			shape = new Cylinder(sh.getPoints().at(0), sh.getWidth()/2, sh.getHight());
			break;
	}
}

Shape& transform::shift(int m, int n, int k)
{
	shape->shift(m, n, k);

	return *shape;
}

Shape& transform::scaleX(const int a)
{
	shape->scale(a, scale::x);

	return *shape;
}

Shape& transform::scaleY(int a)
{
	shape->scale(a, scale::y);

	return *shape;
}

Shape& transform::scaleZ(int a)
{
	shape->scale(a, scale::z);

	return *shape;
}

Shape& transform::scale(int a)
{
	shape->scale(a);

	return *shape;
}