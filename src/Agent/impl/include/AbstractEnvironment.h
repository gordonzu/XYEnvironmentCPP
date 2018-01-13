#ifndef ABSTRACT_ENVIRONMENT_H
#define ABSTRACT_ENVIRONMENT_H

#include <vector>
#include "Agent/include/Agent.h"
#include "Agent/include/EnvironmentObject.h"

class AbstractEnvironment {
public:
    void                                    addEnvironmentObject(EnvironmentObject* eo);
    std::vector<Agent*>&                    getAgents(); 
    const std::vector<EnvironmentObject*>&  getEnvironmentObjects() const;  

protected:
    std::vector<EnvironmentObject*> envObjects;
    std::vector<Agent*>             agents;
};
#endif


