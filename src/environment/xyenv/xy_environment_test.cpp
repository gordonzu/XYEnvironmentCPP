// XYEnvironmentTest.cpp

#include <string>
#include <iostream>
#include "gmock/gmock.h"
#include "test_data.h"

using namespace::testing;

class XYEnvironmentTest: public Test, public TestData {
public:
    virtual void SetUp() {
        env->add_to(agent, *loc);
   	}
};

TEST_F(XYEnvironmentTest, testAddObject) {
    ASSERT_EQ(env->get_agents().size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testGetCurrentLocation) {
    //ASSERT_EQ(*(env->get_location(agent).get()), *loc2);
    ASSERT_EQ(*(env->get_location(agent)), *loc2);
}

TEST_F(XYEnvironmentTest, testAddObject2) {
    env->add_to(wall, *xy991);
    ASSERT_EQ(env->get_agents().size(), size_t(1));
    ASSERT_EQ(env->get_envs().size(), size_t(2));
    ASSERT_EQ(env->get_at(*xy992).size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testAddObjectTwice) {
    ASSERT_EQ(env->get_agents().size(), size_t(1));
    env->add_to(agent2, *xy551);
    ASSERT_EQ(env->get_agents().size(), size_t(2));
    //ASSERT_EQ(*(env->get_location(agent2).get()), *xy552);
    ASSERT_EQ(*(env->get_location(agent2)), *xy552);
}

TEST_F(XYEnvironmentTest, testMoveObjectToAbsoluteLocation) {
    env->add_to(agent3, *xy551);
    //ASSERT_EQ(*(env->get_location(agent3).get()), *xy552);
    ASSERT_EQ(*(env->get_location(agent3)), *xy552);
}

TEST_F(XYEnvironmentTest, testMoveObject) {
    env->add_to(agent4, *xy551);
    //ASSERT_EQ(*(env->get_location(agent4).get()), *xy552);
    ASSERT_EQ(*(env->get_location(agent4)), *xy552);

    env->move_object(agent4, XYLocation::Direction::NORTH);
    //ASSERT_EQ(*(env->get_location(agent4).get()), *xy54);
    ASSERT_EQ(*(env->get_location(agent4)), *xy54);
    env->move_object(agent4, XYLocation::Direction::EAST);
    //ASSERT_EQ(*(env->get_location(agent4).get()), *xy64);
    ASSERT_EQ(*(env->get_location(agent4)), *xy64);
    env->move_object(agent4, XYLocation::Direction::SOUTH);
    //ASSERT_EQ(*(env->get_location(agent4).get()), *xy65);
    ASSERT_EQ(*(env->get_location(agent4)), *xy65);
    env->move_object(agent4, XYLocation::Direction::WEST);
    //ASSERT_EQ(*(env->get_location(agent4).get()), *xy553);
    ASSERT_EQ(*(env->get_location(agent4)), *xy553);
}

/* TODO 
 *      construct data strctures as unique pointers and dereference them to pass by reference
 *      rewrite XYEnvironmentState::moveObjectToAbsoluteLocation with std::find_if?   
 *      construct the XYEnvironment vectors (sets) in moveObjectToAbsoluteLocation with unique_ptr, pass by object ref
 *      have test class inherit from test data class, store test data there
 *      check all for loops for change to STL algos
 *      explore adding "const" and constexpr to all functions that do not write data
 *
 *
 *      each environment has its own vector of location and agent vector pairs, each location 
 *      has it's own vector of agents. 
 *
 *      create two data structure classes - one vector holding a std::pair of a location
 *      and an agent vector, and one agent vector used in the first vector
*/


