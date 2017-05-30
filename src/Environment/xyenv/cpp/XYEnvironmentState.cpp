// XYEnvironmentState.cpp
#include "xyenv/include/XYEnvironmentState.h"

void XYLocation::xylocation() 
{
    std::cout << "XYLocation: width= " << width_ << " height= " << height_ << std::endl;
}

bool XYLocation::operator==(const XYLocation& rhs) const 
{
        return ((width_ == rhs.width_) && (height_ == rhs.height_));
}


