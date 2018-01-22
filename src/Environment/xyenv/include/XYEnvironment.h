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

    void                                addObjectToLocation(EnvironmentObject* eo, const XYLocation& loc); 
    void                                moveObjectToAbsoluteLocation(EnvironmentObject* eo, const XYLocation& loc);
    //XYLocation&         				getCurrentLocationFor(EnvironmentObject* eo); 
    std::shared_ptr<XYLocation>         getCurrentLocationFor(EnvironmentObject* eo); 
    std::vector<LocationPair>&          get_vector();
    std::vector<EnvironmentObject*>&    getObjectsAt(const XYLocation& loc);
    void                                moveObject(EnvironmentObject* eo, const XYLocation::Direction& dir);
    bool                                isBlocked(XYLocation& loc);

private:
    XYEnvironmentState* envState;
    XYLocation*         moveTo;
};
#endif


