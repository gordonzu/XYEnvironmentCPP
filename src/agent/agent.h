//
// Created by gordonzu on 4/15/18.
//

#ifndef AICPP_AGENT_H
#define AICPP_AGENT_H

#include "base_object.h"
#include "base_action.h"
#include "percept.h"

class AgentProgram {
public:
    virtual ~AgentProgram()=default;
    virtual const DynamicAction& execute(Percept* p)=0;
};

class TableDrivenProgram: public AgentProgram {
public:
    TableDrivenProgram()=default;
    ~TableDrivenProgram() override =default;

    virtual const DynamicAction& execute(Percept* p) {
        return NoOpAction::NoOp();
    }
};

class Agent : public Object {
protected:
    AgentProgram* ap;

public:
    Agent(): ap{nullptr} {}
    Agent(AgentProgram* program): ap{program} {}
    ~Agent() override =default;

    const char* talk() { return "Agent..."; }
    const char* execute() { return "name"; }

    bool set_program(AgentProgram* program) {
        if (program) {
            ap = program;
            return true;
        }
        return false;
    }

    const DynamicAction& execute(Percept* per) {
        if (ap != nullptr)
            return ap->execute(per);
        return NoOpAction::NoOp();
    }
};

#endif //AICPP_AGENT_H




