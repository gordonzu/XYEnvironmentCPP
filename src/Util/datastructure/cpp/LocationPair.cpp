// LocationPair.cpp
#include "Util/datastructure/include/LocationPair.h"

LocationPair::LocationPair(XYLocation* xy, std::vector<EnvironmentObject*>& envs)
                            : xy_{xy}, envs_{envs}
{
}

LocationPair::LocationPair(XYLocation* xy, std::vector<EnvironmentObject*>&& envs)
                            : xy_{xy}, envs_{std::move(envs)}
{
}

LocationPair::~LocationPair()
{
    //delete xy_;
    //xy_ = nullptr;
}

size_t LocationPair::getEnvsSize()
{
    return envs_.size();
}

std::vector<EnvironmentObject*>& LocationPair::get_envs() 
{
    return envs_;
} 

XYLocation* LocationPair::get_xy() 
{
    return xy_;
}


