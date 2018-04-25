//
// Created by gordonzu on 4/22/18.

#ifndef AICPP_AGENT_PROGRAM_H
#define AICPP_AGENT_PROGRAM_H

#include "util/datastructure/table.h"
#include "util/datastructure/table.cpp"
#include "agent/base_action.h"
#include "agent/percept.h"
#include <algorithm>

class AgentProgram
{
public:
    virtual ~AgentProgram()=default;
    virtual DynamicAction* execute(const DynamicPercept& p)=0;
};

class TableDrivenAgentProgram: public AgentProgram
{
    static constexpr const char* ACTION = "action";
    std::vector<DynamicPercept> percepts;
    std::vector<std::vector<DynamicPercept>> row_headers;
    std::vector<std::string> col_headers;

    Table<std::vector<DynamicPercept>, std::string, DynamicAction*> table;

    DynamicAction* lookup_action();

public:
    TableDrivenAgentProgram()=delete;
    ~TableDrivenAgentProgram() override =default;
    TableDrivenAgentProgram(std::multimap<std::vector<DynamicPercept>,
                            DynamicAction*> m);

    void set_table(std::multimap<std::vector<DynamicPercept>, DynamicAction*> m);
    virtual DynamicAction* execute(const DynamicPercept& p);
};

#endif //AICPP_AGENT_PROGRAM_H





