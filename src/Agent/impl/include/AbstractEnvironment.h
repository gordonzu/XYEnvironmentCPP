#ifndef ABSTRACT_ENVIRONMENT_H
#define ABSTRACT_ENVIRONMENT_H

#include <vector>
#include <memory>
#include <iostream>
#include "Agent/include/Agent.h"
#include "Agent/include/EnvironmentObject.h"

using PtrEnv = std::shared_ptr<EnvironmentObject>;
using PtrAgt = std::shared_ptr<Agent>;

class AbstractEnvironment {
public:
    void                        addEnvironmentObject(PtrEnv eo);
    const std::vector<PtrAgt>&  getAgents() const; 
    const std::vector<PtrEnv>&  getEnvironmentObjects() const;  

protected:
    std::vector<PtrEnv> envObjects;
    std::vector<PtrAgt> agents;
};
#endif


