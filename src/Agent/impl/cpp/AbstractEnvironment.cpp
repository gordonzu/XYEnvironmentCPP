// AbstractEnvironment.h

#include "Agent/impl/include/AbstractEnvironment.h"

std::vector<std::shared_ptr<Agent>>& AbstractEnvironment::getAgents()
{
    return agents;
}

void AbstractEnvironment::addEnvironmentObject(std::shared_ptr<EnvironmentObject> eo)
{
    envObjects.push_back(eo);
    if (Agent* a = dynamic_cast<Agent*>(eo.get())) {
        agents.push_back(std::make_shared<Agent>(*a));            
    }          
}

const std::vector<std::shared_ptr<EnvironmentObject>>& AbstractEnvironment::getEnvironmentObjects() const 
{
    return envObjects;    
}

