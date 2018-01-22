// LocationPair.cpp
#include "Util/datastructure/include/LocationPair.h"

LocationPair::LocationPair(const XYLocation& xy, std::vector<EnvironmentObject*>& envs)
                            : xy_{xy}, envs_{envs}
{
}
 
LocationPair::LocationPair(const XYLocation& xy, std::vector<EnvironmentObject*>&& envs)
                            : xy_{xy}, envs_{std::move(envs)}
{
}

LocationPair::~LocationPair()
{
}

size_t LocationPair::getEnvsSize()
{
    return envs_.size();
}

std::vector<EnvironmentObject*>& LocationPair::get_envs() 
{
    return envs_;
} 

XYLocation& LocationPair::get_xy() 
{
    return xy_;
}


