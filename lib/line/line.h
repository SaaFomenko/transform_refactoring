#ifndef LINE_H
#define LINE_H

#include <vector>
#include "../shape/shape.h"

class Line
{
	private:
//		int type;

		Point A;
		Point B;

	public:
		Line(Point A, Point B);
        virtual ~Line();

        virtual double size();
};

#endif