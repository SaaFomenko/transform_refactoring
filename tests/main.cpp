#include <iostream>
#include <gtest/gtest.h>
#include <chrono>
#include <cmath>
#include <vector>
//#include "transform.h"
#include "../lib/shape/shape.h"
#include "../lib/line/line.h"
#include "../lib/rectangle/rectangle.h"
#include "../lib/parallelepiped/parallelepiped.h"
#include "../lib/circle/circle.h"

namespace my
{
    //Test Line
    Point a(1, 2, 0);
    Point b(5, 2, 0);
    double ab_size = 4;
    Point c(5, 1, 0);
    Point d(1, 1, 0);
    Points rectangle_p{a, b, c, d};
    double rect_area = 4;
    Point e(1, 2, 5);
    Point f(5, 2, 5);
    Point g(5, 1, 5);
    Point h(1, 1, 5);
    Points parallelepiped_p{a, b, c, d, e, f, g, h};
    double parallel_area = 58;
    double parallel_volume = 20;
    double radius = 2;
    double circle_area = M_PI * 2 * 2;

    const char* test_div = "\n----------------------------------\n";

    void xyz_print(Point& point, const char* name)
    {
        const char* lable_coord = "xyz";
        std::vector<double> vec = point.get();
        std::cout << name;
        for (int i = 0; lable_coord[i] != 0; ++i)
        std::cout << (i == 0 ? "" : ", " ) << lable_coord[i] << " = " 
            << vec.at(i);
    }
}

template <class T>
void print_test(T val, const char* name)
{
    std::cout << my::test_div;
    std::cout << name << val;
    std::cout << my::test_div;
}

class LineShapeTest : public ::testing::Test
{
    public:
        Line* l;
    protected:
        void SetUp(Point& a, Point& b) 
        {
            Points points = {a, b};
            l = new Line(points);
        }

        void TearDown() override
        {
            delete l;
            l = nullptr;
        }
};

TEST_F(LineShapeTest, line_size_method)
{
    SetUp(my::a, my::b);

    print_test<double>(l->size(), "Calculated size line: ");

    EXPECT_EQ(true, my::ab_size == l->size());
}

TEST_F(LineShapeTest, line_id_method)
{
    SetUp(my::a, my::b);

    print_test<double>(l->getType(), "Line getType() id: ");

    EXPECT_EQ(true, shape::line == l->getType());
}

class RectangleShapeTest : public ::testing::Test
{
    public:
        Rectangle* r;
    protected:
        void SetUp(Points& p)
        {
            r = new Rectangle(p);
        }

        void TearDown() override
        {
            delete r;
            r = nullptr;
        }
};

TEST_F(RectangleShapeTest, id_rectangle_method_test)
{
    SetUp(my::rectangle_p);

    print_test<double>(r->getType(), "Rectangle getType() id: ");

    EXPECT_EQ(true, shape::rectangle == r->getType());
}

TEST_F(RectangleShapeTest, rectangle_square_method_test)
{
    SetUp(my::rectangle_p);

    print_test<double>(r->square(), "Area for rectangle equal to: ");

    EXPECT_EQ(true, my::rect_area == r->square());
}

class ParallelepipedShapeTest : public ::testing::Test
{
    public:
        Parallelepiped* p;
    protected:
        void SetUp(Points& points)
        {
            p = new Parallelepiped(points);
        }

        void TearDown() override
        {
            delete p;
            p = nullptr;
        }
};

TEST_F(ParallelepipedShapeTest, parallelepiped_id_method_test)
{
    SetUp(my::parallelepiped_p);

    print_test<double>(p->getType(), "Parallelepiped getType() id: ");

    EXPECT_EQ(true, shape::parallelepiped == p->getType());
}

TEST_F(ParallelepipedShapeTest, parallelepiped_square_method_test)
{
    SetUp(my::parallelepiped_p);

    print_test<double>(p->square(), "Area for parallelepiped equal to: ");

    EXPECT_EQ(true, my::parallel_area == p->square());
}


TEST_F(ParallelepipedShapeTest, parallelepiped_volume_method_test)
{
    SetUp(my::parallelepiped_p);

    print_test<double>(p->volume(), "Volume for parallelepiped equal to: ");

    EXPECT_EQ(true, my::parallel_volume == p->volume());
}

class CircleShapeTest : public ::testing::Test
{
    public:
        Circle* c;
    protected:
        void SetUp(Point center, double radius)
        {
            c = new Circle(center, radius);
        }

        void TearDown() override
        {
            delete c;
            c = nullptr;
        }
};

TEST_F(CircleShapeTest, id_circle_method_test)
{
    SetUp(my::f, my::radius);

    print_test<double>(c->getType(), "Circle getType() id: ");

    EXPECT_EQ(true, shape::circle == c->getType());
}

TEST_F(CircleShapeTest, circle_square_method_test)
{
    SetUp(my::f, my::radius);

    print_test<double>(c->square(), "Area for circle equal to: ");

    EXPECT_EQ(true, my::circle_area == c->square());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}