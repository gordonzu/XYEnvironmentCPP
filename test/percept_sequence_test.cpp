//
// Created by gordonzu on 4/19/18.

#include <agent/percept.h>
#include <memory>
#include "gmock/gmock.h"

using namespace::testing;

class PerceptSequenceTest: public Test
{
public:

    void TearDown() override
    {
        if (delete_vec) {
            auto it = PerceptSequenceTest::v.begin();
            while (it != PerceptSequenceTest::v.end()) {
                delete *it;
                ++it;
            }
        }
    }

    static std::string& print_vec(std::string& str)
    {
        for (unsigned i = 0; i <= v.size(); ++i) {
            str.append(v[i]->get_string());
            if (i + 1  == v.size()) break;
            str.append(", ");
        }
        return str;
    }

    static std::vector<Percept*> v;
    bool delete_vec;
};

std::vector<Percept*> PerceptSequenceTest::v = []
{
    std::vector<Percept*> vec;
    return vec;
}();

TEST_F(PerceptSequenceTest, testString)
{
    std::string str4;
    v.emplace_back(new DynamicPercept("key1", "value1"));
    auto str1 = "DynamicPercept[key1=value1]";
    auto str2 = v[0]->get_string();
    ASSERT_STREQ(str2.c_str(), str1);

    v.emplace_back(new DynamicPercept("key1", "value1", "key2", "value2"));
    auto str3 = "DynamicPercept[key1=value1], DynamicPercept[key1=value1, key2=value2]";
    ASSERT_STREQ(PerceptSequenceTest::print_vec(str4).c_str(), str3);
    delete_vec = true;
}
/*
TEST_F(PerceptSequenceTest, testEquals)
{
    //std::vector<std::unique_ptr<Percept>> v1;
    //std::vector<std::unique_ptr<Percept>> v2;
    std::vector<Percept*> v1;
    std::vector<Percept*> v2;
    ASSERT_TRUE(v2 == v1);

    //v1.emplace_back(std::make_unique<DynamicPercept>("key1", "value1"));
    v1.emplace_back(new DynamicPercept("key1", "value1"));
    ASSERT_FALSE(v2 == v1);

    //v2.emplace_back(std::make_unique<DynamicPercept>("key1", "value1"));
    v2.emplace_back(new DynamicPercept("key1", "value1"));
    ASSERT_TRUE(v2 == v1);

    delete_vec = false;
}
*/




