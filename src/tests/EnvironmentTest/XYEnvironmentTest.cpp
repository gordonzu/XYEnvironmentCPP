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
        xy    = new XYLocation(3, 4);
        xy2   = new XYLocation(3, 4);
        xy3   = new XYLocation(9, 9);
        xy4   = new XYLocation(9, 9);
        xy5   = new XYLocation(5, 5);
        xy6   = new XYLocation(5, 5);
        agent = new MockAgent();
        wall  = new Wall();
        env->addObjectToLocation(agent, xy);
   	}

    virtual void TearDown() 
    {
        delete env;
        delete xy;
        delete xy2;
        delete xy3;
        delete xy4;
        delete xy5;
        delete xy6;
		delete agent;
        delete wall;
    }

    XYEnvironment*  env;
    XYLocation*     xy; 
    XYLocation*     xy2; 
    XYLocation*     xy3; 
    XYLocation*     xy4;
    XYLocation*     xy5;
    XYLocation*     xy6;
    AbstractAgent*  agent;
    Wall*           wall;
};

TEST_F(XYEnvironmentTest, testAddObject) 
{
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    ASSERT_EQ(*env->getCurrentLocationFor(agent), *xy2);
}

TEST_F(XYEnvironmentTest, testAddObject2) 
{
    env->addObjectToLocation(wall, xy3);
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    ASSERT_EQ(env->getEnvironmentObjects().size(), size_t(2));
    ASSERT_EQ(env->getObjectsAt(xy4).size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testAddObjectTwice) 
{
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    AbstractAgent* b = new MockAgent();
    env->addObjectToLocation(b, xy5);
    ASSERT_EQ(env->getAgents().size(), size_t(2));
    ASSERT_EQ(*env->getCurrentLocationFor(b), *xy6);

    delete b;
}

TEST_F(XYEnvironmentTest, testMoveObjectToAbsoluteLocation)
{
    env->moveObjectToAbsoluteLocation(agent, xy5);
    ASSERT_EQ(*env->getCurrentLocationFor(agent), *xy6);
}

TEST_F(XYEnvironmentTest, testMoveObject)
{
    env->moveObjectToAbsoluteLocation(agent, xy5);
    ASSERT_EQ(*env->getCurrentLocationFor(agent), *xy6);
    
}






/* TODO change LocationPair to std::pair
 *      rewrite XYEnvironmentState::moveObjectToAbsoluteLocation with std::find_if?   
 *      
*/


