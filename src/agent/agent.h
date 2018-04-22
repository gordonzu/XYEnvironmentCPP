//
// Created by gordonzu on 4/15/18.

#ifndef AICPP_AGENT_H
#define AICPP_AGENT_H

#include "base_object.h"
#include "base_action.h"
#include "percept.h"
#include "agent_programs/agent_program.h"

class Agent : public Object {
protected:
    AgentProgram* ap;

public:
    Agent(): ap{nullptr} {}
    Agent(AgentProgram* program): ap{program} {}
    ~Agent() override =default;

    const char* talk() { return "Agent..."; }

    bool set_program(AgentProgram* program) {
        if (program) {
            ap = program;
            return true;
        }
        return false;
    }

    std::unique_ptr<BaseAction> execute(Percept* per) {
        if (ap != nullptr)
            return ap->execute(per);
        return NoOpAction::NoOpPtr();
    }
};

#endif //AICPP_AGENT_H




