// XYLocation.cpp

#include "Util/datastructure/include/XYLocation.h"

XYLocation::XYLocation()
{
}

XYLocation::XYLocation(int x, int y): x_{x}, y_{y}
{
}

void XYLocation::print() 
{
    std::cout << "XYLocation: width= " << x_ << " height= " << y_ << std::endl;
}

int XYLocation::getx()
{
    return x_;
}

int XYLocation::gety()
{
    return y_;
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
*/
void XYLocation::north()
{
    this->y_--;
}
/*
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
*/
void XYLocation::locationAt(const Direction& direction)
{
    try
    {
        switch (direction) 
        {
            case     Direction::NORTH:
                     north();
                     break;
            /*case     Direction::SOUTH:
                     xy = south();
                     break;
            case     Direction::EAST:
                     xy = east();
                     break;
            case     Direction::WEST:
                     xy = west();
                     break;
            */
            default: throw std::runtime_error("Unknown direction: ");
        } 
    }
    catch(std::exception const& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}


