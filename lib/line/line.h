#ifndef LINE_H
#define LINE_H

#include <vector>
#include "../shape/shape.h"

//using VecCoords = std::vector<double>;
class Line : public Shape
{
	private:
		int type;

		Point A;
		Point B;

	public:
		Line(int type, Point A, Point B);
		Line(Line& other);
		Line& operator=(Line& other);
		Line(Line&& other) noexcept;
		//Line operator=(Line&& other) noexcept;
        virtual ~Line();

        double size();
};

#endif