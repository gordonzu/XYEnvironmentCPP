// XYEnvironmentState.cpp
#include "xyenv/include/XYEnvironmentState.h"

// XYLocation
void XYLocation::xylocation() 
{
    std::cout << "XYLocation: width= " << width_ << " height= " << height_ << std::endl;
}

bool XYLocation::operator==(const XYLocation& rhs) const 
{
        return ((width_ == rhs.width_) && (height_ == rhs.height_));
}

// EnvironmentObject
EnvironmentObject::~EnvironmentObject() 
{
}

// Agent
Agent::~Agent()
{
}






















