//
// Created by gordonzu on 4/19/18.
//

#include <agent/percept.h>
#include <memory>
#include "gmock/gmock.h"

using namespace::testing;

class DynamicPerceptTest: public Test
{
public:
    void SetUp() override
    {
    }

    std::unique_ptr<DynamicPercept> percept;
};

TEST_F(DynamicPerceptTest, testString)
{
    auto p  = std::make_unique<DynamicPercept>("key1", "value1");
    auto str = "DynamicPercept[key1=value1]";
    ASSERT_STREQ(p->get_string().c_str(), str);

    auto x = std::make_unique<DynamicPercept>("key1", "value1", "key2", "value2");
    auto str2 = "DynamicPercept[key1=value1, key2=value2]";
    ASSERT_STREQ(x->get_string().c_str(), str2);
}

TEST_F(DynamicPerceptTest, testEquals)
{
    auto p1  = std::make_unique<DynamicPercept>();
    auto p2  = std::make_unique<DynamicPercept>();
    ASSERT_TRUE(*p1 == *p2);

    auto p3  = std::make_unique<DynamicPercept>("key1", "value1");
    ASSERT_FALSE(*p1 == *p3);

    auto p4  = std::make_unique<DynamicPercept>("key1", "value1");
    ASSERT_TRUE(*p3 == *p4);
}


