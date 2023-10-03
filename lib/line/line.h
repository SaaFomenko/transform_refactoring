#ifndef LINE_H
#define LINE_H

#include <vector>
#include "../shape/shape.h"

class Line : public Shape
{
	private:
//		int type;

		Point A;
		Point B;

	public:
		Line(int type, Point A, Point B);
        virtual ~Line();

        double size();
};

#endif