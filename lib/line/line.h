#ifndef LINE_H
#define LINE_H

#include "../shape/shape.h"

class Line : public Shape
{
	private:
		Point A;
		Point B;

	public:
		Line(Points points);
        virtual ~Line();

        virtual double size();
		virtual const int getType() override;
		virtual double getWidth() override;
		virtual double getHight() override;
};

#endif