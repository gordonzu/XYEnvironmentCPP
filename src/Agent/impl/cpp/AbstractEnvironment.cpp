// AbstractEnvironment.h

#include "Agent/impl/include/AbstractEnvironment.h"

const std::vector<PtrAgt>& AbstractEnvironment::getAgents() const
{
    return agents;
}

void AbstractEnvironment::addEnvironmentObject(PtrEnv eo)
{
    envObjects.push_back(eo);
    if (Agent* a = dynamic_cast<Agent*>(eo.get())) {
        agents.push_back(std::make_shared<Agent>(*a));            
    }          
}

const std::vector<PtrEnv>& AbstractEnvironment::getEnvironmentObjects() const 
{
    return envObjects;    
}

