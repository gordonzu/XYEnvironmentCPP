#ifndef ABSTRACT_ENVIRONMENT_H
#define ABSTRACT_ENVIRONMENT_H

#include <vector>
#include "Agent/include/Agent.h"
#include "Agent/include/EnvironmentObject.h"

class AbstractEnvironment {
public:
    std::vector<Agent*>& getAgents(); 
    void addEnvironmentObject(EnvironmentObject* eo);
    const std::vector<EnvironmentObject*>& getEnvironmentObjects() const;  

protected:
    std::vector<EnvironmentObject*> envObjects;
    std::vector<Agent*> agents;
};
#endif


