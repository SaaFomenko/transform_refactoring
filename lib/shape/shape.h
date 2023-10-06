#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <exception>

enum shape
{
	line,
	rectangle,
	parallelepiped,
	circle,
	cylinder
};

class Shape
{
	private:
		int type;
		Points points;
		Shape* figure;

	public:
		Shape(const int type, Points points);
		Shape(Shape& other);
		Shape& operator=(Shape& other);
		Shape(Shape&& other) noexcept;
		Shape operator=(Shape&& other) noexcept;

		int getType();
		virtual double size();

		virtual ~Shape();
};

#endif
