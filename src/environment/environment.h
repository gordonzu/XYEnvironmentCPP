#ifndef ABSTRACT_ENVIRONMENT_H
#define ABSTRACT_ENVIRONMENT_H

#include <set>
#include <memory>
#include <iostream>
#include "agent/agent.h"

//using namespace::ag;

class Environment {
public:
    void                 add_obj(Object* eo);
    void                 add_agent(Agent* a);
    std::set<Object*>&   get_objs();
    std::set<Agent*>&    get_agents();

protected:
    std::set<Object*>    objs;
    std::set<Agent*>     agents;
};
#endif


