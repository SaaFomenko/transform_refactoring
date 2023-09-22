#include <iostream>
#include <gtest/gtest.h>
#include <chrono>
#include <vector>
//#include <cstring>
//#include "transform.h"
#include "../lib/shape/shape.h"
#include "../lib/point/point.h"



namespace my
{

    const char* test_div = "\n----------------------------------\n\n";
    const char* lable_coord = "xyz";

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

class PointTest : public ::testing::Test
{
    public:
        Point* point;
    protected:
        // void Setup (Point* point) 
        // {
        //     point = new Point();
        // }
        void Setup (const double x, const double y, const double z)
        {
            point = new Point(x, y, z);
        }

        void TearDown() override
        {
            delete point;
        }

        Point* point{nullptr};
};

TEST_F(PointTest, defaul_constructor)
{
    //Point point; // = new Point();

    //Setup(point);

    Setup(1, 2, 3);

    std::vector<double> vec_point = point.get();

    std::cout << my::test_div;

    for (int i = 0; my::lable_coord[i] != 0; ++i)
        std::cout << (i == 0 ? "" : ", " ) << my::lable_coord[i] << " = " 
            << vec_point.at(i);

    std::cout << my::test_div;

    EXPECT_EQ(true, vec_point.at(0) == 0 && vec_point.at(1) == 0 && vec_point.at(2) == 0);
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