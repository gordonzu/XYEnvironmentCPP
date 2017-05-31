#ifndef XY_ENVIRONMENT_H
#define XY_ENVIRONMENT_H

#include "Agent/include/EnvironmentObject.h"
#include "Util/datastructure/include/XYLocation.h"
#include "Agent/impl/include/AbstractEnvironment.h"
#include "Environment/xyenv/include/XYEnvironmentState.h"

class XYEnvironment: public AbstractEnvironment {
public:
    XYEnvironment(); 
    XYEnvironment(int w, int h); 
    virtual ~XYEnvironment();
    void addObjectToLocation(EnvironmentObject* eo, XYLocation* loc); 
    void moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation* loc);
    XYLocation* getCurrentLocationFor(EnvironmentObject* eo); 

private:
    XYEnvironmentState* envState;
};
#endif


