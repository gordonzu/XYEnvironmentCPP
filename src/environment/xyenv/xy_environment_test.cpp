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
        wall = new Wall();
        env->add_to(agent, *loc);
   	}

    void TearDown() override {
        delete loc;
        delete agent;
        delete wall;
        delete env;
    }
    
    Agent* agent;
    Wall* wall;
    XYLocation* loc;
    XYEnvironment* env;
};

TEST_F(XYEnvironmentTest, testMatrixConstruction) {
    ASSERT_EQ(env->get_vector_size(), size_t(120));
    ASSERT_EQ(env->get_set_size(*loc), size_t(1));

/*
    std::cout << "Set size: " << env->get_set_size(*loc) << std::endl;
    auto w = new Wall();
    env->add_to(w, *loc);
    std::cout << "Set size: " << env->get_set_size(*loc) << std::endl;

    auto yy = new XYLocation(0, 0);
    auto ww = new Wall();
    env->add_to(ww, *yy);
    std::cout << "Set size in test: " << env->get_set_size(*yy) << std::endl;

    auto y = new XYLocation(21, 25);
    auto w1 = new Wall();
    env->add_to(w1, *y);
   Vector::iterator vecit = env->get_vector().begin();
    if ((vecit = env->has_xy(*y)) != env->get_vector().end()) {
        std::cout << "Found the location." << std::endl;
    } else {
        std::cout << "NOT FOUND!" << std::endl;
    }

    std::cout << "Set size: " << env->get_set_size(*y) << std::endl;

    ASSERT_EQ(2, 2);
*/
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
    auto xyloc = new XYLocation(9, 9);

    env->add_to(wall, *xyloc);
    ASSERT_EQ(env->get_agents().size(), size_t(1));
    ASSERT_EQ(env->get_objs().size(), size_t(2));
    delete xyloc;

    xyloc = new XYLocation(9, 9);
    ASSERT_EQ(env->get_set_size(*xyloc), size_t(1));
    delete xyloc;
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
    ASSERT_EQ(env->is_blocked(*loc), false);

    env->add_to(wall, *loc);
    ASSERT_EQ(env->get_set_size(*loc), size_t(1));
    ASSERT_EQ(env->is_blocked(*loc), true);

    delete loc;
}

TEST_F(XYEnvironmentTest, testMoveWithBlockingWalls) {
    auto loc = new XYLocation(5, 5);
    env->add_to(agent, *loc);

    auto northloc = new XYLocation(5, 6);
    auto southloc = new XYLocation(5, 4);
    auto westloc = new XYLocation(4, 5);
    auto endloc = new XYLocation(6, 5);

    auto northwall = new Wall();
    env->add_to(northwall, *northloc);
    ASSERT_EQ(env->is_blocked(*northloc), true);

    auto southwall = new Wall();
    auto westwall = new Wall();
    env->add_to(southwall, *southloc);
    env->add_to(westwall, *westloc);
    ASSERT_EQ(env->get_objs().size(), size_t(4));

    env->move_object(agent, XYLocation::Direction::NORTH); // should not move
    env->move_object(agent, XYLocation::Direction::SOUTH); // should not move
    env->move_object(agent, XYLocation::Direction::WEST);  // should not move
    env->move_object(agent, XYLocation::Direction::EAST);  // SHOULD move
    ASSERT_EQ(*(env->get_location(agent)), *endloc);

    delete loc;
    delete northloc;
    delete southloc;
    delete westloc;
    delete endloc;
    delete northwall;
    delete southwall;
    delete westwall;
}

TEST_F(XYEnvironmentTest, testGetSet) {
    auto loc = new XYLocation(5, 7);
    env->add_to(agent, *loc);
    ASSERT_EQ(env->get_set_size(*loc), size_t(1));
    auto b = new Agent();
    env->add_to(b, *loc);
    ASSERT_EQ(env->get_set_size(*loc), size_t(2));

    delete loc;
    delete b;
}

TEST_F(XYEnvironmentTest, testGetObjectsNear) {
    auto loc = new XYLocation(5, 5);
    auto loc2 = new XYLocation(7, 4);
    auto loc3 = new XYLocation(5, 7);
    auto loc4 = new XYLocation(3, 10);
    auto loc5 = new XYLocation(3, 11);

    env->add_to(agent, *loc);
    auto b = new Agent();
    auto c = new Agent();
    auto w = new Wall();

    env->add_to(b, *loc2);
    env->add_to(c, *loc3);
    env->add_to(w, *loc4);

    std::set<Object*> agentset = env->get_objects_near(agent, 3);
    ASSERT_EQ(agentset.size(), size_t(2));

    std::set<Object*> bset = env->get_objects_near(b, 3);
    ASSERT_EQ(bset.size(), size_t(1));

    env->move_object(b, XYLocation::Direction::SOUTH);

    bset = env->get_objects_near(b, 3);
    ASSERT_EQ(bset.size(), size_t(2));

    env->add_to(c, *loc5);
    std::set<Object*> cset = env->get_objects_near(c, 4);
    ASSERT_EQ(cset.size(), size_t(1));

    delete loc;
    delete loc2;
    delete loc3;
    delete loc4;
    delete loc5;
    delete b;
    delete c;
    delete w;
}

TEST_F(XYEnvironmentTest, testOutOfRangeXYLocations) {
    auto loc = new XYLocation(5, 5);
    auto loc2 = new XYLocation(25, 30);
    auto loc3 = new XYLocation(0, 0);

    auto a = new Agent();
    env->add_to(a, *loc);
    ASSERT_EQ(env->get_set_size(*loc), size_t(1));

    auto a1 = new Agent();
    env->add_to(a1, *loc2);
    ASSERT_EQ(env->get_set_size(*loc2), size_t(0));

    auto a2 = new Agent();
    env->add_to(a2, *loc3);
    ASSERT_EQ(env->get_set_size(*loc3), size_t(0));

    delete loc;
    delete loc2;
    delete loc3;
    delete a;
    delete a1;
    delete a2;
}





































































/* TODO 
 *      explore adding "const" and constexpr to all functions that do not write data
 *      each environment has its own vector of location and agent vector pairs, each location
 *      has it's own vector of agents. 
 *
*/


