//
// Created by gordonzu on 4/24/18.

#include "agent_program.h"

constexpr const char* TableDrivenAgentProgram::ACTION;

TableDrivenAgentProgram::TableDrivenAgentProgram(std::multimap<std::vector<Percept>, Action*> m)
{
    set_table(m);
}

void TableDrivenAgentProgram::set_table(std::multimap<std::vector<Percept>, Action*> m)
{
    std::transform(
        m.begin(), m.end(), std::back_inserter(row_headers),
        [](auto& pair){ return pair.first; }
    );

    col_headers.emplace_back(ACTION);
    table = Table<std::vector<Percept>,
                  std::string, Action*>(row_headers, col_headers);

    for (auto& x: row_headers) {
        auto y = (m.find(x)->second);
        table.set_values(x, ACTION, y);
    }
}

Action* TableDrivenAgentProgram::lookup_action()
{
    Action* action = nullptr;
    bool b = table.get_values(percepts, ACTION, action);

    if (b == false) return ag::NoOpAction::NoOpPtr();

    return action;
}

Action* TableDrivenAgentProgram::execute(const Percept& p)
{
    percepts.emplace_back(p);
    return lookup_action();
}





