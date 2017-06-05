// AbstractEnvironment.h

#include "Agent/impl/include/AbstractEnvironment.h"

std::vector<Agent*>& AbstractEnvironment::getAgents()
{
    return agents;
}

void AbstractEnvironment::addEnvironmentObject(EnvironmentObject* eo)
{
    envObjects.push_back(eo);
    if (Agent* a = dynamic_cast<Agent*>(eo)) {
        agents.push_back(a);            
    }          
}

const std::vector<EnvironmentObject*>& AbstractEnvironment::getEnvironmentObjects() const 
{
    return envObjects;    
}

