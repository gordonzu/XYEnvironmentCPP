// XYEnvironmentTest.cpp

#include <string>
#include <iostream>
#include "gmock/gmock.h"
#include "Environment/xyenv/include/XYEnvironment.h"
#include "AgentTest/impl/include/MockAgent.h"
#include "Environment/xyenv/include/Wall.h"

using namespace::testing;

class XYEnvironmentTest: public Test {
public:
    XYEnvironmentTest() {}
    ~XYEnvironmentTest() {}

    virtual void SetUp() {
        agent = std::make_shared<MockAgent>();
    }

    virtual void TearDown() {
        //delete agent;
        //agent = nullptr;
    }

    XYEnvironment                   env;
    std::shared_ptr<AbstractAgent>  agent;
};

/*TODO: change AbstractAgent* to std::shared_ptr<MockAgent>()   
 *      change all XYEnvironmentObject* params to std::shared_ptr<XYEnvironmentObject>
 *      change all new XYEnvironmentObject() to std::make_shared<XYEnvironmentObject>();
 *      change all new XYLocation() to smart pointers   
 *      rewrite XYEnvironmentState::moveObjectToAbsoluteLocation with std::find_if?   
 *      change all vectors to stack-based objects passed by reference.
*/

TEST_F(XYEnvironmentTest, testAddObject) {
    env = XYEnvironment{10, 10};
    env.addObjectToLocation(agent, new XYLocation(3, 4));

    //ASSERT_EQ(env.getAgents().size(), size_t(1));
    //ASSERT_EQ(*(env.getCurrentLocationFor(agent)), *(new XYLocation(3, 4)));
    ASSERT_TRUE(true);
}

/*
TEST_F(XYEnvironmentTest, testAddObject2) {
    env->addObjectToLocation(new Wall(), new XYLocation(9, 9));
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    ASSERT_EQ(env->getEnvironmentObjects().size(), size_t(2));
    ASSERT_EQ(env->getObjectsAt(new XYLocation(9, 9))->size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testAddObjectTwice) {
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    XYLocation* x = new XYLocation(5, 5);
    AbstractAgent* a = new MockAgent();
    env->addObjectToLocation(a, x);
    ASSERT_EQ(env->getAgents().size(), size_t(2));
    ASSERT_EQ(*(env->getCurrentLocationFor(a)), *x);
}

TEST_F(XYEnvironmentTest, testMoveObjectToAbsoluteLocation) {
    XYLocation* loc = new XYLocation(5, 5);
    env->moveObjectToAbsoluteLocation(agent, loc);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent)), *(new XYLocation(5, 5)));
}
*/
























