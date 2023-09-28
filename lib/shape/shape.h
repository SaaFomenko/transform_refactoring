#ifndef SHAPE_H
#define SHAPE_H

//#include "../point/point.h"

// enum figure
// {
// 	point,
// 	line,
// 	rectangle,
// 	parallelepiped,
// 	circle,
// 	cylinder
// };

enum ord
{
	x,
	y,
	z
};

struct shape
{
	const int line = 0;
	const int rectangle = 1;
 	const int parallelepiped = 2;
 	const int circle = 3;
 	const int cylinder = 4;
};

//template <class T = Point>
class Shape : public shape
{
	private:
	//	T shape;
		int type;
		std::vector<double> a;
	
	public:
		enum types
		{
			line
		};

		Shape();
		virtual ~Shape();
		//Shape() = delete;
		//Shape(Line& l);
	//Shape(int type, int _x1, int _y1, double R, double H);
		int getType();
		//T& get();
		// double volume();
		// double square();
		// double height();
		// double radius();
};

#endif