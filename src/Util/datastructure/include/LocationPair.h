// LocationPair.h
#ifndef LOCATION_PAIR_H
#define LOCATION_PAIR_H

#include <vector>
#include <memory>
#include "Util/datastructure/include/XYLocation.h"
#include "Agent/include/EnvironmentObject.h"

class LocationPair {
public:
    LocationPair(XYLocation* xy, std::vector<std::shared_ptr<EnvironmentObject>>* envs);
    //size_t getEnvsSize();
    std::vector<std::shared_ptr<EnvironmentObject>>* get_envs();
    XYLocation* get_xy();

private:
    XYLocation* xy_;
    std::vector<std::shared_ptr<EnvironmentObject>>* envs_;    
};
#endif

