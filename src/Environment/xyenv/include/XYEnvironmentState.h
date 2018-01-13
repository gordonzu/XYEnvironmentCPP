// XYEnvironmentState.h
#ifndef XY_ENVIRONMENT_STATE_H
#define XY_ENVIRONMENT_STATE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <memory>
#include "Util/datastructure/include/XYLocation.h"
#include "Agent/include/EnvironmentObject.h"
#include "Util/datastructure/include/LocationPair.h"

class XYEnvironmentState {
public:
    XYEnvironmentState(int w, int h);

    void                                                moveObjectToAbsoluteLocation(std::shared_ptr<EnvironmentObject> eo, XYLocation* loc);
    XYLocation*                                         getCurrentLocationFor(std::shared_ptr<EnvironmentObject> eo); 
    std::vector<LocationPair>*                          get_vector(); 
    std::vector<std::shared_ptr<EnvironmentObject>>*    getObjectsAt(XYLocation* loc); 

private:
    std::vector<std::shared_ptr<EnvironmentObject>>*    vecEnvs;
    std::vector<LocationPair>*                          vecPairs;
    int                                                 width_;
    int                                                 height_;
    void                                                initState(); 
};
#endif


