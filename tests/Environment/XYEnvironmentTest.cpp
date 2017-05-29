// XYEnvironmentTest.cpp

#include <string>
#include <iostream>
#include "gmock/gmock.h"
#include "xyenv/include/XYEnvironmentState.h"

using namespace::testing;

class XYEnvironmentTest: public Test {
public:
    XYEnvironmentTest() {}
    virtual ~XYEnvironmentTest() {}

    XYEnvironmentState*     env;
    EnvironmentObject*      eo;
    XYLocation*             loc;

protected: 
    virtual void SetUp() {
        env = new XYEnvironmentState(3, 3);
        loc = new XYLocation(1, 2);
        eo = new EnvironmentObject();            
        env->addObjectToLocation(eo, loc);
    }

    virtual void TearDown() {
        delete env;
        delete loc;
        env = nullptr; 
        loc = nullptr; 
    }
};

TEST_F(XYEnvironmentTest, testAddObject) {
    ASSERT_EQ(env->getVector()->size(), size_t(10));
}

TEST_F(XYEnvironmentTest, testGetCurrentLocation) {
    ASSERT_EQ(*(env->getCurrentLocationFor(eo)), *(new XYLocation(1, 2)));
}



