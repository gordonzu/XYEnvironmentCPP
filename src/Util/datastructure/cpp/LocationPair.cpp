// LocationPair.cpp
#include "Util/datastructure/include/LocationPair.h"

LocationPair::LocationPair(XYLocation* xy, std::vector<EnvironmentObject*>* envs)
                            : xy_{xy}, envs_{envs}
{
}

/*size_t LocationPair::getEnvsSize()
{
    return envs_->size();
}*/

std::vector<EnvironmentObject*>* LocationPair::get_envs() 
{
    return envs_;
} 

XYLocation* LocationPair::get_xy() 
{
    return xy_;
}


