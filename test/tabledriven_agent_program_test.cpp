// Created by gordonzu on 4/1/18.

#include <memory>
#include "gmock/gmock.h"
#include "agent/agent.h"
#include "agent/percept.h"
#include "agent/base_action.h"
#include "agent/agent_programs/agent_program.h"

using namespace::testing;

class TableDrivenAgentProgramTest: public Test
{
    void load_map(std::initializer_list<DynamicPercept> p,
                    std::vector<DynamicPercept> v,
                    DynamicAction* action)
    {
        v.insert(v.end(), p.begin(), p.end());
        sequences.emplace(v, action);
    }

public:
    void SetUp() override
    {
        ACTION_1 = std::make_unique<DynamicAction>("action1");
        ACTION_2 = std::make_unique<DynamicAction>("action2");
        ACTION_3 = std::make_unique<DynamicAction>("action3");
        percept1 = DynamicPercept{"key1", "value1"};
        percept2 = DynamicPercept{"key1", "value2"};
        percept3 = DynamicPercept{"key1", "value3"};

        load_map({percept1}, vec1, ACTION_1.get());
        load_map({percept1, percept2}, vec2, ACTION_2.get());
        load_map({percept1, percept2, percept3}, vec3, ACTION_3.get());
        program = std::make_unique<TableDrivenAgentProgram>(sequences);
        agent = Agent{program.get()};
    }

    std::multimap<std::vector<DynamicPercept>, DynamicAction*> sequences;
    std::vector<DynamicPercept> vec1;
    std::vector<DynamicPercept> vec2;
    std::vector<DynamicPercept> vec3;
    std::unique_ptr<DynamicAction> ACTION_1;
    std::unique_ptr<DynamicAction> ACTION_2;
    std::unique_ptr<DynamicAction> ACTION_3;
    std::unique_ptr<AgentProgram> program;
    DynamicPercept percept1;
    DynamicPercept percept2;
    DynamicPercept percept3;
    Agent agent;
};

TEST_F(TableDrivenAgentProgramTest, testAgentTalks)
{
    ASSERT_STREQ(agent.talk(), "Agent...");
}

TEST_F(TableDrivenAgentProgramTest, testNullPropram)
{
    Agent a;
    a.set_program(nullptr);
    auto action = a.execute(DynamicPercept{});
    ASSERT_TRUE(action->is_no_op());
}

TEST_F(TableDrivenAgentProgramTest, testLiveProgram)
{
    agent.set_program(program.get());
    auto action = agent.execute(DynamicPercept{"key1", "value1"});
    ASSERT_FALSE(action->is_no_op());
}

TEST_F(TableDrivenAgentProgramTest, testExistingSequences)
{
    agent.set_program(program.get());
    ASSERT_EQ(*(agent.execute(DynamicPercept{"key1", "value1"})), *ACTION_1);
    ASSERT_EQ(*(agent.execute(DynamicPercept{"key1", "value2"})), *ACTION_2);
    ASSERT_EQ(*(agent.execute(DynamicPercept{"key1", "value3"})), *ACTION_3);
}

TEST_F(TableDrivenAgentProgramTest, testNonExistingSequences)
{
    agent.set_program(program.get());
    ASSERT_EQ(*(agent.execute(DynamicPercept{"key1", "value1"})), *ACTION_1);
    ASSERT_EQ(*(agent.execute(DynamicPercept{"key1", "value3"})), *NoOpAction::NoOpPtr());
}

//TODO: search for returning the address of a local variable as a pointer return value

