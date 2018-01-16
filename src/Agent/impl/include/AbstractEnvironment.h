#ifndef ABSTRACT_ENVIRONMENT_H
#define ABSTRACT_ENVIRONMENT_H

#include <vector>
#include <memory>
#include <iostream>
#include "Agent/include/Agent.h"
#include "Agent/include/EnvironmentObject.h"

using PtrAgt = std::shared_ptr<Agent>;

class AbstractEnvironment {
public:
    void                                    addEnvironmentObject(EnvironmentObject* eo);
    const std::vector<PtrAgt>&              getAgents() const; 
    const std::vector<EnvironmentObject*>&  getEnvironmentObjects() const;  

protected:
    std::vector<EnvironmentObject*> envObjects;
    std::vector<PtrAgt>             agents;
};
#endif


