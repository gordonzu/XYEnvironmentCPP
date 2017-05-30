// XYEnvironmentTest.cpp

#include <string>
#include <iostream>
#include "gmock/gmock.h"
#include "xyenv/include/XYEnvironmentState.h"

using namespace::testing;

class XYEnvironmentTest: public Test {
public:
    XYEnvironmentTest() {}
    virtual ~XYEnvironmentTest() {}

    XYEnvironment*  env;
    AbstractAgent*  agent;

protected: 
    virtual void SetUp() {
        env     = new XYEnvironment(3, 3);
        agent   = new MockAgent();            
        env->addObjectToLocation(agent, new XYLocation(1, 2));
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
}

TEST_F(XYEnvironmentTest, testGetCurrentLocation) {
    ASSERT_EQ(*(env->getCurrentLocationFor(agent)), *(new XYLocation(1, 2)));
}



