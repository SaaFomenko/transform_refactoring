#ifndef CIRCLE_H
#define CIRCLE_H

#include "../shape/shape.h"


class Circle : public Shape
{
    protected:
        Point A;
        double R;
    
    public:
    Circle(Point point, const double r);
    ~Circle();

    const int getType() override;
    double square();
};

#endif