//
// Created by gordonzu on 4/1/18.
//
#include "gmock/gmock.h"
#include "agent/agent.h"

using namespace::testing;
using namespace::ag;

class TableDrivenAgentTest: public Test {
public:
    void SetUp() override {

    }

    Agent agent;
    //static const Action ACTION_1 = DynamicAction{"action1"};

};

TEST_F(TableDrivenAgentTest, testAgentTalks) {
    ASSERT_STREQ(agent.talk(), "Agent...");
}

/*
TEST_F(TableDrivenAgentTest, testExistingSequences) {
    DynamicPercept dp{"key1", "value1"};
    ASSERT_EQ(agent.execute(dp), ACTION_1)




}
*/



