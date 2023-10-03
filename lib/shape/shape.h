#ifndef SHAPE_H
#define SHAPE_H

#include <vector>


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

class Shape
{
	private:
		int type;
		Points points;

	public:
		const int line = 0;
		const int rectangle = 1;
		const int parallelogram = 2;
		const int circle = 3;
		const int cylinder = 4;

		Shape(const int type, Points points);
		Shape(Shape& other);
		Shape& operator=(Shape& other);
		Shape(Shape&& other) noexcept;
		Shape operator=(Shape&& other) noexcept;


		virtual int getType();
		virtual Shape CreateInstance(int type);

		virtual ~Shape();
};

#endif
