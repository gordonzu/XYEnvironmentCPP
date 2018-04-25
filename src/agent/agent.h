//
// Created by gordonzu on 4/15/18.

#ifndef AICPP_AGENT_H
#define AICPP_AGENT_H

#include "environment/environment_object.h"
#include "action.h"
#include "percept.h"
#include "agent_programs/agent_program.h"

class Agent : public EnvironmentObject
{
protected:
    AgentProgram* ap;

public:
    Agent(): ap{nullptr} {}
    Agent(AgentProgram* program): ap{program} {}
    ~Agent() override =default;

    const char* talk() { return "Agent..."; }

    bool set_program(AgentProgram* program)
    {
        if (program) {
            ap = program;
            return true;
        }
        return false;
    }

    Action* execute(const Percept& per)
    {
        if (ap != nullptr) return ap->execute(per);
        return NoOpAction::NoOpPtr();
    }
};

#endif //AICPP_AGENT_H




