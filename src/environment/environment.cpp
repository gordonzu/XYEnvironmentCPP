// AbstractEnvironment.h

#include <iostream>
#include "environment/environment.h"

std::set<Agent*>& Environment::get_agents()
{
    return agents;
}

std::set<Object*>& Environment::get_objs()
{
    return objs;
}

void Environment::add_agent(Agent* a)
{
    agents.insert(a);
}

void Environment::add_obj(Object* eo)
{
    objs.insert(eo);
    if (auto a = dynamic_cast<Agent*>(eo)) {
        add_agent(a);
    }
}


