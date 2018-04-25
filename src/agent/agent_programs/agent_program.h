//
// Created by gordonzu on 4/22/18.

#ifndef AICPP_AGENT_PROGRAM_H
#define AICPP_AGENT_PROGRAM_H

#include "util/datastructure/table.h"
#include "util/datastructure/table.cpp"
#include "agent/action.h"
#include "agent/percept.h"
#include <algorithm>

using namespace::ag;

class AgentProgram
{
public:
    virtual ~AgentProgram()=default;
    virtual Action* execute(const Percept& p)=0;
};

class TableDrivenAgentProgram: public AgentProgram
{
    static constexpr const char* ACTION = "action";
    std::vector<Percept> percepts;
    std::vector<std::vector<Percept>> row_headers;
    std::vector<std::string> col_headers;

    Table<std::vector<Percept>, std::string, Action*> table;

    ag::Action* lookup_action();

public:
    TableDrivenAgentProgram()=delete;
    ~TableDrivenAgentProgram() override =default;
    TableDrivenAgentProgram(std::multimap<std::vector<Percept>,
                            Action*> m);

    void set_table(std::multimap<std::vector<Percept>, Action*> m);
    virtual Action* execute(const Percept& p);
};

#endif //AICPP_AGENT_PROGRAM_H





