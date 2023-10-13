#ifndef CYLINDER_H
#define CYLINDER_H

#include "../circle/circle.h"


class Cylinder final : public Circle
{
    private:
        double H;

    public:
        Cylinder(Point center, double radius, double hight);
        ~Cylinder();

        const int getType() override;
        double square() override;
        double volume();
};

#endif