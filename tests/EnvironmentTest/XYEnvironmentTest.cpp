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
    virtual ~XYEnvironmentTest() {}

    XYEnvironment*  env;
    AbstractAgent*  agent;

protected: 
    virtual void SetUp() {
        env     = new XYEnvironment(10, 10);
        agent   = new MockAgent();           
        env->addObjectToLocation(agent, new XYLocation(3, 4));
    }

    virtual void TearDown() {
        delete env;
        delete agent;
        env = nullptr; 
        agent = nullptr;
    }
};

TEST_F(XYEnvironmentTest, testAddObject) {
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    ASSERT_EQ(*(env->getCurrentLocationFor(agent)), *(new XYLocation(3, 4)));
}

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

TEST_F(XYEnvironmentTest, moveObjectToAbsoluteLocation) {
    ASSERT_EQ();
}

/*TEST_F(XYEnvironmentTest, ) {
    ASSERT_EQ();
}

TEST_F(XYEnvironmentTest, ) {
    ASSERT_EQ();
}
*/
























