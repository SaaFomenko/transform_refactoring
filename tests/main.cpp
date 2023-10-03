#include <iostream>
#include <gtest/gtest.h>
#include <chrono>
#include <vector>
//#include <cstring>
//#include "transform.h"
#include "../lib/shape/shape.h"

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

    // const std::string shape_to_str(Shape& shape)
    // {
    //     const std::string div = ", ";

    //     std::vector<std::string> figure{
    //         "line",
    //         "rectanle",
    //         "cube",
    //         "circle",
    //         "cylinder",
    //     };

    //     std::vector<std::string> params{
    //         "Figure: " + figure.at(shape.getType()),
    //         "volume = " + std::to_string(shape.volume),
    //         "square = " + std::to_string(shape.square),
    //         "height = " + std::to_string(shape.height),
    //         "radius = " + std::to_string(shape.radius),
    //     }; 
        
    //     std::string str = "";

    //     for (std::string el : params)
    //         str += el + div;

    //     return str;
    // }
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
        Shape* l;
    protected:
        void SetUp(Point& a, Point& b) 
        {
            Points points = {a, b};
            l = new Shape(Shape::line, points);
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
