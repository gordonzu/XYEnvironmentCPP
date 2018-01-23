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
        loc   = std::make_unique<XYLocation>(3, 4);  
        env->addObjectToLocation(agent, *loc);
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
    std::unique_ptr<XYLocation> loc;
};

TEST_F(XYEnvironmentTest, testAddObject) 
{
    ASSERT_EQ(env->getAgents().size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testGetCurrentLocation) 
{
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), XYLocation(3, 4));
}

TEST_F(XYEnvironmentTest, testAddObject2) 
{
    auto loc1 = std::make_unique<XYLocation>(9, 9);
    auto loc2 = std::make_unique<XYLocation>(9, 9);

    env->addObjectToLocation(wall, *loc1);
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    ASSERT_EQ(env->getEnvironmentObjects().size(), size_t(2));
    ASSERT_EQ(env->getObjectsAt(*loc2).size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testAddObjectTwice) 
{
    ASSERT_EQ(env->getAgents().size(), size_t(1));

    auto agt = std::make_unique<AbstractAgent>(MockAgent());
    auto loc = std::make_unique<XYLocation>(5, 5);
    auto xy2 = std::make_unique<XYLocation>(5, 5);

    env->addObjectToLocation(agt.get(), *loc);
    ASSERT_EQ(env->getAgents().size(), size_t(2));
    ASSERT_EQ(*(env->getCurrentLocationFor(agt.get()).get()), *xy2);
}

TEST_F(XYEnvironmentTest, testMoveObjectToAbsoluteLocation) 
{
    auto loc = std::make_unique<XYLocation>(5, 5);
    auto xy2 = std::make_unique<XYLocation>(5, 5);
    env->moveObjectToAbsoluteLocation(agent, *loc);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy2);
}

TEST_F(XYEnvironmentTest, testMoveObject)
{
    auto xy1 = std::make_unique<XYLocation>(5, 5);
    auto xy2 = std::make_unique<XYLocation>(5, 5);
    auto xy3 = std::make_unique<XYLocation>(5, 5);
    auto xy4 = std::make_unique<XYLocation>(5, 4);
    auto xy5 = std::make_unique<XYLocation>(6, 4);
    auto xy6 = std::make_unique<XYLocation>(6, 5);

    env->moveObjectToAbsoluteLocation(agent, *xy1);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy2);
    env->moveObject(agent, XYLocation::Direction::NORTH);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy4);
    env->moveObject(agent, XYLocation::Direction::EAST);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy5);
    env->moveObject(agent, XYLocation::Direction::SOUTH);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy6);
    env->moveObject(agent, XYLocation::Direction::WEST);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy3);
}



/* TODO change LocationPair to std::pair
 *      find a way to pass anonymous pointers -- either smart pointers or XYEnvirnmentState vector collects and delets
 *      stop resource leaks in XYLocation direction functions
 *      do away with compiler warnings for unused variable
 *      rewrite XYEnvironmentState::moveObjectToAbsoluteLocation with std::find_if?   
 *      
*/


