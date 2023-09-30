#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
	private:

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
