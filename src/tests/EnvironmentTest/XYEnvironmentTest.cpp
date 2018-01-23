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
    virtual void SetUp() 
    {
		env   = new XYEnvironment(10, 10);
        agent = new MockAgent();
        wall  = new Wall();
        env->addObjectToLocation(agent, XYLocation(3, 4));
   	}

    virtual void TearDown() 
    {
        delete env;
		delete agent;
        delete wall;
    }

    XYEnvironment*  env;
    AbstractAgent*  agent;
    Wall*           wall;
};

TEST_F(XYEnvironmentTest, testAddObject) {
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), XYLocation(3, 4));
}

TEST_F(XYEnvironmentTest, testAddObject2) {
    env->addObjectToLocation(wall, XYLocation(9, 9));
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    ASSERT_EQ(env->getEnvironmentObjects().size(), size_t(2));
    ASSERT_EQ(env->getObjectsAt(XYLocation(9, 9)).size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testAddObjectTwice) {
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    auto b = std::make_unique<AbstractAgent>(MockAgent());
    env->addObjectToLocation(b.get(), XYLocation(5, 5));
    ASSERT_EQ(env->getAgents().size(), size_t(2));
    ASSERT_EQ(*(env->getCurrentLocationFor(b.get()).get()), XYLocation(5, 5));
}

TEST_F(XYEnvironmentTest, testMoveObjectToAbsoluteLocation) {
    env->moveObjectToAbsoluteLocation(agent, XYLocation(5, 5));
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), XYLocation(5, 5));
}

TEST_F(XYEnvironmentTest, testMoveObject)
{
    env->moveObjectToAbsoluteLocation(agent, XYLocation(5, 5));
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), XYLocation(5, 5));
    env->moveObject(agent, XYLocation::Direction::NORTH);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), XYLocation(5, 4));
    env->moveObject(agent, XYLocation::Direction::EAST);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), XYLocation(6, 4));
    env->moveObject(agent, XYLocation::Direction::SOUTH);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), XYLocation(6, 5));
    env->moveObject(agent, XYLocation::Direction::WEST);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), XYLocation(5, 5));
}



/* TODO change LocationPair to std::pair
 *      find a way to pass anonymous pointers -- either smart pointers or XYEnvirnmentState vector collects and delets
 *      stop resource leaks in XYLocation direction functions
 *      do away with compiler warnings for unused variable
 *      rewrite XYEnvironmentState::moveObjectToAbsoluteLocation with std::find_if?   
 *      
*/


