// XYLocation.cpp

#include "Util/datastructure/include/XYLocation.h"

XYLocation::XYLocation()
{
}

XYLocation::XYLocation(int x, int y): x_{x}, y_{y}
{
}


void XYLocation::xylocation() 
{
    std::cout << "XYLocation: width= " << x_ << " height= " << y_ << std::endl;
}

bool XYLocation::operator==(const XYLocation& rhs) const  
{
        return ((x_ == rhs.x_) && (y_ == rhs.y_));
}
/*
XYLocation* XYLocation::west()
{
    return new XYLocation(x_ - 1, y_);
}

XYLocation* XYLocation::east()
{
    return new XYLocation(x_ + 1, y_);
}

XYLocation* XYLocation::north()
{
    return new XYLocation(x_, y_ - 1);
}

XYLocation* XYLocation::south()
{
    return new XYLocation(x_, y_ + 1);
}

XYLocation* XYLocation::right()
{
    return east();
}

XYLocation* XYLocation::left()
{
    return west();
}

XYLocation* XYLocation::up()
{
    return north();
}

XYLocation* XYLocation::down()
{
    return south();
}

XYLocation* XYLocation::locationAt(const Direction& direction)
{
    XYLocation* xy;
    try
    {
        switch (direction) 
        {
            case     Direction::NORTH:
                     xy = north();
                     break;
            case     Direction::SOUTH:
                     xy = south();
                     break;
            case     Direction::EAST:
                     xy = east();
                     break;
            case     Direction::WEST:
                     xy = west();
                     break;
            default: throw std::runtime_error("Unknown direction: ");
        }
    }
    catch(std::exception const& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return xy;
}
*/

