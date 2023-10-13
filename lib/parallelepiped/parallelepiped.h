#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "../line/line.h"
#include "../rectangle/rectangle.h"


class Parallelepiped final : public Rectangle
{
    private:
        Point E;
        Point F;
        Point G;
        Point H;
        Line* a;
        Line* b;
        Line* j;

    public:
        Parallelepiped(Points point);
        ~Parallelepiped();

        const int getType() override;
        double square() override;
        double volume();
};

#endif
