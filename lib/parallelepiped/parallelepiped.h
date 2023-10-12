#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "../shape/shape.h"


class Parallelepiped : public Shape
{
    private:
        Point A;
        Point B;
        Point C;
        Point D;
        Point E;
        Point F;
        Point G;
        Point H;
    public:
        Parallelepiped(Points point);
        ~Parallelepiped();

        const int getType() override;
        double volume(); 
};

#endif
