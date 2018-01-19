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
        //xy    = new XYLocation(3, 4);
        //xy2   = new XYLocation(3, 4);
        //xy3   = new XYLocation(9, 9);
        //xy4   = new XYLocation(9, 9);
        //xy5   = new XYLocation(5, 5);
        //xy6   = new XYLocation(5, 5);
        agent = new MockAgent();
        wall  = new Wall();
        env->addObjectToLocation(agent, XYLocation{3, 4});

        //env = XYEnvironment{10, 10};
        //env.addObjectToLocation(agent, XYLocation{3, 4});
   	}

    virtual void TearDown() 
    {
        delete env;
        //delete xy;
        //delete xy2;
        //delete xy3;
        //delete xy4;
        //delete xy5;
        //delete xy6;
		delete agent;
        delete wall;
    }

    //XYEnvironment   env;
    XYEnvironment*  env;
    //XYLocation*     xy; 
    //XYLocation*     xy2; 
    //XYLocation*     xy3; 
    //XYLocation*     xy4;
    //XYLocation*     xy5;
    //XYLocation*     xy6;
    AbstractAgent*  agent;
    Wall*           wall;
};

TEST_F(XYEnvironmentTest, testAddObject) {
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    ASSERT_EQ(env->getCurrentLocationFor(agent), XYLocation(3, 4));
}

TEST_F(XYEnvironmentTest, testAddObject2) {
    env->addObjectToLocation(wall, XYLocation(9, 9));
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    ASSERT_EQ(env->getEnvironmentObjects().size(), size_t(2));
    ASSERT_EQ(env->getObjectsAt(XYLocation(9, 9)).size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testAddObjectTwice) {
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    AbstractAgent* b = new MockAgent();
    env->addObjectToLocation(b, XYLocation(5, 5));
    ASSERT_EQ(env->getAgents().size(), size_t(2));
    ASSERT_EQ(env->getCurrentLocationFor(b), XYLocation(5, 5));
    delete b;
}

TEST_F(XYEnvironmentTest, testMoveObjectToAbsoluteLocation) {
    env->moveObjectToAbsoluteLocation(agent, XYLocation(5, 5));
    ASSERT_EQ(env->getCurrentLocationFor(agent), XYLocation(5, 5));
}

TEST_F(XYEnvironmentTest, testMoveObject)
{
    //XYLocation* loc1 = new XYLocation(5, 4);
    //XYLocation* loc2 = new XYLocation(6, 4);
    //XYLocation* loc3 = new XYLocation(6, 5);
    //XYLocation* loc4 = new XYLocation(5, 5);

    env->moveObjectToAbsoluteLocation(agent, XYLocation(5, 5));
    ASSERT_EQ(env->getCurrentLocationFor(agent), XYLocation(5, 5));

    env->moveObject(agent, XYLocation::Direction::NORTH);
    ASSERT_EQ(env->getCurrentLocationFor(agent), XYLocation(5, 4));
    //ASSERT_TRUE(true);
/*
    env->moveObject(agent, XYLocation::Direction::EAST);
    ASSERT_EQ(*env->getCurrentLocationFor(agent), *loc2);
    env->moveObject(agent, XYLocation::Direction::SOUTH);
    ASSERT_EQ(*env->getCurrentLocationFor(agent), *loc3);
    env->moveObject(agent, XYLocation::Direction::WEST);
    ASSERT_EQ(*env->getCurrentLocationFor(agent), *loc4);
*/
}



/* TODO change LocationPair to std::pair
 *      find a way to pass anonymous pointers -- either smart pointers or XYEnvirnmentState vector collects and delets
 *      stop resource leaks in XYLocation direction functions
 *      do away with compiler warnings for unused variable
 *      rewrite XYEnvironmentState::moveObjectToAbsoluteLocation with std::find_if?   
 *      
*/


