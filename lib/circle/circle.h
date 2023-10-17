#ifndef CIRCLE_H
#define CIRCLE_H

#include "../shape/shape.h"


class Circle : public Shape
{
    protected:
        Point A;

        Circle(const int vertexes, Point center, const double radius);
    
    public:
    Circle(Point center, const double radius);
    virtual ~Circle();

    virtual const int getType() override;
    virtual double getSquare() override;
    virtual void scale(const int a, const int coord = scale::all) override;

};

#endif