// XYEnvironmentState.h

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
    void addObjectToLocation(EnvironmentObject* eo, XYLocation* loc); 
    void moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc);
    std::vector<EnvironmentObject*>* getObjectsAt(XYLocation* loc); 
    void addEnvironmentObject(EnvironmentObject* eo); 
    XYLocation* getCurrentLocationFor(EnvironmentObject* eo); 
    std::vector<LocationPair>* getVector(); 

private:
    std::vector<LocationPair>*          vecPairs;
    std::vector<EnvironmentObject*>*    vecEnvs;
    int                                 width_;
    int                                 height_;
    void initState(); 
};



