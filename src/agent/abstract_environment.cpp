// AbstractEnvironment.h

#include <iostream>
#include "abstract_environment.h"

std::vector<Agent*>& AbstractEnvironment::get_agents() 
{
    return agents;
}

void AbstractEnvironment::add_eo(EnvironmentObject* eo)
{
    envs.push_back(eo);
    if (Agent* a = dynamic_cast<Agent*>(eo)) {
        agents.push_back(a);            
    }
}

std::vector<EnvironmentObject*>& AbstractEnvironment::get_envs()  
{
    return envs;    
}

