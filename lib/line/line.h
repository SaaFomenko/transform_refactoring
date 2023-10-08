#ifndef LINE_H
#define LINE_H

#include "../shape/shape.h"

class Line
{
	private:
		Point A;
		Point B;

	public:
		Line(Points points);
        virtual ~Line();

        double size();
		int getType();
};

#endif