#include <iostream>
#include <chrono>
#include <vector>
//#include <cstring>
//#include "transform.h"
#include "lib/shape/shape.h"


//static const unsigned char CHAR_BUFF = 255;

namespace my
{
    const std::string shape_to_str(Shape& shape)
    {
        //char str[CHAR_BUFF]{0};
        const std::string div = ", ";

        std::vector<std::string> figure{
            "line",
            "rectanle",
            "cube",
            "circle",
            "cylinder",
        };

//        const std::string str_t = "Figure: " + figure.at(shape.getType());
        std::cout << "Shape type: " << shape.getType() << '\n';
        const std::string str_t = "Figure: " + figure.at(0);

        std::vector<std::string> params{
            //"Figure: " + figure.at(shape.getType()),
            str_t,
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
    Shape line(0, 1, 2, 3, 4);

    std::cout << my::shape_to_str(line) << '\n';

    return 0;
}