//
// Created by gordonzu on 4/1/18.

#include <agent/percept.h>
#include <agent/base_action.h>
#include <memory>
#include "gmock/gmock.h"
#include "agent/agent.h"

using namespace::testing;

class TableDrivenAgentTest: public Test
{

    void create_map(std::initializer_list<Percept*> p,
                    std::vector<Percept*> v,
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

        percept1 = std::make_unique<DynamicPercept>("key1", "value1");
        percept2 = std::make_unique<DynamicPercept>("key1", "value1");
        percept3 = std::make_unique<DynamicPercept>("key1", "value2");
        percept4 = std::make_unique<DynamicPercept>("key1", "value1");
        percept5 = std::make_unique<DynamicPercept>("key1", "value2");
        percept6 = std::make_unique<DynamicPercept>("key1", "value3");
        program = std::make_unique<TableDrivenProgram>();

        create_map({percept1.get()},
                    vec1,
                    ACTION_1.get());

        create_map({percept2.get(),
                    percept3.get()},
                    vec2,
                    ACTION_2.get());

        create_map({percept4.get(),
                    percept5.get(),
                    percept6.get()},
                    vec3,
                    ACTION_3.get());
    }

    Agent agent;
    Agent a;
    std::unique_ptr<AgentProgram> program;

    std::unique_ptr<Percept> percept1;
    std::unique_ptr<Percept> percept2;
    std::unique_ptr<Percept> percept3;
    std::unique_ptr<Percept> percept4;
    std::unique_ptr<Percept> percept5;
    std::unique_ptr<Percept> percept6;
    std::unique_ptr<DynamicAction> ACTION_1;
    std::unique_ptr<DynamicAction> ACTION_2;
    std::unique_ptr<DynamicAction> ACTION_3;

    std::vector<Percept*> vec1;
    std::vector<Percept*> vec2;
    std::vector<Percept*> vec3;
    std::map<std::vector<Percept*>, BaseAction*> sequences;
};

TEST_F(TableDrivenAgentTest, testAgentTalks)
{
    ASSERT_STREQ(agent.talk(), "Agent...");
}

TEST_F(TableDrivenAgentTest, testNullPropram)
{
    std::unique_ptr<Percept> per = std::make_unique<DynamicPercept>();
    a.set_program(nullptr);
    auto action = a.execute(per.get());
    ASSERT_TRUE(action->is_no_op());
}

TEST_F(TableDrivenAgentTest, testLiveProgram)
{
    std::unique_ptr<Percept> per = std::make_unique<DynamicPercept>("key1", "value1");
    std::unique_ptr<AgentProgram> p = std::make_unique<TableDrivenProgram>();
    a.set_program(p.get());
    auto action = a.execute(per.get());
    ASSERT_FALSE(action->is_no_op());
}

TEST_F(TableDrivenAgentTest, testExistingSequences)
{
    //ASSERT_STREQ(agent.execute(), "name");
    ASSERT_EQ(NoOpAction::NoOp(), NoOpAction::NoOp());
}

//TODO: search for returning the address of a local variable as a pointer return value















/*
    auto action = NoOpAction::NoOp();
    auto m = action.get_map();
    std::cout << "Map size: " << m.size() << std::endl;
*/
/*    const char* str = "name";

    auto search = m.find(str);
    if (search == m.end()) std::cout << "Past the end. " << std::endl;
*/
    //ASSERT_TRUE(true);

