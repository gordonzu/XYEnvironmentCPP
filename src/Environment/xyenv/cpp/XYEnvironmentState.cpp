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

// AbstractAgent
AbstractAgent::~AbstractAgent()
{
}

// MockAgent
MockAgent::~MockAgent()
{
}

// LocationPair
LocationPair::LocationPair(XYLocation* xy, std::vector<EnvironmentObject*>* envs):
                           xy_{xy}, envs_{envs} 
{
} 
                            





































