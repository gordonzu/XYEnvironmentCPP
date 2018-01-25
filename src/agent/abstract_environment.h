#ifndef ABSTRACT_ENVIRONMENT_H
#define ABSTRACT_ENVIRONMENT_H

#include <vector>
#include <memory>
#include <iostream>
#include "agent.h"

class AbstractEnvironment {
public:
    void                              add_eo(EnvironmentObject* eo);
    std::vector<Agent*>&              get_agents(); 
    std::vector<EnvironmentObject*>&  get_envs();  

protected:
    std::vector<EnvironmentObject*> envs;
    std::vector<Agent*>             agents;
};
#endif


