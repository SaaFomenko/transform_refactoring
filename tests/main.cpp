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
#include "../lib/cylinder/cylinder.h"
#include "../lib/transform/transform.h"

namespace my
{
    //Test Line
    Point a(1, 2, 0);
    Point b(5, 2, 0);
    double ab_size = 4;
    Point c(5, 1, 0);
    Point d(1, 1, 0);
    //Test Rectangle
    Points rectangle_p{a, b, c, d};
    double rect_area = 4;
    Point e(1, 2, 5);
    Point f(5, 2, 5);
    Point g(5, 1, 5);
    Point h(1, 1, 5);
    //Test Parallelepiped
    Points parallelepiped_p{a, b, c, d, e, f, g, h};
    double parallel_area = 58;
    double parallel_volume = 20;
    //Test Circle
    Point center(7, 0, 7);
    Point new_center(6, -1, 8);
    double radius = 2;
    double circle_area = M_PI * radius * radius;
    //Test Cylinder
    double hight = 5;
    double cylinder_area = M_PI * radius * radius * 2  + M_PI * hight * radius * 2;
    double cylinder_volume = circle_area * hight;
    //Test Transform method shift for Shape
    const int m = -1;
    const int n = -1;
    const int k = 1;
    Point new_A(0, 1, 1);
    Line line_new_pos(Points{Point(0, 1, 1), Point(4, 1, 1)});

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

    print_test<double>(r->getSquare(), "Area for rectangle equal to: ");

    EXPECT_EQ(true, my::rect_area == r->getSquare());
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

    print_test<double>(p->getSquare(), "Area for parallelepiped equal to: ");

    EXPECT_EQ(true, my::parallel_area == p->getSquare());
}


TEST_F(ParallelepipedShapeTest, parallelepiped_volume_method_test)
{
    SetUp(my::parallelepiped_p);

    print_test<double>(p->getVolume(), "Volume for parallelepiped equal to: ");

    EXPECT_EQ(true, my::parallel_volume == p->getVolume());
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
    SetUp(my::center, my::radius);

    print_test<double>(c->getType(), "Circle getType() id: ");

    EXPECT_EQ(true, shape::circle == c->getType());
}

TEST_F(CircleShapeTest, circle_square_method_test)
{
    SetUp(my::center, my::radius);

    print_test<double>(c->getSquare(), "Area for circle equal to: ");

    EXPECT_EQ(true, my::circle_area == c->getSquare());
}

class CylinderShapeTest : public ::testing::Test
{
    public:
        Cylinder* cl;
    protected:
        void SetUp(Point center, double radius, double hight)
        {
            cl = new Cylinder(center, radius, hight);
        }

        void TearDown() override
        {
            delete cl;
            cl = nullptr;
        }
};

TEST_F(CylinderShapeTest, id_cylinder_method_test)
{
    SetUp(my::center, my::radius, my::hight);

    print_test<double>(cl->getType(), "Circle getType() id: ");

    EXPECT_EQ(true, shape::cylinder == cl->getType());
}

TEST_F(CylinderShapeTest, cylinder_square_method_test)
{
    SetUp(my::center, my::radius, my::hight);

    print_test<double>(cl->getSquare(), "Area for cylinder equal to: ");

    EXPECT_EQ(true, my::cylinder_area == cl->getSquare());
}

TEST_F(CylinderShapeTest, cylinder_volume_method_test)
{
    SetUp(my::center, my::radius, my::hight);

    print_test<double>(cl->getVolume(), "Volume for cylinder equal to: ");

    EXPECT_EQ(true, my::cylinder_volume == cl->getVolume());
}

class transformParallelepipedTest : public ::testing::Test
{
    public:
        Shape* sh;
        transform* tr;

    protected:
        void SetUp(Points& points)
        {
            sh = new Parallelepiped(points);
            tr = new transform(*sh);
        }

        void TearDown() override
        {
            delete sh;
            sh = nullptr;
            delete tr;
            tr = nullptr;
        }
};

TEST_F(transformParallelepipedTest, shift_parallelepiped_method_test)
{
    SetUp(my::parallelepiped_p);

    std::cout << "! Old position A point in parallelepiped: ";
    Point A = sh->getPoints().at(0);
    std::cout << A.x << ", " << A.y << ", " << A.z << "\n";

    Shape& tr_shape = tr->shift(my::m, my::n, my::k);

    std::cout << "! New position A point in parallelepiped: ";
    Point new_A = tr_shape.getPoints().at(0);
    std::cout << new_A.x << ", " << new_A.y << ", " << new_A.z << "\n";

    EXPECT_EQ(true, my::new_A == new_A);

    print_test<double>(tr_shape.getVolume(), "Volume for parallelepiped equal to: ");

    EXPECT_EQ(true, my::parallel_volume == tr_shape.getVolume());
}

class transformCylinderTest : public ::testing::Test
{
    public:
        Shape* sh;
        transform* tr;

    protected:
        void SetUp(Point center, double radius, double hight)
        {
            std::cout << "Test radius: " << radius << '\n';
            sh = new Cylinder(center, radius, hight);
            tr = new transform(*sh);
        }

        void TearDown() override
        {
            delete sh;
            sh = nullptr;
            delete tr;
            tr = nullptr;
        }
};


TEST_F(transformCylinderTest, shift_cylinder_method_test)
{
    SetUp(my::center, my::radius, my::hight);

    std::cout << "! Test cylinder radius: ";
    std::cout << sh->getRadius() << '\n';
    std::cout << "! Old position A point in cylinder: ";
    Point A = sh->getPoints().at(0);
    std::cout << A.x << ", " << A.y << ", " << A.z << "\n";

    Shape& tr_shape = tr->shift(my::m, my::n, my::k);

    std::cout << "! New position A point in cylinder: ";
    Point new_A = tr_shape.getPoints().at(0);
    std::cout << new_A.x << ", " << new_A.y << ", " << new_A.z << "\n";

    EXPECT_EQ(true, my::new_center == new_A);

    print_test<double>(tr_shape.getVolume(), "Volume for cylinder equal to: ");

    EXPECT_EQ(true, my::cylinder_volume == tr_shape.getVolume());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}