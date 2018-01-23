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

class XYEnvironmentState {
public:
    XYEnvironmentState(int w, int h);
    ~XYEnvironmentState();

    void                                moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation& loc);
    std::shared_ptr<XYLocation>         getCurrentLocationFor(EnvironmentObject* eo); 

    std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>>& get_vector();


    std::vector<EnvironmentObject*>&    getObjectsAt(XYLocation& loc); 
    EnvironmentObject*                  get_pointer();

private:
    int                             width_;
    int                             height_;
    void                            initState(); 
    std::vector<EnvironmentObject*> env_vector;
    std::vector<std::pair<XYLocation, std::vector<EnvironmentObject*>>> vecPairs;
    EnvironmentObject*              env_ptr;
    XYLocation                      xy_;
    XYLocation                      NULL_XYLOCATION;

};
#endif


