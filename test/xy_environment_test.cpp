// XYEnvironmentTest.cpp

#include <string>
#include <vector>
#include "gmock/gmock.h"
#include "environment/xyenv/xy_environment.h"

using namespace::testing;

class XYEnvironmentTest: public Test {
public:
    void SetUp() override {
        agent = std::make_unique<Agent>();
        wall = std::make_unique<Wall>();
        env.add_to(agent.get(), loc);
   	}

    std::unique_ptr<Agent> agent;
    std::unique_ptr<Wall> wall;
    XYLocation loc{3, 4};
    XYEnvironment env{10, 12};
};

TEST_F(XYEnvironmentTest, testMatrixConstruction) {
    ASSERT_EQ(env.get_vector_size(), size_t(120));
    ASSERT_EQ(env.get_set_size(loc), size_t(1));
    env.add_to(wall.get(), loc);
    ASSERT_EQ(env.get_set_size(loc), size_t(2));
}


TEST_F(XYEnvironmentTest, testObjectIsUnique) {
    auto xy = XYLocation{5, 6};
    env.add_to(agent.get(), xy);
    ASSERT_EQ(env.get_set_size(xy), size_t(1));
    ASSERT_EQ(env.get_set_size(loc), size_t(0));
}

TEST_F(XYEnvironmentTest, testBaseClassContainers) {
    auto a = std::make_unique<Agent>();
    auto w = std::make_unique<Wall>();
    env.add_to(a.get(), loc);
    env.add_to(w.get(), loc);
    ASSERT_EQ(env.get_agents().size(), size_t(2));
    ASSERT_EQ(env.get_objs().size(), size_t(3));
}

TEST_F(XYEnvironmentTest, testGetCurrentLocation) {
    auto xy = XYLocation{3, 4};
    ASSERT_EQ(*(env.get_location(agent.get())), xy);
}

TEST_F(XYEnvironmentTest, testAddObject2) {
    auto xyloc = XYLocation{9, 9};
    env.add_to(wall.get(), xyloc);
    ASSERT_EQ(env.get_agents().size(), size_t(1));
    ASSERT_EQ(env.get_objs().size(), size_t(2));

    auto xy = XYLocation{9, 9};
    ASSERT_EQ(env.get_set_size(xy), size_t(1));
}

TEST_F(XYEnvironmentTest, testAddObjectTwice) {
    ASSERT_EQ(env.get_agents().size(), size_t(1));

    auto agent1 = std::make_unique<Agent>();
    auto xyloc = XYLocation{5, 5};
    auto xy = XYLocation{5, 5};

    env.add_to(agent1.get(), xyloc);
    ASSERT_EQ(env.get_agents().size(), size_t(2));
    ASSERT_EQ(*(env.get_location(agent1.get())), xy);
}

TEST_F(XYEnvironmentTest, testMoveObjectToAbsoluteLocation) {
    auto a = std::make_unique<Agent>();
    auto xyloc = XYLocation{5, 5};
    auto xy = XYLocation{5, 5};

    env.add_to(a.get(), xyloc);
    ASSERT_EQ(*(env.get_location(a.get())), xy);
}

TEST_F(XYEnvironmentTest, testMoveObject) {
    auto xyloc = XYLocation{5, 5};
    auto xy = XYLocation{5, 5};

    env.add_to(agent.get(), xyloc);
    ASSERT_EQ(*(env.get_location(agent.get())), xy);

    auto loc54 = XYLocation{5, 4};
    auto loc64 = XYLocation{6, 4};
    auto loc65 = XYLocation{6, 5};

    env.move_object(agent.get(), XYLocation::Direction::NORTH);
    ASSERT_EQ(*(env.get_location(agent.get())), loc54);
    env.move_object(agent.get(), XYLocation::Direction::EAST);
    ASSERT_EQ(*(env.get_location(agent.get())), loc64);
    env.move_object(agent.get(), XYLocation::Direction::SOUTH);
    ASSERT_EQ(*(env.get_location(agent.get())), loc65);
    env.move_object(agent.get(), XYLocation::Direction::WEST);
    ASSERT_EQ(*(env.get_location(agent.get())), xy);
}

TEST_F(XYEnvironmentTest, testIsBlocked) {
    auto loc = XYLocation{5, 5};
    ASSERT_EQ(env.get_set_size(loc), size_t(0));
    ASSERT_EQ(env.is_blocked(loc), false);

    env.add_to(wall.get(), loc);
    ASSERT_EQ(env.get_set_size(loc), size_t(1));
    ASSERT_EQ(env.is_blocked(loc), true);
}

TEST_F(XYEnvironmentTest, testMoveWithBlockingWalls) {
    auto loc = XYLocation{5, 5};
    env.add_to(agent.get(), loc);

    auto northloc = XYLocation{5, 6};
    auto southloc = XYLocation{5, 4};
    auto westloc = XYLocation{4, 5};
    auto endloc = XYLocation{6, 5};

    auto northwall = std::make_unique<Wall>();
    env.add_to(northwall.get(), northloc);
    ASSERT_EQ(env.is_blocked(northloc), true);

    auto southwall = std::make_unique<Wall>();
    auto westwall = std::make_unique<Wall>();
    env.add_to(southwall.get(), southloc);
    env.add_to(westwall.get(), westloc);
    ASSERT_EQ(env.get_objs().size(), size_t(4));

    env.move_object(agent.get(), XYLocation::Direction::NORTH); // should not move
    env.move_object(agent.get(), XYLocation::Direction::SOUTH); // should not move
    env.move_object(agent.get(), XYLocation::Direction::WEST);  // should not move
    env.move_object(agent.get(), XYLocation::Direction::EAST);  // SHOULD move
    ASSERT_EQ(*(env.get_location(agent.get())), endloc);
}

TEST_F(XYEnvironmentTest, testGetSet) {
    auto loc = XYLocation{5, 7};
    env.add_to(agent.get(), loc);
    ASSERT_EQ(env.get_set_size(loc), size_t(1));
    auto b = std::make_unique<Agent>();
    env.add_to(b.get(), loc);
    ASSERT_EQ(env.get_set_size(loc), size_t(2));
}

TEST_F(XYEnvironmentTest, testGetObjectsNear) {
    auto loc = XYLocation{5, 5};
    auto loc2 = XYLocation{7, 4};
    auto loc3 = XYLocation{5, 7};
    auto loc4 = XYLocation{3, 10};
    auto loc5 = XYLocation{3, 11};

    env.add_to(agent.get(), loc);
    auto b = std::make_unique<Agent>();
    auto c = std::make_unique<Agent>();
    auto w = std::make_unique<Agent>();

    env.add_to(b.get(), loc2);
    env.add_to(c.get(), loc3);
    env.add_to(w.get(), loc4);

    std::set<EnvironmentObject*> agentset = env.get_objects_near(agent.get(), 3);
    ASSERT_EQ(agentset.size(), size_t(2));

    std::set<EnvironmentObject*> bset = env.get_objects_near(b.get(), 3);
    ASSERT_EQ(bset.size(), size_t(1));

    env.move_object(b.get(), XYLocation::Direction::SOUTH);

    bset = env.get_objects_near(b.get(), 3);
    ASSERT_EQ(bset.size(), size_t(2));

    env.add_to(c.get(), loc5);
    std::set<EnvironmentObject*> cset = env.get_objects_near(c.get(), 4);
    ASSERT_EQ(cset.size(), size_t(1));
}

TEST_F(XYEnvironmentTest, testOutOfRangeXYLocations) {
    auto loc = XYLocation{11, 13};
    auto loc2 = XYLocation{25, 30};
    auto loc3 = XYLocation{0, 0};

    auto a = std::make_unique<Agent>();
    env.add_to(a.get(), loc);
    ASSERT_EQ(env.get_set_size(loc), size_t(1));

    auto a1 = std::make_unique<Agent>();
    env.add_to(a1.get(), loc2);
    ASSERT_EQ(env.get_set_size(loc2), size_t(1));

    auto a2 = std::make_unique<Agent>();
    env.add_to(a2.get(), loc3);
    ASSERT_EQ(env.get_set_size(loc3), size_t(1));
}

TEST_F(XYEnvironmentTest, testMakePerimeter) {
    env.make_perimeter();
    ASSERT_TRUE(env.is_blocked(XYLocation{0, 0}));
    ASSERT_TRUE(env.is_blocked(XYLocation{0, 6}));
    ASSERT_TRUE(env.is_blocked(XYLocation{0, 11}));
    ASSERT_TRUE(env.is_blocked(XYLocation{6, 0}));
    ASSERT_TRUE(env.is_blocked(XYLocation{9, 0}));
    ASSERT_TRUE(env.is_blocked(XYLocation{9, 6}));
    ASSERT_TRUE(env.is_blocked(XYLocation{9, 11}));
    ASSERT_TRUE(env.is_blocked(XYLocation{6, 11}));
}




