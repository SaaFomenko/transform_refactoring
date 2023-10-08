#include <iostream>
#include <gtest/gtest.h>
#include <chrono>
#include <vector>
//#include "transform.h"
#include "../lib/shape/shape.h"
#include "../lib/line/line.h"

namespace my
{
    //Test Line
    Point a(1, 2, 0);
    Point b(5, 2, 0);
    const double ab_size = 4;
    Point c(5, 1, 0);
    Point d(1, 1, 0);
    Points rectangle_p{a, b, c, d};
    const double rect_area = 4;

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
        Shape<Line>* l;
    protected:
        void SetUp(Point& a, Point& b) 
        {
            Points points = {a, b};
            l = new Shape<Line>(points);
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
        Shape<Rectangle>* r;
    protected:
        void SetUp(Points& p)
        {
            r = new Shape<Rectangle>(p);
        }

        void TeamDown() override
        {
            delete r;
            r = nullptr;
        }
}

TEST_F(RectangleShapeTest, rectangle_id_method)
{
    SetUp(my::rectangle_p);

    print_test<double>(r->getType(), "Line getType() id: ");

    EXPECT_EQ(true, shape::line == r->getType());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
