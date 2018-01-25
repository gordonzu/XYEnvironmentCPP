#ifndef XY_ENVIRONMENT_H
#define XY_ENVIRONMENT_H

#include <vector>
#include <memory>
#include "agent/agent.h"
#include "agent/abstract_environment.h"
#include "util/datastructure/xy_location.h"

class Wall: public EnvironmentObject {
public:
    virtual ~Wall() {}
};

class XYEnvironment: public AbstractEnvironment {
public:
    XYEnvironment(); 
    XYEnvironment(int w, int h); 
    virtual ~XYEnvironment();

    void                                move_object(EnvironmentObject* eo, const XYLocation::Direction& dir);
    void                                add_to(EnvironmentObject* eo, XYLocation& loc); 
    void                                move_to(EnvironmentObject* eo, XYLocation& loc);
    bool                                is_blocked(XYLocation& loc);
    std::shared_ptr<XYLocation>         get_location(EnvironmentObject* eo); 
    std::vector<EnvironmentObject*>&    get_at(XYLocation& loc);

    std::vector<std::pair<XYLocation,std::vector<EnvironmentObject*>>>& get_vector();

private:
    class XYEnvironmentState;
    std::unique_ptr<XYEnvironmentState> envState;
};
#endif


