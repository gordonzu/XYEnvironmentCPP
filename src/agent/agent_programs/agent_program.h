//
// Created by gordonzu on 4/22/18.
//

#ifndef AICPP_AGENT_PROGRAM_H
#define AICPP_AGENT_PROGRAM_H

#include <agent/base_action.h>
#include <agent/percept.h>

class AgentProgram {
public:
    virtual ~AgentProgram()=default;
    virtual std::unique_ptr<BaseAction> execute(Percept* p)=0;
};

class TableDrivenAgentProgram: public AgentProgram {
public:
    TableDrivenAgentProgram()=default;
    ~TableDrivenAgentProgram() override =default;

    virtual std::unique_ptr<BaseAction> execute(Percept* p) {
        return DynamicAction::DynamicPtr();
    }
};

#endif //AICPP_AGENT_PROGRAM_H
