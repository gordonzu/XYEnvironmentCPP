#ifndef XY_ENVIRONMENT_H
#define XY_ENVIRONMENT_H

#include <vector>
#include <memory>
#include "Agent/include/EnvironmentObject.h"
#include "Util/datastructure/include/XYLocation.h"
#include "Util/datastructure/include/LocationPair.h"
#include "Agent/impl/include/AbstractEnvironment.h"
#include "Environment/xyenv/include/XYEnvironmentState.h"

class XYEnvironment: public AbstractEnvironment {
public:
    XYEnvironment(); 
    XYEnvironment(int w, int h); 
    virtual ~XYEnvironment();
    void addObjectToLocation(std::shared_ptr<EnvironmentObject> eo, XYLocation* loc); 
    void moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc);
    XYLocation* getCurrentLocationFor(EnvironmentObject* eo); 
    std::vector<EnvironmentObject*>* getObjectsAt(XYLocation* loc);
    std::vector<LocationPair>* get_vector();

private:
    XYEnvironmentState* envState;
};
#endif


