#ifndef XY_ENVIRONMENT_H
#define XY_ENVIRONMENT_H

#include <vector>
#include <memory>
#include "agent/environment_object.h"
#include "agent/abstract_environment.h"
#include "util/datastructure/xy_location.h"

class XYEnvironment: public AbstractEnvironment {
public:
    XYEnvironment(); 
    XYEnvironment(int w, int h); 
    virtual ~XYEnvironment();

    void                                moveObject(EnvironmentObject* eo, const XYLocation::Direction& dir);
    void                                addObjectToLocation(EnvironmentObject* eo, XYLocation& loc); 
    void                                moveObjectToAbsoluteLocation(EnvironmentObject* eo, XYLocation& loc);
    bool                                isBlocked(XYLocation& loc);
    std::shared_ptr<XYLocation>         getCurrentLocationFor(EnvironmentObject* eo); 
    std::vector<EnvironmentObject*>&    getObjectsAt(XYLocation& loc);

    std::vector<std::pair<XYLocation,std::vector<EnvironmentObject*>>>& get_vector();
private:
    class XYEnvironmentState;
    std::unique_ptr<XYEnvironmentState> envState;
};
#endif


