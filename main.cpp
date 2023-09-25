#include <iostream>
#include <gtest/gtest.h>
#include <chrono>
#include <vector>
//#include <cstring>
//#include "transform.h"
#include "lib/shape/shape.h"
#include "lib/point/point.h"


//static const unsigned char CHAR_BUFF = 255;

namespace my
{
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

int main()
{
    //Shape f1(0, 1, 2, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); //line

    //std::cout << my::shape_to_str(f1) << '\n';


    return 0;
}