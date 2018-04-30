//
// Created by gordonzu on 4/29/18.
//

#include <gtest/gtest.h>
#include <agent/dyn_percept.h>
#include <util/string.h>
#include <util/boolean.h>


using namespace::testing;

class DynPerceptTest: public Test
{
};

TEST_F(DynPerceptTest, testString)
{
    auto str = "DynPercept[key1=value1]";
    auto percept1 = DynPercept<String, String>{"key1", "value1"};
    ASSERT_STREQ(percept1.get_string().c_str(), str);

    auto str2 = "DynPercept[key1=value1, key2=value2]";
    auto percept2 = DynPercept<String, String>{"key1", "value1", "key2", "value2"};
    ASSERT_STREQ(percept2.get_string().c_str(), str2);

    auto str3 = "DynPercept[key1=true, key2=false]";
    auto percept3 = DynPercept<String, Boolean>{"key1", true, "key2", false};
    ASSERT_STREQ(percept3.get_string().c_str(), str3);
}


TEST_F(DynPerceptTest, testEquals)
{
    auto p3  = DynPercept<String, String>{};
    auto p4  = DynPercept<String, String>{};

    ASSERT_TRUE(p3 == p4);

    auto p5  = DynPercept<String, String>{"key1", "value1"};
    ASSERT_FALSE(p3 == p5);

    auto p6  = DynPercept<String, String>{"key1", "value1"};
    ASSERT_TRUE(p6 == p5);
}
