// XYEnvironmentTest.cpp

#include <string>
#include <iostream>
#include "gmock/gmock.h"
#include "tests/data/TestData.h"

using namespace::testing;

class XYEnvironmentTest: public Test, public TestData {
public:
    virtual void SetUp() 
    {
        env->addObjectToLocation(agent, *loc);
   	}
};

TEST_F(XYEnvironmentTest, testAddObject) 
{
    ASSERT_EQ(env->getAgents().size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testGetCurrentLocation) 
{
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *loc2);
}

TEST_F(XYEnvironmentTest, testAddObject2) 
{
    env->addObjectToLocation(wall, *xy991);
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    ASSERT_EQ(env->getEnvironmentObjects().size(), size_t(2));
    ASSERT_EQ(env->getObjectsAt(*xy992).size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testAddObjectTwice) 
{
    ASSERT_EQ(env->getAgents().size(), size_t(1));
    env->addObjectToLocation(agent2, *xy551);
    ASSERT_EQ(env->getAgents().size(), size_t(2));
    ASSERT_EQ(*(env->getCurrentLocationFor(agent2)), *xy552);
}

TEST_F(XYEnvironmentTest, testMoveObjectToAbsoluteLocation) 
{
    env->moveObjectToAbsoluteLocation(agent, *xy551);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy552);
}

TEST_F(XYEnvironmentTest, testMoveObject)
{
    env->moveObjectToAbsoluteLocation(agent, *xy551);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent)), *xy552);
    env->moveObject(agent, XYLocation::Direction::NORTH);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy54);
    env->moveObject(agent, XYLocation::Direction::EAST);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy64);
    env->moveObject(agent, XYLocation::Direction::SOUTH);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy65);
    env->moveObject(agent, XYLocation::Direction::WEST);
    ASSERT_EQ(*(env->getCurrentLocationFor(agent).get()), *xy553);
}


/* TODO 
 *      construct data strctures as unique pointers and dereference them to pass by reference
 *      rewrite XYEnvironmentState::moveObjectToAbsoluteLocation with std::find_if?   
 *      construct the XYEnvironment vectors (sets) in moveObjectToAbsoluteLocation with unique_ptr, pass by object ref
 *      have test class inherit from test data class, store test data there
 *      check all for loops for change to STL algos
 *      explore adding "const" and constexpr to all functions that do not write data
 *
*/


