// XYLocation.cpp

#include "util/datastructure/xy_location.h"

XYLocation::XYLocation() 
{
}

XYLocation::XYLocation(int x, int y): x_{x}, y_{y}
{
}

XYLocation::XYLocation(XYLocation&& other): x_{0}, y_{0}
{
    x_ = other.x_;
    y_ = other.y_;

    other.x_ = 0;
    other.y_ = 0;
}

XYLocation::~XYLocation()
{
}

XYLocation::XYLocation(const XYLocation& other)
{
    x_ = other.x_;
    y_ = other.y_;
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

XYLocation& XYLocation::operator=(const XYLocation& rhs)
{
    if (&rhs != this) {
        x_ = rhs.x_;
        y_ = rhs.y_;
    }
    return *this;
}

bool XYLocation::operator<(const XYLocation& rhs) const 
{
    return x_ < rhs.x_ || (!(rhs.x_ < x_) && y_ < rhs.y_);
} 

bool XYLocation::operator==(const XYLocation& rhs) const  
{
        return ((x_ == rhs.x_) && (y_ == rhs.y_));
}

std::shared_ptr<XYLocation> XYLocation::west()
{
    return std::make_shared<XYLocation>(x_ - 1, y_);
}

std::shared_ptr<XYLocation> XYLocation::east()
{
    return std::make_shared<XYLocation>(x_ + 1, y_);
}

std::shared_ptr<XYLocation> XYLocation::north()
{
    return std::make_shared<XYLocation>(x_, y_ -1);
}

std::shared_ptr<XYLocation> XYLocation::south()
{
    return std::make_shared<XYLocation>(x_, y_ + 1);
}

std::shared_ptr<XYLocation> XYLocation::right()
{
    return east();
}

std::shared_ptr<XYLocation> XYLocation::left()
{
    return west();
}

std::shared_ptr<XYLocation> XYLocation::up()
{
    return north();
}

std::shared_ptr<XYLocation> XYLocation::down()
{
    return south();
}

std::shared_ptr<XYLocation> XYLocation::location_at(const Direction& direction)
{
    std::shared_ptr<XYLocation> xy;
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
            default: throw std::runtime_error("Unknown direction...");
        } 
    }
    catch(std::exception const& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return xy;
}


