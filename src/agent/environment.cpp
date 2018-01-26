// AbstractEnvironment.h

#include <iostream>
#include "environment.h"

std::vector<Agent*>& Environment::get_agents() 
{
    return agents;
}

void Environment::add_eo(Object* eo)
{
    envs.push_back(eo);
    if (Agent* a = dynamic_cast<Agent*>(eo)) {
        agents.push_back(a);            
    }
}

std::vector<Object*>& Environment::get_envs()  
{
    return envs;    
}

