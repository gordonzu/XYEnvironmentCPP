// XYEnvironmentTest.cpp

#include <string>
#include "gmock/gmock.h"
#include "environment/xyenv/xy_environment.h"

using namespace::testing;

class XYEnvironmentTest: public Test {
public:
    void SetUp() override {
        env = new XYEnvironment(10, 12);
        loc = new XYLocation(3, 4);
        agent = new Agent();
        env->add_to(agent, *loc);
   	}

    void TearDown() override {
        delete loc;
        delete agent;
        delete env;
    }
    
    Object* agent;
    XYLocation* loc;
    XYEnvironment* env;
};

TEST_F(XYEnvironmentTest, testMatrixConstruction) {
    ASSERT_EQ(env->get_vector_size(), size_t(120));
    ASSERT_EQ(env->get_set_size(*loc), size_t(1));
}

TEST_F(XYEnvironmentTest, testObjectIsUnique) {
    auto xy = new XYLocation(5,6);
    env->add_to(agent, *xy);
    ASSERT_EQ(env->get_set_size(*xy), size_t(1));
    ASSERT_EQ(env->get_set_size(*loc), size_t(0));
    delete xy;
}

TEST_F(XYEnvironmentTest, testBaseClassContainers) {
    ASSERT_EQ(env->get_agents().size(), size_t(1));
    ASSERT_EQ(env->get_objs().size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testGetCurrentLocation) {
    auto xyloc = new XYLocation(3, 4);
    ASSERT_EQ(*(env->get_location(agent)), *xyloc);
    delete xyloc;
}

TEST_F(XYEnvironmentTest, testAddObject2) {
    Object* wall = new Wall();
    auto xyloc = new XYLocation(9, 9);

    env->add_to(wall, *xyloc);
    ASSERT_EQ(env->get_agents().size(), size_t(1));
    ASSERT_EQ(env->get_objs().size(), size_t(2));
    delete xyloc;

    xyloc = new XYLocation(9, 9);
    ASSERT_EQ(env->get_set_size(*xyloc), size_t(1));
    delete xyloc;
    delete wall;
}

TEST_F(XYEnvironmentTest, testAddObjectTwice) {
    ASSERT_EQ(env->get_agents().size(), size_t(1));

    auto agent1 = new Agent();
    auto xyloc = new XYLocation(5, 5);
    auto xy    = new XYLocation(5, 5);
  
    env->add_to(agent1, *xyloc);
    ASSERT_EQ(env->get_agents().size(), size_t(2));
    ASSERT_EQ(*(env->get_location(agent1)), *xy);

    delete agent1;
    delete xyloc;
    delete xy;
}

TEST_F(XYEnvironmentTest, testMoveObjectToAbsoluteLocation) {
    auto a = new Agent();
    auto xyloc = new XYLocation(5, 5);
    auto xy    = new XYLocation(5, 5);
 
    env->add_to(a, *xyloc);
    ASSERT_EQ(*(env->get_location(a)), *xy);

    delete a;
    delete xyloc;
    delete xy;
}

TEST_F(XYEnvironmentTest, testMoveObject) {
    auto xyloc = new XYLocation(5, 5);
    auto xy    = new XYLocation(5, 5);

    env->add_to(agent, *xyloc);
    ASSERT_EQ(*(env->get_location(agent)), *xy);

    auto loc54 = new XYLocation(5, 4);
    auto loc64    = new XYLocation(6, 4);
    auto loc65    = new XYLocation(6, 5);

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

TEST_F(XYEnvironmentTest, testIsBlocked) {
    auto loc = new XYLocation(5, 5);
    ASSERT_EQ(env->get_set_size(*loc), size_t(0));

    delete loc;
}




















































































/* TODO 
 *      explore adding "const" and constexpr to all functions that do not write data
 *      each environment has its own vector of location and agent vector pairs, each location
 *      has it's own vector of agents. 
 *
*/


