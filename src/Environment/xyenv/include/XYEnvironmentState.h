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

using PtrEnv = std::shared_ptr<EnvironmentObject>;

class XYEnvironmentState {
public:
    XYEnvironmentState(int w, int h);

    void                        moveObjectToAbsoluteLocation(PtrEnv eo, XYLocation* loc);
    XYLocation*                 getCurrentLocationFor(PtrEnv eo); 
    std::vector<LocationPair>&  get_vector(); 
    std::vector<PtrEnv>&        getObjectsAt(XYLocation* loc); 

private:
    int                         width_;
    int                         height_;
    void                        initState(); 
    std::vector<PtrEnv>         env_vector;
    std::vector<LocationPair>   vecPairs;

};
#endif


