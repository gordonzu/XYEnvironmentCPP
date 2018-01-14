// LocationPair.cpp
#include "Util/datastructure/include/LocationPair.h"

LocationPair::LocationPair(std::shared_ptr<XYLocation> xy, std::vector<PtrEnv>& envs)
                            : xy_{xy}, envs_{envs}
{
}

LocationPair::LocationPair(std::shared_ptr<XYLocation> xy, std::vector<PtrEnv>&& envs)
                            : xy_{xy}, envs_{std::move(envs)}
{
}

size_t LocationPair::getEnvsSize()
{
    return envs_.size();
}

std::vector<PtrEnv>& LocationPair::get_envs() 
{
    return envs_;
} 

std::shared_ptr<XYLocation> LocationPair::get_xy() 
{
    return xy_;
}


