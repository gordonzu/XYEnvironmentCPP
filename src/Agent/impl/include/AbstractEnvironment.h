#ifndef ABSTRACT_ENVIRONMENT_H
#define ABSTRACT_ENVIRONMENT_H

#include <vector>
#include <memory>
#include "Agent/include/Agent.h"
#include "Agent/include/EnvironmentObject.h"

class AbstractEnvironment {
public:
    void                                                    addEnvironmentObject(std::shared_ptr<EnvironmentObject> eo);
    std::vector<Agent*>&                                    getAgents(); 
    const std::vector<std::shared_ptr<EnvironmentObject>>&  getEnvironmentObjects() const;  

protected:
    std::vector<std::shared_ptr<EnvironmentObject>> envObjects;
    std::vector<Agent*>                             agents;
};
#endif


