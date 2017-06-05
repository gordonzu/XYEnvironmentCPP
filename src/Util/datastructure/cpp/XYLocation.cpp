// XYLocation.cpp

#include "Util/datastructure/include/XYLocation.h"

XYLocation::XYLocation(int w, int h): width_{w}, height_{h}
{
}


void XYLocation::xylocation() 
{
    std::cout << "XYLocation: width= " << width_ << " height= " << height_ << std::endl;
}

bool XYLocation::operator==(const XYLocation& rhs) const  
{
        return ((width_ == rhs.width_) && (height_ == rhs.height_));
}


