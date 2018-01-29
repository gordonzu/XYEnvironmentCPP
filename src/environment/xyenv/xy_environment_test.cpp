// XYEnvironmentTest.cpp

#include <string>
#include <iostream>
#include "gmock/gmock.h"
#include "environment/xyenv/xy_environment.h"

using namespace::testing;

class XYEnvironmentTest: public Test {
public:
    virtual void SetUp() {
        env = new XYEnvironment(10, 12);
        loc = new XYLocation(3, 4);
        agent = new Agent();
        env->add_to(agent, *loc);
   	}

    virtual void TearDown() {
        delete loc;
        delete agent;
        delete env;
    }
    
    Object* agent;
    XYLocation* loc;
    XYEnvironment* env;
};

TEST_F(XYEnvironmentTest, testAddObject) {
    ASSERT_EQ(env->get_agents().size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testGetCurrentLocation) {
    XYLocation* xyloc = new XYLocation(3, 4);
    ASSERT_EQ(*(env->get_location(agent)), *xyloc);
    delete xyloc;
}

TEST_F(XYEnvironmentTest, testAddObject2) {
    Object* wall = new Wall();
    XYLocation* xyloc = new XYLocation(9, 9);

    env->add_to(wall, *xyloc);
    ASSERT_EQ(env->get_agents().size(), size_t(1));
    ASSERT_EQ(env->get_envs().size(), size_t(2));
    delete xyloc;

    xyloc = new XYLocation(9, 9);
    ASSERT_EQ(env->get_at(*xyloc).size(), size_t(1));
    delete xyloc;
    delete wall;
}

TEST_F(XYEnvironmentTest, testAddObjectTwice) {
    ASSERT_EQ(env->get_agents().size(), size_t(1));

    XYLocation* xyloc = new XYLocation(5, 5);
    XYLocation* xy    = new XYLocation(5, 5);
  
    env->add_to(agent, *xyloc);
    ASSERT_EQ(env->get_agents().size(), size_t(2));
    ASSERT_EQ(*(env->get_location(agent)), *xy);

    delete xyloc;
    delete xy;
}

TEST_F(XYEnvironmentTest, testMoveObjectToAbsoluteLocation) {
    XYLocation* xyloc = new XYLocation(5, 5);
    XYLocation* xy    = new XYLocation(5, 5);
 
    env->add_to(agent, *xyloc);
    ASSERT_EQ(*(env->get_location(agent)), *xy);

    delete xyloc;
    delete xy;
}

TEST_F(XYEnvironmentTest, testMoveObject) {
    XYLocation* xyloc = new XYLocation(5, 5);
    XYLocation* xy    = new XYLocation(5, 5);

    env->add_to(agent, *xyloc);
    ASSERT_EQ(*(env->get_location(agent)), *xy);

    XYLocation* loc54 = new XYLocation(5, 4);
    XYLocation* loc64    = new XYLocation(6, 4);
    XYLocation* loc65    = new XYLocation(6, 5);

    env->move_object(agent, XYLocation::Direction::NORTH);
    ASSERT_EQ(*(env->get_location(agent)), *loc54);
    env->move_object(agent, XYLocation::Direction::EAST);
    ASSERT_EQ(*(env->get_location(agent)), *loc64);
    env->move_object(agent, XYLocation::Direction::SOUTH);
    ASSERT_EQ(*(env->get_location(agent)), *loc65);
    env->move_object(agent, XYLocation::Direction::WEST);
    ASSERT_EQ(*(env->get_location(agent)), *xy);

    delete xyloc;
    delete xy;
    delete loc54;
    delete loc64;
    delete loc65;
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


