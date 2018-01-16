// XYEnvironmentTest.cpp

#include <string>
#include <iostream>
#include "gmock/gmock.h"
#include "Environment/xyenv/include/XYEnvironment.h"
#include "tests/AgentTest/impl/include/MockAgent.h"
#include "Environment/xyenv/include/Wall.h"

using namespace::testing;

class XYEnvironmentTest: public Test {
public:
    XYEnvironmentTest() {
		env   = new XYEnvironment(10, 10);
        agent = new MockAgent();
	}

    ~XYEnvironmentTest() {
        delete env;
		delete agent;
        env = nullptr;
		env = nullptr;
	}

    virtual void SetUp() 
    {
   	}

    virtual void TearDown() 
    {
    }

    XYEnvironment*  env;
    AbstractAgent*  agent;
};

/* TODO change LocationPair to std::pair
 *      rewrite XYEnvironmentState::moveObjectToAbsoluteLocation with std::find_if?   
 *      
*/
TEST_F(XYEnvironmentTest, testAddAgent) 
{
	auto xy_one = new XYLocation(3,4); 
    env->addObjectToLocation(agent, xy_one);
    ASSERT_EQ(env->getAgents().size(), size_t(1));

	auto xy_two = new XYLocation(8, 7);
    env->addObjectToLocation(agent, xy_two);
    ASSERT_EQ(env->getAgents().size(), size_t(2));

	delete xy_one;
	delete xy_two;
	xy_one = nullptr;
	xy_two = nullptr;
}

TEST_F(XYEnvironmentTest, testAddAgentLocation) 
{
    XYLocation* xy = new XYLocation(5, 6);
    env->addObjectToLocation(agent, xy);
    ASSERT_EQ(*env->getCurrentLocationFor(agent), *xy);

	delete xy;
	xy = nullptr;
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
























