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
    ~XYEnvironmentState();

    void                                moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc);
    XYLocation*         				getCurrentLocationFor(EnvironmentObject* eo); 
    std::vector<LocationPair>&          get_vector(); 
    std::vector<EnvironmentObject*>&    getObjectsAt(XYLocation* loc); 
    EnvironmentObject*                  get_pointer();

private:
    int                             width_;
    int                             height_;
    void                            initState(); 
    std::vector<EnvironmentObject*> env_vector;
    std::vector<LocationPair>       vecPairs;
    EnvironmentObject*              env_ptr;
    XYLocation*                     xy_;

};
#endif


