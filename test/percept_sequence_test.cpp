// Created by gordonzu on 4/19/18.

#include <agent/percept.h>
#include <memory>
#include "gmock/gmock.h"
#include "util/algorithm/compares.h"

using namespace::testing;

class PerceptSequenceTest: public Test
{
};

TEST_F(PerceptSequenceTest, testString)
{
    std::vector<std::unique_ptr<Percept>> vec;
    std::string str4;

    vec.emplace_back(std::make_unique<DynamicPercept>("key1", "value1"));
    auto str1 = "DynamicPercept[key1=value1]";
    auto str2 = vec[0]->get_string();
    ASSERT_STREQ(str2.c_str(), str1);

    vec.emplace_back(std::make_unique<DynamicPercept>("key1", "value1", "key2", "value2"));
    auto str3 = "DynamicPercept[key1=value1], DynamicPercept[key1=value1, key2=value2]";
    ASSERT_STREQ(util::print_vec(std::move(vec), str4).c_str(), str3);
}

TEST_F(PerceptSequenceTest, testEquals)
{
    bool b;
    std::vector<std::unique_ptr<Percept>> v1;
    std::vector<std::unique_ptr<Percept>> v2;

    b = util::vec_compare(std::move(v1), std::move(v2));
    ASSERT_TRUE(b);

    v1.emplace_back(std::make_unique<DynamicPercept>("key1", "value1"));
    b = util::vec_compare(std::move(v1), std::move(v2));
    ASSERT_FALSE(b);

    v1.emplace_back(std::make_unique<DynamicPercept>("key1", "value1"));
    v2.emplace_back(std::make_unique<DynamicPercept>("key1", "value1"));
    b = util::vec_compare(std::move(v1), std::move(v2));
    ASSERT_TRUE(b);

    v1.emplace_back(std::make_unique<DynamicPercept>("key1", "value1"));
    v2.emplace_back(std::make_unique<DynamicPercept>("key2", "value1"));

    b = util::vec_compare(std::move(v1), std::move(v2));
    ASSERT_FALSE(b);
}

























