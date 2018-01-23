#ifndef XY_ENVIRONMENT_H
#define XY_ENVIRONMENT_H

#include <vector>
#include <memory>
#include "Agent/include/EnvironmentObject.h"
#include "Util/datastructure/include/XYLocation.h"
#include "Agent/impl/include/AbstractEnvironment.h"

class XYEnvironment: public AbstractEnvironment {
public:
    XYEnvironment(); 
    XYEnvironment(int w, int h); 
    virtual ~XYEnvironment();

    void                                addObjectToLocation(EnvironmentObject* eo, XYLocation& loc); 
    void                                moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation& loc);
    std::shared_ptr<XYLocation>         getCurrentLocationFor(EnvironmentObject* eo); 
    std::vector<std::pair<XYLocation,   std::vector<EnvironmentObject*>>>& get_vector();

    std::vector<EnvironmentObject*>&    getObjectsAt(XYLocation& loc);
    void                                moveObject(EnvironmentObject* eo, const XYLocation::Direction& dir);
    bool                                isBlocked(XYLocation& loc);

private:
    class XYEnvironmentState;
    std::unique_ptr<XYEnvironmentState> envState;
};
#endif


