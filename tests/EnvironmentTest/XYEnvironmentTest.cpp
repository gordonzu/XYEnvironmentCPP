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

    virtual void SetUp() 
    {
        agent = std::make_shared<MockAgent>();
    }

    virtual void TearDown() 
    {
    }

    XYEnvironment                   env;
    std::shared_ptr<AbstractAgent>  agent;
};

/* TODO change LocationPair to std::pair
 *      change all new XYLocation() to smart pointers   
 *      rewrite XYEnvironmentState::moveObjectToAbsoluteLocation with std::find_if?   
 *      
*/

TEST_F(XYEnvironmentTest, testAddAgent) 
{
    env = XYEnvironment{10, 10};
    env.addObjectToLocation(agent, std::make_shared<XYLocation>(3, 4));
    ASSERT_EQ(env.getAgents().size(), size_t(1));
    env.addObjectToLocation(agent, std::make_shared<XYLocation>(8, 7));
    ASSERT_EQ(env.getAgents().size(), size_t(2));
}

TEST_F(XYEnvironmentTest, testAddAgentLocation) 
{
    env = XYEnvironment{10, 10};
    std::shared_ptr<XYLocation> myXy = std::make_shared<XYLocation>(5, 6);
    env.addObjectToLocation(agent, myXy);
    ASSERT_EQ(*env.getCurrentLocationFor(agent), *myXy);
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
























