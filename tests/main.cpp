#include <iostream>
#include <gtest/gtest.h>
#include <chrono>
#include <vector>
//#include <cstring>
//#include "transform.h"
#include "../lib/shape/shape.h"
#include "../lib/point/point.h"
#include "../lib/line/line.h"

namespace my
{
    //Test Line
    Point a(1, 2, 0);
    Point b(5, 2, 0);
    const double ab_size = 4;

    const char* test_div = "\n----------------------------------\n";
    std::vector<double> p1 = {1, 2, 3};
    std::vector<double> p2 = {4, 5, 6};

    void xyz_print(Point& point, const char* name)
    {
        const char* lable_coord = "xyz";
        std::vector<double> vec = point.get();
        std::cout << name;
        for (int i = 0; lable_coord[i] != 0; ++i)
        std::cout << (i == 0 ? "" : ", " ) << lable_coord[i] << " = " 
            << vec.at(i);
    }

    const std::string shape_to_str(Shape& shape)
    {
        const std::string div = ", ";

        std::vector<std::string> figure{
            "line",
            "rectanle",
            "cube",
            "circle",
            "cylinder",
        };

        std::vector<std::string> params{
            "Figure: " + figure.at(shape.getType()),
            "volume = " + std::to_string(shape.volume),
            "square = " + std::to_string(shape.square),
            "height = " + std::to_string(shape.height),
            "radius = " + std::to_string(shape.radius),
        }; 
        
        std::string str = "";

        for (std::string el : params)
            str += el + div;

        return str;
    }
}

template <class T>
void print_test(T val, const char* name)
{
    std::cout << my::test_div;
    std::cout << name << val;
    std::cout << my::test_div;
}

class LineTest : public ::testing::Test
{
    public:
        Line* l;
    protected:
        void SetUp(Point& a, Point& b) 
        {
            l = new Line(a, b);
        }

        void TearDown() override
        {
            delete l;
            l = nullptr;
        }
};

TEST_F(LineTest, line_size_method)
{
    SetUp(my::a, my::b);

    print_test<double>(l->size(), "Calculated size line: ");

    EXPECT_EQ(true, my::ab_size == l->size());
}

class PointTest : public ::testing::Test
{
    public:
        Point* point;
    protected:
        void SetUp() 
        {
            point = new Point();
        }
        void SetUp(const double x, const double y, const double z)
        {
            point = new Point(x, y, z);
        }
        void SetUp(std::vector<double> p)
        {
            point = new Point(p);
        }

        void TearDown() override
        {
            delete point;
            point = nullptr;
        }
};

TEST_F(PointTest, defaul_constructor)
{
    SetUp();

    std::vector<double> vec_point = point->get();

    std::cout << my::test_div;
    my::xyz_print(*point, "Default point coordinate: ");
    std::cout << my::test_div;

    EXPECT_EQ(
        true, 
        vec_point.at(ord::x) == 0 && vec_point.at(ord::y) == 0 && vec_point.at(ord::z) == 0);
}

TEST_F(PointTest, params_constructor)
{
    SetUp(my::p1.at(ord::x), my::p1.at(ord::y), my::p1.at(ord::z));

    std::vector<double> p1 = point->get();

    std::cout << my::test_div;
    my::xyz_print(*point, "Set const point coordinate: ");
    std::cout << my::test_div;

    EXPECT_EQ(
        true,
        p1 == my::p1
    );
}

TEST_F(PointTest, vector_constructor)
{
    SetUp(my::p2);

    std::vector<double> p2 = point->get();

    std::cout << my::test_div;
    my::xyz_print(*point, "Set vector point coordinate: ");
    std::cout << my::test_div;

    EXPECT_EQ(
        true,
        p2 == my::p2
    );
}

TEST_F(PointTest, copy_constructor)
{
    SetUp(my::p2);

    Point p3(*point);

    std::vector<double> vec_p3 = p3.get();

    std::cout << my::test_div;
    my::xyz_print(p3, "Constructor copy point to point: ");
    std::cout << my::test_div;

    EXPECT_EQ(
        true,
        vec_p3 == my::p2
    );
}

TEST_F(PointTest, copy_operator)
{
    SetUp(my::p2);

    Point p4(my::p1);

    p4 = *point;

    std::vector<double> vec_p4 = p4.get();

    std::cout << my::test_div;
    my::xyz_print(p4, "Operator= for copy point to point: ");
    std::cout << my::test_div;

    EXPECT_EQ(
        true,
        vec_p4 == my::p2
    );
}

TEST_F(PointTest, move_constructor)
{
    SetUp(my::p2);

    Point p4(std::move(*point));

    std::vector<double> vec_p4 = p4.get();

    std::cout << my::test_div;
    my::xyz_print(p4, "Constructor move point to point: ");
    std::cout << my::test_div;

    EXPECT_EQ(
        true,
        vec_p4 == my::p2
    );
}

TEST_F(PointTest, move_operator)
{
    SetUp(my::p1);

    //Point p5(my::p2);
    *point = Point(my::p2);

    std::vector<double> vec_p2 = point->get();

    std::cout << my::test_div;
    my::xyz_print(*point, "Operator= for move point to point: ");
    std::cout << my::test_div;

    EXPECT_EQ(
        true,
        vec_p2 == my::p2
    );
}


int main(int argc, char** argv)
{
    //Shape f1(4, 1, 2, 3, 4); //cylinder
    //Shape f1(0, 1, 2, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); //line
    //Shape f1(1, 1, 2, 0, 5, 2, 0, 1, 4, 0, 5, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); //rectangle не работает вычисление стороны
    //Shape f1(2, 1, 2, 0, 3, 4, 0, 5, 2, 0, 3, 0, 0, 1, 2, 2, 3, 4, 2, 5, 2, 2, 3, 0, 2); //cube

    //std::cout << my::shape_to_str(f1) << '\n';

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}