#ifndef ABSTRACT_ENVIRONMENT_H
#define ABSTRACT_ENVIRONMENT_H

#include <vector>
#include <memory>
#include <iostream>
#include "object.h"

class Environment {
public:
    void                    add_eo(Object* eo);
    std::vector<Agent*>&    get_agents(); 
    std::vector<Object*>&   get_envs();  

protected:
    std::vector<Object*>    envs;
    std::vector<Agent*>     agents;
};
#endif


