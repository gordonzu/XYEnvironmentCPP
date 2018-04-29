//
// Created by gordonzu on 4/19/18.
//

#include <agent/percept.h>
#include <memory>
#include "gmock/gmock.h"

using namespace::testing;

class DynamicPerceptTest: public Test
{
};

TEST_F(DynamicPerceptTest, testString)
{
    auto str = "Percept[key1=value1]";
    auto percept1 = Percept{"key1", "value1"};
    ASSERT_STREQ(percept1.get_string().c_str(), str);

    auto str2 = "Percept[key1=value1, key2=value2]";
    auto percept2 = Percept{"key1", "value1", "key2", "value2"};
    ASSERT_STREQ(percept2.get_string().c_str(), str2);

}

TEST_F(DynamicPerceptTest, testEquals)
{
    auto p3  = Percept{};
    auto p4  = Percept{};

    ASSERT_TRUE(p3 == p4);

    auto p5  = Percept{"key1", "value1"};
    ASSERT_FALSE(p3 == p5);

    auto p6  = Percept{"key1", "value1"};
    ASSERT_TRUE(p6 == p5);
}


