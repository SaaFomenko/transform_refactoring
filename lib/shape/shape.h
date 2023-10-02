#ifndef SHAPE_H
#define SHAPE_H


struct Point
{
	double x;
	double y;
	double z;
};

class Shape
{
	protected:
		Shape() = default;
	public:
		virtual ~Shape();
		virtual int getType() = 0;
		//virtual Shape CreateInstance(int type) = 0;

		const int line = 0;
		const int rectangle = 1;
		const int parallelogram = 2;
		const int circle = 3;
		const int cylinder = 4;
};

#endif
