// XYEnvironmentState.h
#ifndef XY_ENVIRONMENT_STATE_H
#define XY_ENVIRONMENT_STATE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "Util/datastructure/include/XYLocation.h"
#include "Agent/include/EnvironmentObject.h"
#include "Util/datastructure/include/LocationPair.h"

class XYEnvironmentState {
public:
    XYEnvironmentState(int w, int h);
    void moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc);
    std::vector<EnvironmentObject*>* getObjectsAt(XYLocation* loc); 
    XYLocation* getCurrentLocationFor(EnvironmentObject* eo); 
    std::vector<LocationPair>* get_vector(); 

private:
    std::vector<LocationPair>*          vecPairs;
    std::vector<EnvironmentObject*>*    vecEnvs;
    int                                 width_;
    int                                 height_;
    void initState(); 
};
#endif


