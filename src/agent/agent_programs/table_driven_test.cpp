//
// Created by gordonzu on 4/1/18.

#include <agent/percept.h>
#include <agent/base_action.h>
#include <memory>
#include "gmock/gmock.h"
#include "agent/agent.h"

using namespace::testing;

class TableDrivenAgentTest: public Test {

    std::vector<Percept*> create_sequence(std::initializer_list<Percept*> p) {
        v.insert(v.end(), p.begin(), p.end());
        return v;
    }

public:
    void SetUp() override {
        ACTION_1 = std::make_unique<DynamicAction>("action1");
        percept = std::make_unique<DynamicPercept>("key1", "value1");
        program = std::make_unique<TableDrivenProgram>();

        v = create_sequence({percept.get()});
        sequences.emplace(v, ACTION_1.get());
    }

    Agent agent;
    Agent a;
    std::unique_ptr<Percept> percept;
    std::unique_ptr<BaseAction> ACTION_1;
    std::unique_ptr<AgentProgram> program;
    std::vector<Percept*> v;
    std::map<std::vector<Percept*>, BaseAction*> sequences;
};

TEST_F(TableDrivenAgentTest, testAgentTalks) {
    ASSERT_STREQ(agent.talk(), "Agent...");
    ASSERT_TRUE(true);
}

TEST_F(TableDrivenAgentTest, testNullAgentProgram) {
/*    auto action = NoOpAction::NoOp();
    auto m = action.get_map();
    std::cout << "Map size: " << m.size() << std::endl;
    const char* str = "name";

    auto search = m.find(str);
    if (search == m.end()) std::cout << "Past the end. " << std::endl;
*/
    ASSERT_TRUE(true);
}

TEST_F(TableDrivenAgentTest, testExistingSequences) {
    ASSERT_STREQ(agent.execute(), "name");
    ASSERT_EQ(NoOpAction::NoOp(), NoOpAction::NoOp());

}

//TODO: search for returning the address of a local variable as a pointer return value


