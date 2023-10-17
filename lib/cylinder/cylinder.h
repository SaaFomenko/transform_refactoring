#ifndef CYLINDER_H
#define CYLINDER_H

#include "../circle/circle.h"


class Cylinder final : public Circle
{
    public:
        Cylinder(Point center, const double radius_, const double hight_);
        ~Cylinder();

        const int getType() override;
        double getSquare() override;
        double getVolume();
};

#endif