#ifndef CIRCLE_H
#define CIRCLE_H

#include "../shape/shape.h"


class Circle : public Shape
{
    protected:
        Point A;

        Circle(const int vertexes, Point center, const double radius_);
    
    public:
    Circle(Point center, const double radius_);
    virtual ~Circle();

    virtual const int getType() override;
    virtual double getSquare() override;
    virtual double getVolume() override;
    virtual double getRadius() override;
    virtual void scale(const int a, const int coord = scale::all) override;
};

#endif