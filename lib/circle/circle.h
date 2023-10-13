#ifndef CIRCLE_H
#define CIRCLE_H

#include "../shape/shape.h"


class Circle : public Shape
{
    protected:
        Point A;
        double R;

        Circle(const int vertexes, Point center, const double radius);
    
    public:
    Circle(Point center, const double radius);
    virtual ~Circle();

    virtual const int getType() override;
    virtual double square();
};

#endif