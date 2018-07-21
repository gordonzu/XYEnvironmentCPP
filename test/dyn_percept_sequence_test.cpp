//
// Created by gordonzu on 4/30/18.
//

#include <agent/percept.h>
#include <memory>
#include <agent/dyn_percept.h>
#include <util/string.h>
#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include "util/algorithm/utils.h"

using namespace::testing;

class DynPerceptSequenceTest: public Test
{
};

TEST_F(DynPerceptSequenceTest, testString)
{
    std::vector<Percept> vec;
    std::string str4;

    vec.emplace_back(Percept{"key1", "value1"});
    auto str1 = "Percept[key1=value1]";
    auto str2 = vec[0].get_string();
    ASSERT_STREQ(str2.c_str(), str1);

    vec.emplace_back(Percept{"key1", "value1", "key2", "value2"});
    auto str3 = "Percept[key1=value1], Percept[key1=value1, key2=value2]";
    ASSERT_STREQ(util::print_vec(vec, str4).c_str(), str3);
}

TEST_F(DynPerceptSequenceTest, testEquals)
{
    bool b;
    std::vector<Percept> v1;
    std::vector<Percept> v2;

    b = util::vec_compare(v1, v2);
    ASSERT_TRUE(b);

    v1.emplace_back(Percept{"key1", "value1"});
    b = util::vec_compare(v1, v2);
    ASSERT_FALSE(b);

    v2.emplace_back(Percept{"key1", "value1"});
    b = util::vec_compare(v1, v2);
    ASSERT_TRUE(b);

    v2.clear();
    v2.emplace_back(Percept{"key2", "value1"});
    b = util::vec_compare(v1, v2);
    ASSERT_FALSE(b);
}

