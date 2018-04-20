//
// Created by gordonzu on 4/19/18.
//

#include <agent/percept.h>
#include <memory>
#include "gmock/gmock.h"

using namespace::testing;

class PerceptTest: public Test
{
public:
    void SetUp() override
    {
    }

    std::unique_ptr<DynamicPercept> percept;
};

TEST_F(PerceptTest, testString)
{
    ASSERT_TRUE(true);
}


